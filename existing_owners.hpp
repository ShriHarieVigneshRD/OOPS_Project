#include<iostream>
#include"owners.hpp"
#ifndef EXISTING_OWNERS_HPP
#define EXISTING_OWNERS_HPP

using namespace std;

class Existingowner:public owner{
   public:
   Existingowner(long int,string);
   void update_menu(Existingowner &);
   void update_time(Existingowner &);
   vector<dessert> dess;
   vector<maincourse> mc;
   vector<snacks> snack;
   vector<starter> stat;
   friend ostream & operator <<(ostream &,Existingowner &);
};
#endif