#include "fk.hpp"
#include <cmath>
#include <stdexcept>

Vec2 forwardKinematics(const std::vector<double>& linklength,const std::vector<double>& jointangle ){
    if (linklength.size()==jointangle.size()){
        throw std::runtime_error("joint angle size and link length size mismatch");
    }
    double theta = 0;
    double x_cord=0;
    double y_cord=0;
    Vec2 posval={0,0};
    for (size_t i=0;i<linklength.size();i++){
        theta=theta+jointangle[i];
        posval.x=posval.x+linklength[i]*std::cos(theta);
        posval.y = posval.y+linklength[i]*std::sin(theta);
    }
    return posval;
}
