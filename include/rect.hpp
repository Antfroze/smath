#pragma once

#include <vector.hpp>

namespace smath {
template <class T>
struct Rect {
    inline Rect(const Vector2<T>& origin, const Vector2<T>& size)
        : origin(origin), size(size) {}

    inline const T GetWidth() { return size.x; }
    inline const T GetHeight() { return size.y; }
    inline const T GetArea() { return GetWidth() * GetHeight(); }
    inline const Vector2<T> Center() { return origin + size / 2; }

    inline bool Contains(const Vector2<T>& position) {
        return (position.x >= origin.x && position.x <= (origin.x + size.x) &&
                position.y >= origin.y && position.y <= (origin.y + size.y));
    }

    inline bool Contains(const Rect<T>& other) {
        return (other.origin.x >= origin.x && other.origin.y >= origin.y &&
                (other.origin.x + other.size.x) <= (origin.x + size.x) &&
                (other.origin.y + other.size.y) <= (origin.y + size.y));
    }

    Vector2<T> origin, size;
};

using RectI = Rect<int>;
using RectF = Rect<float>;
}  // namespace smath
