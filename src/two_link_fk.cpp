#include<cmath>
#include<iostream>

int main(){
    double theta1,theta2,link1,link2,pos1_x,pos1_y,pos2_x,pos2_y;

    //Assumption here is theta 1 nd theta 2 are in radian but not in degree
    std::cout<<"Enter link 1 and link 2";
    std::cin>>link1>>link2;
    std::cout<<"Enter theta 1 and theta 2";
    std::cin>>theta1>>theta2;
   
    pos1_x = link1 *std::cos(theta1);
    pos1_y = link1 *std::sin(theta1);

    pos2_x = pos1_x+link2 *std::cos(theta1+theta2);
    pos2_y = pos1_y+link2 *std::sin(theta1+theta2);
    
    std::cout << "Joint 1 position: (" << pos1_x << ", " << pos1_y << ")\n";
    std::cout << "End effector position: (" << pos2_x << ", " << pos2_y << ")\n";


    return 0;

}