#include "forward_kinematics.hpp"
#include "inverse_kinematics.hpp"
#include "jacobian.hpp"
#include "joint.hpp"
#include "mat2.hpp"
#include "robot_arm.hpp"
#include <Eigen/Dense>
#include <Eigen/src/Core/Matrix.h>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  RobotArm arm1;
  Mat2 m1;
  IKCalculation ik;
  Jacobian j1;
  double angle_init = 0.1; // cant be 0.0 because it hit kinematic singlualrity
  Vec2 xtarget = {1, 0.75};
  arm1.addSegment(1.0, angle_init);
  arm1.addSegment(1.5, angle_init);

  m1 = j1.CalulateInverseJacobian(1.0, 1.1, angle_init, -angle_init);
  std::vector<Joint> finalPos =
      ik.InverseCalulation(xtarget, m1, arm1, angle_init);
  for (size_t i = 0; i < finalPos.size(); i++) {
    std::cout << finalPos[i].angle << "\n";
  }
  return 0;
}