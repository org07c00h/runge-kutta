#include "RK4.hpp"

RK4::RK4(const std::array<double, 2> x0, const std::array<double, 2> y0)
{
  x = x0;
  y = y0;

  initialValues[0] = x[0];
  initialValues[1] = x[1];
  initialValues[2] = y[0];
  initialValues[3] = y[1];

  h = 1e-7;

  // mOutX.open("/tmp/dump/x_" + std::to_string(x[0]) + "_" + std::to_string(x[1]) +
  // std::to_string(y[0]) + "_" + std::to_string(y[1]) + ".dat");
  // mOutY.open("/tmp/dump/y_" + std::to_string(x[0]) + "_" + std::to_string(x[1]) +
  // std::to_string(y[0]) + "_" + std::to_string(y[1]) + ".dat");
}

void RK4::solve()
{
  int counter = 0;
  std::ofstream goodData;
  goodData.open("/tmp/foobar100.txt", std::ios_base::app);
  while(counter < 1e8 &&
    sqrt((x[0] - 1) * (x[0] - 1) + x[1] * x[1]) > 1e-4 &&
    !isHuge(x, y))
  {
    this->nextStep();
    counter++;
  }
  // std::cout << "x:\t" << initialValues[0] << " " << initialValues[1] << std::endl;
  // std::cout << "y:\t" << initialValues[2] << " " << initialValues[3] << std::endl;

  if (counter == 1e5)
  {
    std::cout << "counter is huge" << std::endl;
  }
  else if (!isHuge(x, y))
  {
    std::cout << "OMG I FOUND IT!!!111111" << std::endl;
    goodData << initialValues[0] << "\t" << initialValues[1] << "\t"
      << initialValues[2] << "\t" << initialValues[3] << std::endl;
  }
  // mOutX.close();
  // mOutY.close();
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
  //
  // mOutX << x[0] << "\t" << x[1] << "\r\n";
  // mOutY << y[0] << "\t" << y[1] << "\r\n";

}
