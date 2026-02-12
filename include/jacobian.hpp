#pragma once

#include "mat2.hpp"
#include <vector>
class Jacobian {
private:
  std::vector<Mat2> matrix;

public:
  Mat2 CalulateJacob(double L1, double L2, double theta1, double theta2);
};