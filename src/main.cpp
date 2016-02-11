#include <iostream>
#include <array>
#include <string>

#include "functions.hpp"
#include "RK4.hpp"

int main(int argc, const char *argv[])
{
    double h = 1e-6;
    for (int i = 1; i <= 100; i++)
    {
      for (int j = 1; j <= 100; j++)
      {
        for (int k = 1; k <= 100; k++)
        {
          for (int l = 1; l <= 100; l++)
          {
            std::array<double, 2> x = {4*1e-3 + h * k, 4.1*1e-3 + h*l};
            std::array<double, 2> y = {h * j / 19, h*i / 21};
            RK4* rk4 = new RK4(x, y);
            rk4->solve();
          }
        }
      }
    }


}
