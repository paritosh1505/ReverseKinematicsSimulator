#include "jacobian.hpp"

#include "mat2.hpp"
#include <cmath>

Mat2 Jacobian::CalulateInverseJacobian(double L1, double L2, double theta1,
                                       double theta2) {

  Mat2 j1;
  j1.a11 = -L1 * std::sin(theta1) - L2 * std::sin(theta1 + theta2);
  j1.a12 = -L2 * std::sin(theta1 + theta2);
  j1.a21 = L1 * std::cos(theta1) + L2 * std::cos(theta1 + theta2);
  j1.a22 = L2 * std::cos(theta1 + theta2);
  return j1;
}
