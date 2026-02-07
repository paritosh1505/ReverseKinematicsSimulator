#pragma once
#include <vector>

struct Vec2{
    double x;
    double y;
};

Vec2 forwardKinematics(
    const std::vector<double>& linklength,
    const std::vector<double>& jointangle
);