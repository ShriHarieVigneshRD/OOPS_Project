#include<iostream>
#include "item.hpp"
using namespace std;
#ifndef BREAKFAST_HPP
#define BREAKFAST_HPP
class bf:virtual public item{
    protected:
    int start_time;
    int end_time;
    public:
    bf(string ,int ,string ,int =6,int =11);
    virtual string availability_bf();
};     
#endif 