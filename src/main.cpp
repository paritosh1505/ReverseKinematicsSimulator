#include<cmath>
#include<iostream>

int main(){
    double x,y,theta,lVal;
    std::cout<<"Enter you radian";
    std::cin>>theta;
    std::cout<<"\n";
    std::cout<<"Enter L value";
    std::cin>>lVal;
    std::cout<<"\n";
    x = lVal * std::cos(theta);
    y = lVal * std::sin(theta);
    std::cout<<"Required coordinates are ("<<x<<","<<y<<")";
    return 0;
}