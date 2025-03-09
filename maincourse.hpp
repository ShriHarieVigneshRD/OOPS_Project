#include<iostream>
#include "breakfast.hpp"
#include "lunch.hpp"
#include "dinner.hpp"
using namespace std;
#ifndef MAINCOURSE_HPP
#define MAINCOURSE_HPP
class maincourse:public bf,public dinner,public lunch{
    public:
    maincourse(string ,int ,string ,int =6,int =11);
    virtual string course_type();
};     
#endif 