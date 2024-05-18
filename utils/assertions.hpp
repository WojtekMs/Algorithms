#include <cassert>
#include <iostream>

namespace utils {
    // TODO: use correct Concept :) 
template <typename T>
void assertEq(const T& actual, const T& expected, bool print = false) {
    if (print) {
        std::cerr << "Actual size: " << actual.size() << ", expected size: " << expected.size() << "\n";
        std::cerr << "Actual: '" << actual << "', expected: '" << expected << "'\n";
    }
    assert(actual == expected);
}

}