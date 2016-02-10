#include "RK4.hpp"

RK4::RK4(const std::array<double, 2> x0, const std::array<double, 2> y0)
{
  x = x0;
  y = y0;

  h = 1e-4;

  mOutX.open("/tmp/x.dat");
  mOutY.open("/tmp/y.dat");

}

void RK4::solve()
{
  for (int i = 0; i < 1e4; i++)
  {
    //progressBar(double(i)/1e4, i);
    this->nextStep();
  }
  mOutX.close();
  mOutY.close();
}

void RK4::nextStep()
{
  std::array<double, 2> tempX = x;
  std::array<double, 2> tempY = y;
  k[0] = f(tempX, tempY);
  //std::cout << "k0 calculated" << std::endl;

  for (unsigned int i = 0; i < tempX.size(); i++)
  {
    tempX[i] = x[i] + h / 2.0 * k[0][i];
    tempY[i] = y[i] + h / 2.0 * k[0][i + 2];
  }
  k[1] = f(tempX, tempY);
  //std::cout << "k1 calculated" << std::endl;

  for (unsigned int i = 0; i < tempX.size(); i++)
  {
    tempX[i] = x[i] + h / 2.0 * k[1][i];
    tempY[i] = y[i] + h / 2.0 * k[1][i + 2];
  }
  k[2] = f(tempX, tempY);
  //std::cout << "k2 calculated" << std::endl;

  for (unsigned int i = 0; i < tempX.size(); i++)
  {
    tempX[i] = x[i] + h * k[2][i];
    tempY[i] = y[i] + h * k[2][i + 2];
  }
  k[3] = f(tempX, tempY);
  //std::cout << "k3 calculated" << std::endl;

  for (unsigned int j = 0; j < tempX.size(); j++)
  {
    x[j] += h / 6.0 * (k[0][j] + 2.0 * k[1][j] + 2.0 * k[2][j] + k[3][j]);
    y[j] += h / 6.0 * (k[0][j + 2] + 2.0 * k[1][j + 2] + 2.0 * k[2][j + 2] + k[3][j + 2]);
  }


  mOutX << x[0] << "\t" << x[1] << "\r\n";
  mOutY << y[0] << "\t" << y[1] << "\r\n";

}
