#include<iostream>
#include "item.hpp"
using namespace std;
#ifndef DINNER_HPP
#define DINNER_HPP
class dinner:virtual public item{
    protected:
    int start_time;
    int end_time;
    public:
    dinner(string ,int ,string ,int =18,int =23);
    virtual string availability_dinner();
};      
#endif