#pragma once
#include <array>
#include <iostream>

double x1(const std::array<double, 2> x, const std::array<double, 2> y);
double x2(const std::array<double, 2> x, const std::array<double, 2> y);
double y1(const std::array<double, 2> x, const std::array<double, 2> y);
double y2(const std::array<double, 2> x, const std::array<double, 2> y);

std::array<double, 4> f(const std::array<double, 2> x, const std::array<double, 2> y);

double squarNorm(std::array<double, 2> x);

void progressBar(float progress, unsigned int current);
