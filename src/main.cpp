#include "jacobian.hpp"
#include "mat2.hpp"
#include "robot_arm.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
  Mat2 m1;
  Jacobian j1;
  m1 = j1.CalulateJacob(1.0, 1.1, M_PI / 2, -M_PI / 2);
  return 0;
}