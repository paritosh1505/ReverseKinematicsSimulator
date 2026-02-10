#pragma once
#include "joint.hpp"
#include "link.hpp"
#include "vec2.hpp"
#include <vector>
class RobotArm {
private:
  std::vector<Joint> joints;
  std::vector<Link> links;

public:
  void addSegment(double length, double angle);
  std::vector<Vec2> forwardKinematics() const;
};