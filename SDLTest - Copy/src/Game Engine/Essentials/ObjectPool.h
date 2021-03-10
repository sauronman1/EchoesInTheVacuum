#include <type_traits>
#include <iostream>
#include <memory>
#include <chrono>

template<class T, int sizeOfPool>
class ObjectPool final
{
public:

    ObjectPool()
    {
        size = sizeOfPool;
        for (auto i = 1; i < size; ++i)
            mPool[i - 1].mNext = &mPool[i];

        mNextFree = &mPool[0];
    }

    ObjectPool(const ObjectPool&) = delete;

    ObjectPool(ObjectPool&& other) noexcept
        : mPool{ std::move(other.mPool) }
        , mNextFree{ other.mNextFree }
    {
        other.mNextFree = nullptr;
    }

    ~ObjectPool() = default;

    [[nodiscard]] T* allocate()
    {
        if (mNextFree == nullptr)
            throw std::bad_alloc{};

        const auto item = mNextFree;
        mNextFree = item->mNext;

        return reinterpret_cast<T*>(&item->mStorage);
    }

    void deallocate(T* p) noexcept
    {
        const auto item = reinterpret_cast<Item*>(p);

        item->mNext = mNextFree;
        mNextFree = item;
    }

    template<class ...Args>
    [[nodiscard]] T* construct(Args&& ...args)
    {
        return new (allocate()) T(std::forward<Args>(args)...);
    }

    void destroy(T* p) noexcept
    {
        if (p == nullptr)
            return;

        p->~value_type();
        deallocate(p);
    }

    ObjectPool& operator =(const ObjectPool&) = delete;

    ObjectPool& operator =(ObjectPool&& other) noexcept
    {
        if (this == &other)
            return *this;

        mPool = std::move(other.mPool);
        mNextFree = other.mNextFree;
        other.mNextFree = nullptr;

        return *this;
    }

private:
    std::size_t size;

    union Item
    {
        std::aligned_storage_t<sizeof(T), alignof(T)> mStorage;
        Item* mNext;
    };

    std::unique_ptr<Item[]> mPool = std::make_unique<Item[]>(size);
    Item* mNextFree = nullptr;
};
