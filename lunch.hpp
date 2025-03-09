#include<iostream>
#include "item.hpp"
using namespace std;
#ifndef LUNCH_HPP
#define LUNCH_HPP
class lunch:virtual public item{
    protected:
    int start_time;
    int end_time;
    public:
    lunch(string ,int ,string ,int =11,int =15);
    virtual string availability_lunch();
};      
#endif