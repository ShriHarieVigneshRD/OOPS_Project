#include<iostream>
using namespace std;
#ifndef OWNERS_HPP
#define OWNERS_HPP
class owner{
    protected:
        long int  regnumber;
        string password;
        int count=0;
    public: 
        owner(long int,string);

};
#endif