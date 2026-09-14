#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<float>::epsilon() << std::endl;;
    std::cout << std::numeric_limits<double>::epsilon() << std::endl;

    std::cout << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << std::numeric_limits<double>::digits10 << std::endl;
}