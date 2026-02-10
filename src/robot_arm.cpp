#include "robot_arm.hpp"
#include "link.hpp"

#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <vector>

void RobotArm::addSegment(double length, double angle) {
  links.push_back(Link{length});
  joints.push_back(Joint{angle});
}
std::vector<Vec2> RobotArm::forwardKinematics() const {
  std::vector<Vec2> currPosVal;
  double theta = 0.0;
  double x_val = 0.0, y_val = 0.0;

  currPosVal.push_back({x_val, y_val});
  if (joints.size() != links.size()) {
    throw std::logic_error("Mismatch between joint size and link size");
  }
  for (size_t i = 0; i < links.size(); i++) {

    theta = theta + joints[i].angle;
    x_val = x_val + links[i].length * std::cos(theta);

    y_val = y_val + links[i].length * std::sin(theta);
    currPosVal.push_back({x_val, y_val});
  }
  return currPosVal;
}
