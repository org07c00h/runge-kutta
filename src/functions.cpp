#include "functions.hpp"
#include <cmath>

double x1(std::array<double, 2> x, std::array<double, 2> y)
{
        return y[0] + x[1];
}

double x2(std::array<double, 2> x, std::array<double, 2> y)
{
    return y[1] - x[0];
}

double y1(std::array<double, 2> x, std::array<double, 2> y)
{
    return -3 * x[0] / pow(squarNorm(x), 3.0/2.0) + 2 * x[0] + y[1];
}

double y2(std::array<double, 2> x, std::array<double, 2> y)
{
    return -3 * x[1] / pow(squarNorm(x), 3.0/2.0) - x[1] - y[0];
}

double squarNorm(std::array<double, 2> x) {
    return x[0] * x[0] + x[1] * x[1];
}

std::array<double, 4> f(const std::array<double, 2> x, const std::array<double, 2> y)
{
  std::array<double, 4> data;
  data[0] = x1(x, y);
  data[1] = x2(x, y);

  data[2] = y1(x, y);
  data[3] = y2(x, y);

  return data;
}

void progressBar(float progress, unsigned int current)
{
  std::cout << "\r" << progress << "% completed: ";
  // std::cout << std::string(X, '|');
  std::cout.flush();


}
