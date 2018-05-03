// const and constexpr for c++11

const int x = 10;
constexpr int y = 10 * 5;

// func `square()` must be a constexpr func:

constexpr int square(int x) { return x * x; }

constexpr int v = square(5);


