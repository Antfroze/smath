#include <iostream>
#include <smath.hpp>

using namespace smath;

int main() {
    Vector2F vec(40, 40);
    Vector2F vec2(50, 50);
    RectF rect(Vector2F::Zero(), Vector2F(100, 100));
    RectI rect2 = rect;

    std::cout << vec.Distance(vec2) << std::endl;
    std::cout << vec << std::endl;
    std::cout << rect.Center() << std::endl;

    return 0;
}