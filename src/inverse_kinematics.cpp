
#include "inverse_kinematics.hpp"
#include "joint.hpp"
#include "robot_arm.hpp"
#include <cmath>
#include <stdexcept>
#include <vector>
double NormCalculation(Vec2 errorVal) {
  return std::sqrt((errorVal.x * errorVal.x) + (errorVal.y * errorVal.y));
}
std::vector<Joint> IKCalculation::InverseCalulation(Vec2 target, Mat2 m1,
                                                    RobotArm arm,
                                                    double angle_init) {

  std::vector<Vec2> currentfkvec = arm.forwardKinematics();
  std::vector<Joint> theta(2);
  std::vector<Joint> newtheta(2);

  theta[0].angle = angle_init;
  theta[1].angle = angle_init;
  Vec2 actual = currentfkvec.back();
  double alpha = 0.05;
  double det = m1.a11 * m1.a22 - m1.a12 * m1.a21;
  double angle_calc1 = 0.0;
  double angle_calc2 = 0.0;

  if (det == 0)
    throw std::runtime_error(
        "Robot arm is either fully streched up or fully compressed");
  std::vector<Joint> joint_angle(2);
  Vec2 errorVal;
  double normVal = 0.0;
  while (normVal < 1e-5) {
    arm.addSegment(1, theta[0].angle);
    arm.addSegment(1.5, theta[1].angle);
    currentfkvec = arm.forwardKinematics();
    actual = currentfkvec.back();
    errorVal.x = target.x - actual.x;
    errorVal.y = target.y - actual.y;
    angle_calc1 = (m1.a11 * errorVal.x + m1.a12 * errorVal.y) / det;
    angle_calc2 = (m1.a21 * errorVal.x + m1.a22 * errorVal.y) / det;
    joint_angle[0].angle = angle_calc1;
    joint_angle[1].angle = angle_calc2;
    newtheta[0].angle = theta[0].angle + alpha * angle_calc1;
    newtheta[1].angle = theta[1].angle + alpha * angle_calc2;
    theta[0].angle = newtheta[0].angle;
    theta[1].angle = newtheta[1].angle;
    normVal = NormCalculation(errorVal);
  }
  return joint_angle;
  // Vec2 errorX = actual.x - target.x;
  // Vec2 errorY = actual.y - target.y;
}
