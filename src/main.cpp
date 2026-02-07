#include "fk.hpp"
#include <iostream>
constexpr double pi = 3.141592653589793;
int main(){
     std::vector<double> jointlen = {1,1};
     std::vector<double> angleval = {pi/2,-pi/2};
    Vec2 effectorpos= forwardKinematics(jointlen, angleval);
    std::cout<<"final value("<<effectorpos.x<<","<<effectorpos.y<<")"<<"\n";
    return 0;
}