#include<iostream>
using namespace std;
#ifndef ITEM_HPP
#define ITEM_HPP
class item{
    protected:
    string item_name;
    int price;
    string itype;
    public:
    item(string,int,string);
    virtual string course_type()=0;
};
#endif