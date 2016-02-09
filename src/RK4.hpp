#pragma once

#include <array>
#include <iostream>
#include <fstream>

#include "functions.hpp"

template <class T, unsigned I, unsigned J>
using Matrix = std::array<std::array<T, J>, I>;

class RK4 {
public:
  RK4(std::array<double, 2> x0, std::array<double, 2> y0);
  void solve();
private:
  Matrix<double, 4, 4> k;
  double h;
  std::array<double, 2> x;
  std::array<double, 2> y;

  std::ofstream mOutX;
  std::ofstream mOutY;

  void nextStep();

};
