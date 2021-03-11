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

    }
    ~ObjectPool() {
        delete[] allObj;
    }
 
    T getNextObject() {

    }
private:
    T allObj[sizeOfPool];


};