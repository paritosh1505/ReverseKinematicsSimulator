#pragma once
#include "joint.hpp"
#include "mat2.hpp"
#include "robot_arm.hpp"
#include "vec2.hpp"
#include <vector>
class IKCalculation {
private:
  std::vector<Joint> final_angle;

public:
  std::vector<Joint> InverseCalulation(Vec2 target, Mat2 m1, RobotArm arm,
                                       double angle_init);
};