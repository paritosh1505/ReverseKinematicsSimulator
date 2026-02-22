#pragma once
#include "vec2.hpp"
#include <vector>
Vec2 forwardKinematics(const std::vector<double> &linklength,
                       const std::vector<double> &jointangle);