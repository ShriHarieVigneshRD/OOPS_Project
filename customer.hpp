#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <limits.h>
using namespace std;
class Customer{ 
	public:
		string fname;
		string lname;
	private:
		long int phn_no;
		string password;
	public:
		Customer(long int =0,string="",string="",string="");
		void login();			
};
class Billitem{
	
	public:
		int token_number;
		int unit_price;
		string item_name;
		string type;
		string msd;
		string time;
		int total_price;
		int quantity;
		int sortmsd;
		Billitem operator+=(const Billitem item);
		Billitem(int tokennumber=INT_MIN,int unitprice=0,string s="BILL ITEM-X",string s1="",string s2="",string s3="",int totalprice=0,int q =0);
};

void register_customer();
int displayHotels(string,int);
void loadMenu(int ,string,int,vector<Billitem> &);
int checkitem(int ,vector<Billitem> &);
void displayMenuclone(vector<Billitem>& );
