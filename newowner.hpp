#include<iostream>
#ifndef NEWOWNER_HPP
#define NEWOWNER_HPP
#include"owners.hpp"
#include "breakfast.hpp"
#include "dessert.hpp"
#include "maincourse.hpp"
#include "starter.hpp"
#include "snacks.hpp"
#include<vector>

using namespace std;

class Newowner:public owner{
   protected: string name;
   string type;//Veg,NonVeg
   public:
   vector<dessert> dess;
   vector<maincourse> mc;
   vector<snacks> snack;
   vector<starter> stat;
   Newowner(string,string,long int,string);
   void setmenu();
friend ostream & operator <<(ostream &,Newowner &);
};
#endif