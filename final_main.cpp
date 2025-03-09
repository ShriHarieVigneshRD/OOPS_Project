#include <iostream>
#include "newowner.hpp"
#include "existing_owners.hpp"
#include "functions.hpp"
#include "customer.hpp"
#include<fstream>

using namespace std;

void call_customer(){
	   // Get the current time in UTC
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    
    // Convert to local time (assuming the local time is UTC)
    std::tm* utc_time = std::gmtime(&now_time_t);

    // Create a new tm struct for IST (UTC + 5:30)

    std::tm ist_time = *utc_time;

    // Add 5 hours and 30 minutes to UTC time
    ist_time.tm_hour += 2;
    ist_time.tm_min += 30;

    // Normalize the time (in case it overflows into the next hour or day)
    std::mktime(&ist_time);

    // Print the time in IST
    std::cout << "Current IST time: " 
              << std::put_time(&ist_time, "%H:%M:%S") << std::endl;
              //customer code starts.
	Customer c;
	int choice=0,max_choice;
	cout<<endl<<"Enter -1 to exit application";
	do{
	cout<<endl<<"1) Log in "<<endl<<"2) Register (Choose this if you are a new customer)."<<endl<<"Your choice:";
	cin>>choice;
	if(choice!=1 && choice!=2 && choice !=-1){
		cout<<"Invalid choice! Please select from given choices.";
	}
	}while(choice!=1 && choice!=2 && choice !=-1);
	do{
	if(choice==1){
	int sentinel=0;
		do{
		try {
        // Attempt to log in with the provided credentials
			c.login();
        cout << "Login successful!" << endl;
    	 
			sentinel=1;
		
			
			
		cout<<endl<<"**************  "<<"Welcome "<<c.fname<<" "<<c.lname<<"!"<<"  **************"<<endl;
		do{
		cout<<endl<<"Select 0 to Log out during the whole session."<<endl;
		cout<<"Select type of food you would like to order(number):"<<endl<<endl<<"1) Veg"<<endl<<"2) Non-Veg"<<endl<<"Your Choice :";
		cin>>choice;
		cout<<"Select the restaurant you would like to order(number):"<<endl;
		vector<Billitem> bill;
		switch(choice){
			case 1:
				max_choice=displayHotels("Veg",ist_time.tm_hour);
				if(max_choice>0){
				do{
				cout<<endl<<"Your choice:";
				cin>>choice;
				if(choice>max_choice){
					cout<<endl<<"Invalid selection!Please select in given choices.";
				}
				}while(choice>max_choice);
				}
				else{
					choice=0;
				}
				if(choice>0){
				loadMenu(choice,"Veg",ist_time.tm_hour,bill);
				displayMenuclone(bill);
				do{
				cout<<endl<<"Select item by entering the respective token number."<<endl<<" -2)Confirm order and display bill."<<endl<<" -1)Cancel order."<<endl<<"Your choice:";
				cin>>choice;
				if(checkitem(choice,bill)){
					for(int i=0;i<bill.size();i++){
						if(bill[i].token_number==choice){
							bill[i].quantity+=1;
							bill[i].total_price+=bill[i].unit_price;
							cout<<endl<<"-->"<<bill[i].item_name<<" is added to bill.";
							cout<<endl<<"--------------------------------------------------------------";
							cout<<endl<<"                          BILL                                ";
							cout<<endl<<"--------------------------------------------------------------";
							Billitem sum;
					for(int i=0;i<bill.size();i++){
						sum+=bill[i];
						if(bill[i].quantity>0){
						cout<<endl<<bill[i].item_name<<" | Quantity:" <<bill[i].quantity<<" | Price :"<<bill[i].quantity<<" x "<<bill[i].unit_price<<" = "<<bill[i].total_price;
						}
					}
					cout<<endl<<"=============================================================";
					cout<<endl<<"Current Bill:"<<sum.total_price;
					cout<<endl<<"=============================================================";
						break;
						}
					}
									
				}
				else{	
				if(choice!=-2 && choice!= 0 && choice!=-1){
					cout<<endl<<"Invalid token number! Please select from given token numbers.";
					}
					if(choice==0){
						cout<<endl<<"No order has been placed"<<endl<<"Thank you!";
					}
					if(choice==-1){
						cout<<endl<<"Your order has been cancelled!";
					}
				}
				
				}while(choice!=0 && choice !=-1 && choice!=-2);
				}
				if(choice==-2){
						cout<<endl<<"``````````````````````````````````````````````````````````````";
						cout<<endl<<"                          BILL                                ";
						cout<<endl<<"``````````````````````````````````````````````````````````````";
					Billitem sum;
					for(int i=0;i<bill.size();i++){
						sum+=bill[i];
						if(bill[i].quantity>0){
						cout<<endl<<bill[i].item_name<<" | Quantity:" <<bill[i].quantity<<" | Price :"<<bill[i].quantity<<" x "<<bill[i].unit_price<<" = "<<bill[i].total_price;
						}
					}
					cout<<endl<<"=============================================================";
					cout<<endl<<"Total Bill:"<<sum.total_price;
					cout<<endl<<"=============================================================";
					if(sum.total_price==0){
						cout<<endl<<"Your order cannot be placed.This order has been cancelled.";
					}
					else{
					cout<<endl<<"Your order has been confirmed!"<<endl;
					}
				}	
					
				
				break;
				
			case 2:
				max_choice=displayHotels("NonVeg",ist_time.tm_hour);
				if(max_choice>0){
				do{
				cout<<endl<<"Your choice:";
				cin>>choice;
				if(choice>max_choice){
					cout<<endl<<"Invalid selection!Please select in given choices.";
				}
				}while(choice>max_choice);
				}
				else{
					choice=0;
				}
				if(choice>0){
				loadMenu(choice,"NonVeg",ist_time.tm_hour,bill);
				displayMenuclone(bill);
				do{
				cout<<endl<<"Select item by entering the respective token number."<<endl<<" -2)Confirm order and display bill."<<endl<<" -1)Cancel order."<<endl<<"Your choice:";
				cin>>choice;
				if(checkitem(choice,bill)){
					for(int i=0;i<bill.size();i++){
						if(bill[i].token_number==choice){
							bill[i].quantity+=1;
							bill[i].total_price+=bill[i].unit_price;
							cout<<endl<<"-->"<<bill[i].item_name<<" is added to bill.";
							cout<<endl<<"--------------------------------------------------------------";
							cout<<endl<<"                          BILL                                ";
							cout<<endl<<"--------------------------------------------------------------";
							Billitem sum;
					for(int i=0;i<bill.size();i++){
						sum+=bill[i];
						if(bill[i].quantity>0){
						cout<<endl<<bill[i].item_name<<" | Quantity:" <<bill[i].quantity<<" | Price :"<<bill[i].quantity<<" x "<<bill[i].unit_price<<" = "<<bill[i].total_price;
						}
					}
					cout<<endl<<"=============================================================";
					cout<<endl<<"Current Bill:"<<sum.total_price;
					cout<<endl<<"=============================================================";
						break;
						}
					}
									
				}
				else{	
				if(choice!=-2 && choice!= 0 && choice!=-1){
					cout<<endl<<"Invalid token number! Please select from given token numbers.";
					}
					if(choice==0){
						cout<<endl<<"No order has been placed"<<endl<<"Thank you!";
					}
					if(choice==-1){
						cout<<endl<<"Your order has been cancelled!";
					}
				}
				
				}while(choice!=0 && choice !=-1 && choice!=-2);
				}
				if(choice==-2){
						cout<<endl<<"``````````````````````````````````````````````````````````````";
						cout<<endl<<"                          BILL                                ";
						cout<<endl<<"``````````````````````````````````````````````````````````````";
					Billitem sum;
					for(int i=0;i<bill.size();i++){
						sum+=bill[i];
						if(bill[i].quantity>0){
						cout<<endl<<bill[i].item_name<<" | Quantity:" <<bill[i].quantity<<" | Price :"<<bill[i].quantity<<" x "<<bill[i].unit_price<<" = "<<bill[i].total_price;
						}
					}
					cout<<endl<<"=============================================================";
					cout<<endl<<"Total Bill:"<<sum.total_price;
					cout<<endl<<"=============================================================";
					if(sum.total_price==0){
						cout<<endl<<"Your order cannot be placed.This order has been cancelled.";
					}
					else{
					cout<<endl<<"Your order has been confirmed!"<<endl;
					}
				}	
				
				break;
		}
		if(choice!=0 ){
		cout<<endl<<"What would you like to do next?"<<endl<<"0)Log out :("<<endl<<"1)Order again :)"<<endl<<"Your choice:";
			cin>>sentinel;
			}
			else{
				sentinel=choice;
				if(choice==-1){
					sentinel=0;
				}
			}
		}while(sentinel==1);
		if(sentinel==0){
			sentinel=1;
		}
		}
		catch (const runtime_error& e) {
        // Handle any errors that occur during the login process
        cout << "Error: " << e.what() << endl;
		sentinel=0;
    	}
	
		
	
	}while(sentinel==0);
	
	
	cout<<endl<<"Enter -1 to exit application";
	do{
	cout<<endl<<"1) Log in "<<endl<<"2) Register (Choose this if you are a new customer)."<<endl<<"Your choice:";
	cin>>choice;
	if(choice!=1 && choice!=2 && choice !=-1){
		cout<<"Invalid choice! Please select from given choices.";
	}
	}while(choice!=1 && choice!=2 && choice !=-1);
	}
	else if(choice ==2){
		register_customer();
		cout<<endl<<"Enter -1 to exit application";
	do{
	cout<<endl<<"1) Log in "<<endl<<"2) Register (Choose this if you are a new customer)."<<endl<<"Your choice:";
	cin>>choice;
	if(choice!=1 && choice!=2 && choice !=-1){
		cout<<"Invalid choice! Please select from given choices.";
	}
	}while(choice!=1 && choice!=2 && choice !=-1);
	
	
	}
	else if(choice==-1){
		cout<<endl<<"Thank you!";
	}
}while(choice==1 || choice==2 );

}

	
void call_owner()
{
	int choice;
    long int registration_number ;
    string regno;
    string pass;
    
    cout<<"**************  "<<"Welcome to Hotel Management Service"<<"!"<<"  **************"<<endl;
    cout << "Are you a new or existing owner?" << endl;
    cout << "1. New Owner" << endl;
    cout << "2. Existing Owner" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // To handle any newline characters left in the input stream
    
    if (choice == 1) {
        // New Owner Flow
        cout << "New Owner Registration:" << endl;
        assign_new_owner();
    } 
    else if (choice == 2) {
        // Existing Owner Flow
        string hotel_name,password,reg_check;
        int check=1;
        cout << "Enter the registration number"<<endl;
        cin>>registration_number;
        regno=to_string(registration_number);
        ifstream file(regno+".txt");
        int i=0;
        for(i=0;i<10;i++)
        file>>hotel_name;
        getline(file,hotel_name);
        cout<<"Enter password"<<endl;
        cin>>pass;
	if(authenticate_existing_owner(regno,password,"existing_owners.txt"))
	{
        Existingowner existingOwner(registration_number,pass);
        cout<<endl<<"**************  "<<"Welcome "<<hotel_name<<"!"<<"  **************"<<endl;
        while(check)
        {
			
        		cout<<"Enter 1 to Update Menu\n";
        		cout<<"Enter 2 to Update Slot Time\n";
        		cout<<"Enter 3 to discontinue from our Hotel Management Sevices\n";
        		cout<<"Enter 0 to Exit\n";
        		cin>>check;
        		if(check==1)
        		existingOwner.update_menu(existingOwner);
       		 	else if(check==2)
        		existingOwner.update_time(existingOwner);
        		else if(check==3)
        		{
            		ifstream Myfile("existing_owners.txt");
            		ofstream tempfile("temp.txt");
            		while(Myfile>>reg_check>>password)
            		{
                		if(reg_check!=regno)
                		tempfile<<reg_check<<" "<<password<<'\n';
                		else
                		continue;
            		}
            		rename("temp.txt","existing_owners");
            		remove((regno+".txt").c_str());
        		}

        		else
        		{
        			if(check!=0)
        			cout<<"Invalid Input\n";
        		}
			
			
        }
	}
	else
	cout<< "You are not an existing user\n";
    } 
    else {
        cout << "Invalid choice. Please select either 1 or 2." << endl;
    }

    cout << "Thank you for using our Hotel Management Serives." << endl;  
}

int main() {
    int option;
    cout << endl << "******************  Welcome to Hotel Management System  ******************" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "1 - Customer: Browse our services and place an order." << endl;
    cout << "2 - Hotel Owner: Register as a new owner or log in as an existing owner to manage your listings." << endl;
    
    while (true) { // Loop until valid input is received
        cout << "Enter your choice (1 for Customer, 2 for Hotel Owner): ";
        cin >> option;

        // Validate the input
        if (option == 1) {
            cout << "You selected Customer. Proceeding to customer options..." << endl;
            call_customer();
            break;
        }
        else if (option == 2) {
            cout << "You selected Hotel Owner. Proceeding to owner options..." << endl;
            call_owner();
            break;
        }
        else {
            cout << "Invalid choice. Please enter 1 for Customer or 2 for Hotel Owner." << endl;
        }
    }

    return 0;
}
