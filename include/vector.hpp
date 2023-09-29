#pragma once

#include <cmath>
#include <iostream>

namespace smath {
template <class T>
struct Vector2 {
    inline Vector2() : x(0), y(0) {}
    inline Vector2(const T& val) : x(val), y(val) {}
    inline Vector2(const T& x, const T& y) : x(x), y(y) {}

    inline static Vector2 Zero() { return Vector2(); }
    inline static Vector2 One() { return Vector2(1, 1); }

    inline float LengthSquared() const { return x * x + y * y; }
    inline float Length() const { return sqrt(LengthSquared()); }
    inline float Distance(const Vector2& vector) const {
        float xSeperation = x - vector.x;
        float ySeperation = y - vector.y;
        return sqrt(xSeperation * xSeperation + ySeperation * ySeperation);
    }
    inline Vector2 Normalized() const { return *this * (1.f / (Length())); }
    inline bool IsEmpty() const { return x <= 0 || y <= 0; }

    // Operator overloads
    inline Vector2 operator+(const Vector2& vector) const {
        return Vector2(x + vector.x, y + vector.y);
    }
    inline Vector2 operator-(const Vector2& vector) const {
        return Vector2(x - vector.x, y - vector.y);
    }
    inline Vector2 operator*(const Vector2& vector) const {
        return Vector2(x * vector.x, y * vector.y);
    }
    inline Vector2 operator/(const Vector2& vector) const {
        return Vector2(x / vector.x, y / vector.y);
    }
    inline Vector2& operator+=(const Vector2& vector) {
        x += vector.x;
        y += vector.y;
        return *this;
    }
    inline Vector2& operator-=(const Vector2& vector) {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }
    inline Vector2& operator*=(const Vector2& vector) {
        x *= vector.x;
        y *= vector.y;
        return *this;
    }
    inline Vector2& operator/=(const Vector2& vector) {
        x /= vector.x;
        y /= vector.y;
        return *this;
    }
    inline Vector2 operator-() const { return Vector2(-x, -y); }
    inline Vector2 operator-(const T& num) const {
        return Vector2(x - num, y - num);
    }
    inline Vector2 operator+(const T& num) const {
        return Vector2(x + num, y + num);
    }
    inline Vector2 operator*(const T& num) const {
        return Vector2(x * num, y * num);
    }
    inline Vector2 operator/(const T& num) const {
        return Vector2(x / num, y / num);
    }
    inline Vector2& operator+=(const T& num) {
        x += num;
        y += num;
        return *this;
    }
    inline Vector2& operator-=(const T& num) {
        x -= num;
        y -= num;
        return *this;
    }
    inline Vector2& operator*=(const T& num) {
        x *= num;
        y *= num;
        return *this;
    }
    inline Vector2& operator/=(const T& num) {
        x /= num;
        y /= num;
        return *this;
    }
    inline bool operator==(const Vector2& vector) const {
        return x == vector.x && y == vector.y;
    }

    inline bool operator!=(const Vector2& vector) const {
        return x != vector.x || y != vector.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
        os << "(x: " << vector.x << ", y: " << vector.y << ")";
        return os;
    }

    T x, y;
};

using Vector2I = Vector2<int>;
using Vector2F = Vector2<float>;
using Vector2U = Vector2<unsigned>;

using SizeI = Vector2I;
using SizeF = Vector2F;
using SizeU = Vector2U;
}  // namespace smath
