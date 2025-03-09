#include<iostream>
#include "lunch.hpp"
#include "dinner.hpp"
using namespace std;
#ifndef STARTER_HPP
#define STARTER_HPP
class starter:public dinner,public lunch{
    public:
    starter(string ,int ,string ,int =6,int =11);
    virtual string course_type();
};     
#endif 