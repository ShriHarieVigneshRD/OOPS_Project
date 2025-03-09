#include<iostream>
#include "lunch.hpp"
#include "dinner.hpp"
using namespace std;
#ifndef DESSERT_HPP
#define DESSERT_HPP
class dessert:public dinner,public lunch{
    public:
    dessert(string,int,string,int,int);
    virtual string course_type();
};     
#endif 