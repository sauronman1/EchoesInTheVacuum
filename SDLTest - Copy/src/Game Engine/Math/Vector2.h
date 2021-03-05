#pragma once
#include <ostream>

template <typename T>
struct Vector2 {

	T x, y;

	Vector2() : x(0), y(0) {}
	Vector2(T v) : x(v), y(v) {}
	Vector2(T _x, T _y) : x(_x), y(_y) {}


	inline const Vector2<T> operator+(const Vector2<T>& v2) const {
		return Vector2<T>(x + v2.x, y + v2.y);
	 }


	inline friend std::ostream& operator<<(std::ostream& stream, const Vector2<T>& v) {
		stream << "(" << v.x << "," << v.y << ")";
		return stream;
	}

	inline static Vector2<T> toZero() {
		return Vector2<T>(0, 0);
	}

	inline Vector2<T> operator*(const T scalar) const {
		return Vector2<T>(x * scalar, y * scalar);
	}

	inline static Vector2<T> one() {
		return Vector2<T>(1, 1);
	}


	inline Vector2<T> operator-(const Vector2<T>& v2) const {
		return Vector2<T>(x - v2.x, y - v2.y);
	}


	inline friend Vector2<T>& operator-=(Vector2<T>& v1, const Vector2<T>& v2) {
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}


	inline friend Vector2<T>& operator+=(Vector2<T>& v1, const Vector2<T>& v2) {
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}


};


