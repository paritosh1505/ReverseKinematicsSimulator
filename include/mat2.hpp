#pragma once

struct Mat2 {
  double a11, a12;
  double a21, a22;
};

Mat2 computeJacobian(double L1, double L2, double theta1, double theta2);