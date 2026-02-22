#pragma once

#include "mat2.hpp"
#include <vector>
class Jacobian {
private:
  std::vector<Mat2> matrix;

public:
  Mat2 CalulateInverseJacobian(double L1, double L2, double theta1,
                               double theta2);

  // Mat2 CalcualteCurrentPos(Mat2 m1, double theta1, double theta2);
};