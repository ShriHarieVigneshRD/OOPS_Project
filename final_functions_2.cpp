#include "customer.hpp"
#include <fstream>
#include <string>
Customer :: Customer(long int a,string b,string c,string d){
}

void Customer :: login(){
	cout<<endl<<"Enter Phone number:";
	cin>>phn_no;
	//int k=phn_no,count=0;
	int* count = new int(0);
	long int* k = new long int(0);
    *k=phn_no;
	while(*k!=0){
		*count+=1;
		*k=*k/10;
	}
	if(*count!=10)
	throw runtime_error("Phone number must contain exactly 10 digits! Please try again."); 
	delete count;
	delete k;
	cout<<endl<<"Enter Password:";
	cin>>password;
	fstream myfile;
	myfile.open("existing_customers.txt",ios::in);
	string file_phn_no, file_password;
	while(myfile>> file_phn_no >> file_password){
		if(file_phn_no==to_string(phn_no) && file_password==password){
			myfile >> fname >>lname;
			return;
		}
		myfile>> file_phn_no >> file_password;
	}
	throw runtime_error("Username and password are not matching!Please enter valid credentials!");
	
}
void register_customer(){
	
	long int temp_phn_no;
	string temp_password,temp_fname,temp_lname;
	cout<<"Enter your details:"<<endl<<"First Name:";
	cin>>temp_fname;
	cout<<endl<<"Last Name:";
	cin>>temp_lname;
	do{
	cout<<endl<<"Phone number:";
	cin>>temp_phn_no;
	if(temp_phn_no/1000000000==0){
		cout<<endl<<"Invalid phone number";
	}
	}while(temp_phn_no/1000000000==0);
	cout<<endl<<"Set a password for your account."<<endl <<"New Password:";
	cin>>temp_password;
	ofstream myfile;
	myfile.open("existing_customers.txt",ios::app);
	myfile << temp_phn_no<<" "<<temp_password<<" "<<temp_fname<<" "<<temp_lname<<'\n';
	myfile.close();
		
}

int displayHotels(string food_type,int hour){
	int count=0;
	//cout<<endl<<endl<<hour<<endl<<endl;
	ifstream owners_file("existing_owners.txt");
	string file_name,temp_name;
	ofstream stored_hotels;
	stored_hotels.open("stored_hotels.txt",ios::out);
	while(owners_file >> file_name){
	temp_name=file_name;
	file_name=file_name+".txt";
		
		ifstream hotel_file(file_name);
		string temp1,temp2,temp;
		hotel_file>>temp1>>temp2;
		temp=temp2;
		int flag=0;
		if(food_type=="Veg"){
		if(temp2==food_type){
		
			for(int i=0;i<4;i++){
			hotel_file>>temp1>>temp2;
				if(stoi(temp1)<=hour && stoi(temp2)>hour){
					flag=1;
				}
			}
			if(flag==1){
			getline(hotel_file,temp1);
					cout<<endl<<++count<<") "<<temp1<<" "<<temp;
					stored_hotels<<count<<" "<<temp_name<<'\n';
			}
		}
		}
		else if(food_type=="NonVeg"){
			for(int i=0;i<4;i++){
			hotel_file>>temp1>>temp2;
				//cout<<endl<<stoi(temp1)<<" " <<stoi(temp2);
				if(stoi(temp1)<=hour && stoi(temp2)>hour){
					flag=1;
				}
			}
			if(flag==1){
			getline(hotel_file,temp1);
					cout<<endl<<++count<<") "<<temp1<<" "<<temp;
					stored_hotels<<count<<" "<<temp_name<<'\n';
			}
		}
		hotel_file.close();
		owners_file>>file_name;
	}		
	if(count==0){
		cout<<endl<<"No restaurants currently available ";
	}	
	owners_file.close();
	
	stored_hotels.close();
	return count;
		
}

int checkitem(int choice,vector<Billitem> &bill){
	for(int i=0;i<bill.size();i++){
		if(bill[i].token_number==choice){
			return 1;
		}
	}
	return 0;

}

