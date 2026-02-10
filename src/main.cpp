#include "robot_arm.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
  RobotArm arm;
  std::vector<Vec2> position;
  arm.addSegment(1.0, 0);
  arm.addSegment(1.0, 0);
  arm.addSegment(1.0, 0);
  position = arm.forwardKinematics();
  position = arm.forwardKinematics();
  for (size_t i = 0; i < position.size(); i++) {
    std::cout << "(" << position[i].x << "," << position[i].y << ")" << "\n";
  }
  return 0;
}