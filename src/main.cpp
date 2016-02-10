#include <iostream>
#include <array>
#include <string>

#include "functions.hpp"
#include "RK4.hpp"

int main(int argc, const char *argv[])
{
    // for (int i = 1; i < argc; i++)
    // {
    //   std::cout << std::stod(std::string(argv[1])) + 2.14 << std::endl;
    // }
    std::array<double, 2> x = {
      std::stod(std::string(argv[1])),
      std::stod(std::string(argv[2]))
    };
    std::array<double, 2> y = {std::stod(std::string(argv[3])), std::stod(std::string(argv[4]))};
    //
    RK4 rk4(x, y);
    rk4.solve();

}