void loadMenu(int choice,string food_type,int hour,vector<Billitem> &bill){
	//cout<<endl<<endl<<hour<<endl<<endl;
	int count=0;
	ifstream owners_file("stored_hotels.txt");
	string count_num,file_name;
	while (owners_file>>count_num>>file_name){
	
		if(count_num==to_string(choice)){
			break;
		}
	}
	cout<<file_name;
		file_name=file_name+".txt";
		ifstream hotel_file(file_name);
		string temp1,temp2,temp;
		hotel_file>>temp1>>temp2;
		temp=temp2;
		for(int i=0;i<4;i++){
			hotel_file>>temp1>>temp2;
			if(stoi(temp1)<=hour && stoi(temp2)>hour){
				count=i+1;
			}
			
		}
		//cout<<endl<<endl<<count<<endl<<endl;
			getline(hotel_file,temp1);
			cout<<endl<<"              "<<temp1<<" ("<<temp<<")";
			/*cout<<endl<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
			cout<<endl<<"                          MENU                                ";
			cout<<endl<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
			*/
			string serial,price,type,msd,time,name;
			Billitem o;
		switch(count){
			case 1:
				while(hotel_file>>serial>>price>>type>>msd>>time){
					getline(hotel_file,name);
					if(time=="breakfast"){
						o.token_number=stoi(serial);
						o.unit_price=stoi(price);
						o.item_name=name;
						o.quantity=0;
						o.total_price=0;
						o.type=type;
						o.msd=msd;
						o.time=time;
						msd=="starter"?o.sortmsd=0:(msd=="maincourse"?o.sortmsd=1:(msd=="snacks"?o.sortmsd=2:o.sortmsd=3));
						//cout<<endl<<"Token Number:"<<serial<<" | Item name:"<<name<<"("<<type<<")"<<" | Price:"<<price<<" | "<<msd<<" | "<<time;
						bill.push_back(o);
					}
				}
				break;
			case 2:
				while(hotel_file>>serial>>price>>type>>msd>>time){
					getline(hotel_file,name);
					if(time=="lunch"){
						o.token_number=stoi(serial);
						o.unit_price=stoi(price);
						o.item_name=name;
						o.quantity=0;
						o.total_price=0;
						o.type=type;
						o.msd=msd;
						o.time=time;
						msd=="starter"?o.sortmsd=0:(msd=="maincourse"?o.sortmsd=1:(msd=="snacks"?o.sortmsd=2:o.sortmsd=3));
						//	cout<<endl<<"Token Number:"<<serial<<" | Item name:"<<name<<"("<<type<<")"<<" | Price:"<<price<<" | "<<msd<<" | "<<time;
						bill.push_back(o);
					}
				}
				break;
			case 3:
				while(hotel_file>>serial>>price>>type>>msd>>time){
					getline(hotel_file,name);
					if(time=="snacks"){
						o.token_number=stoi(serial);
						o.unit_price=stoi(price);
						o.item_name=name;
						o.quantity=0;
						o.total_price=0;
						o.type=type;
						o.msd=msd;
						o.time=time;
						msd=="starter"?o.sortmsd=0:(msd=="maincourse"?o.sortmsd=1:(msd=="snacks"?o.sortmsd=2:o.sortmsd=3));
						//cout<<endl<<"Token Number:"<<serial<<" | Item name:"<<name<<"("<<type<<")"<<" | Price:"<<price<<" | "<<msd<<" | "<<time;
						bill.push_back(o);
					}
				}
				break;
			case 4:
				while(hotel_file>>serial>>price>>type>>msd>>time){
					getline(hotel_file,name);
					if(time=="dinner"){
						o.token_number=stoi(serial);
						o.unit_price=stoi(price);
						o.item_name=name;
						o.quantity=0;
						o.total_price=0;
						o.type=type;
						o.msd=msd;
						o.time=time;
						msd=="starter"?o.sortmsd=0:(msd=="maincourse"?o.sortmsd=1:(msd=="snacks"?o.sortmsd=2:o.sortmsd=3));
						//cout<<endl<<"Token Number:"<<serial<<" | Item name:"<<name<<"("<<type<<")"<<" | Price:"<<price<<" | "<<msd<<" | "<<time;
						bill.push_back(o);
					}
				}
				break;
			default:
				cout<<endl<<"Server error!";
				break;
		
		}
		cout<<endl<<"---------------------------------------------------------------------"<<endl;
		owners_file.close();
		hotel_file.close();
	
}
template <class T>
void sort_price(vector<T>& bill, bool (*compare)(int, int)) {
    for (int i = 0; i < bill.size() - 1; i++) {
        for (int j = 0; j < bill.size() - i - 1; j++) {
            if ((*compare)(bill[j].unit_price, bill[j + 1].unit_price)) {
                T a = bill[j];
                bill[j] = bill[j + 1];
                bill[j + 1] = a;
            }
        }
    }
}
template <class T>
void sort_msd(vector<T>& bill, bool (*compare)(int, int)) {
    for (int i = 0; i < bill.size() - 1; i++) {
        for (int j = 0; j < bill.size() - i - 1; j++) {
            if ((*compare)(bill[j].sortmsd, bill[j + 1].sortmsd)) {
                T a = bill[j];
                bill[j] = bill[j + 1];
                bill[j + 1] = a;
            }
        }
    }
}
template <class T>
bool ascending(T A, T B) {
    return A > B;
}
template <class T>
bool descending(T A, T B) {
    return A < B;
}

void displayMenuclone(vector<Billitem>& bill) {
	sort_msd(bill, &ascending); 
	   cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    cout << endl << "                          MENU                                ";
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    for (int i = 0; i < bill.size(); i++) {
        cout << endl << "Token Number: " << bill[i].token_number << " | Item name: " << bill[i].item_name << " (" << bill[i].type << ") | Price: " << bill[i].unit_price<< " | " << bill[i].msd << " | " << bill[i].time << " | ";
    }
	string sort_choice;
	do{
    cout << endl << "1) Sort the items from low to high" << endl;
    cout << "2) Sort items from high to low" << endl;
    cout << ";) Enter any key to skip to ordering process." << endl;
    cout << "(Note: Key 0 will not log you out of the session here, so enter any key to skip.)" << endl;
    cout << "Your choice: ";
    cin >> sort_choice;
    
    if (sort_choice == "1") {
        sort_price(bill, &ascending);  
    } else if (sort_choice == "2") {
        sort_price(bill, &descending);
    }

    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    cout << endl << "                          MENU                                ";
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    for (int i = 0; i < bill.size(); i++) {
        cout << endl << "Token Number: " << bill[i].token_number << " | Item name: " << bill[i].item_name << " (" << bill[i].type << ") | Price: " << bill[i].unit_price<< " | " << bill[i].msd << " | " << bill[i].time << " | ";
    }
	}while(sort_choice =="1" || sort_choice =="2");
}
Billitem :: Billitem(int tokennumber,int unitprice,string s,string s1,string s2,string s3,int totalprice,int q){
	token_number=tokennumber;
	unit_price=unitprice;
	item_name=s;
	time=s1;
	type=s3;
	msd =s2;
	total_price=totalprice;
	quantity=q;
}
Billitem Billitem :: operator+=(const Billitem item){
	this->total_price=this->total_price+item.total_price;
	return *this;
}
