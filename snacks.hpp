#include<iostream>
#include "item.hpp"
using namespace std;
#ifndef SNACKS_HPP
#define SNACKS_HPP
class snacks:virtual public item{
    protected:
    int start_time;
    int end_time;
    public:
    snacks(string ,int ,string ,int =16,int =17);
    virtual string availability_snacks();
    virtual string course_type();
};    
#endif  