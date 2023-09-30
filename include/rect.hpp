#pragma once

#include <vector.hpp>

namespace smath {
template <class T>
struct Rectangle {
    inline Rectangle(const Vector2<T>& origin, const Vector2<T>& size)
        : origin(origin), size(size) {}

    inline const T GetWidth() { return size.x; }
    inline const T GetHeight() { return size.y; }
    inline const T GetArea() { return GetWidth() * GetHeight(); }
    inline const Vector2<T> Center() { return origin + size / 2; }

    inline bool Contains(const Vector2<T>& position) {
        return (position.x >= origin.x && position.x <= (origin.x + size.x) &&
                position.y >= origin.y && position.y <= (origin.y + size.y));
    }

    inline bool Contains(const Rectangle<T>& other) {
        return (other.origin.x >= origin.x && other.origin.y >= origin.y &&
                (other.origin.x + other.size.x) <= (origin.x + size.x) &&
                (other.origin.y + other.size.y) <= (origin.y + size.y));
    }

    inline Rectangle RoundOut() const {
        return Rectangle(Vector2<T>(std::floor(origin.x), std::floor(origin.y)),
                         Vector2<T>(std::ceil(size.x), std::ceil(size.y)));
    }

    inline Rectangle operator*(const T& num) const {
        return Rectangle(origin * num, size * num);
    }
    inline Rectangle& operator*=(const T& num) {
        origin *= num;
        size *= num;
        return *this;
    }

    Vector2<T> origin, size;
};

using RectI = Rectangle<int>;
using RectF = Rectangle<float>;
}  // namespace smath
