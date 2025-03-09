#include<iostream>
#include "owners.hpp"
#include "breakfast.hpp"
#include "lunch.hpp"
#include "snacks.hpp"
#include "dinner.hpp"
#include"newowner.hpp"
#include"existing_owners.hpp"
#include <fstream>
#include <string>
#include "starter.hpp"
#include "maincourse.hpp"
#include "dessert.hpp"
#include "functions.hpp"
using namespace std;

bool authenticate_new_owner(const string& regNumber, const string& password, const string& filename,string& filename2) {
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    bool isAuthenticated = false;
    ofstream existing_owner(filename2,ios::app);
    string fileRegNumber, filePassword;

    // Read each line and check for matching registration number and password
    while (file >> fileRegNumber >> filePassword) {
        if (fileRegNumber == regNumber && filePassword == password) {
            isAuthenticated = true;  // Match found
            // Skip writing this line to temp file to "delete" it
            existing_owner << fileRegNumber << " " << filePassword << "\n";
            continue;
        }
        // Write unmatched lines to temp file
        tempFile << fileRegNumber << " " << filePassword << "\n";
    }

    file.close();
    tempFile.close();

    // Replace original file with updated temp file
    if (isAuthenticated) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    } else {
        // Remove temp file if authentication fails
        remove("temp.txt");
    }

    return isAuthenticated;
}

bool authenticate_existing_owner(const string& regNumber, const string& password,const string& filename){
    ifstream file(filename);
    bool isAuthenticated = false;
    string fileRegNumber, filePassword;
    while (file >> fileRegNumber >> filePassword) {
        if (fileRegNumber == regNumber && filePassword == password) {
            isAuthenticated = true;  // Match found
            break;
        }
    }
    return isAuthenticated;
}

item :: item(string item,int cost,string item_type)
{
    item_name=item;
    price=cost;
    itype=item_type;
}

lunch :: lunch(string name,int cost,string item_type,int start,int end):item(name,cost,item_type)
{
    start_time=start;
    end_time=end;
}

dinner :: dinner(string name,int cost,string item_type,int start,int end):item(name,cost,item_type)
{
    start_time=start;
    end_time=end;
}

bf :: bf(string name,int cost,string item_type,int start,int end):item(name,cost,item_type)
{
    start_time=start;
    end_time=end;
}

snacks :: snacks(string name,int cost,string item_type,int start,int end):item(name,cost,item_type)
{
    start_time=start;
    end_time=end;
}

owner::owner(long int regno,string passw){
    regnumber=regno;
    password=passw;
}

Newowner::Newowner(string hotelname,string t,long int regno,string password):owner(regno,password){
    name=hotelname;
    type=t;
}

Existingowner::Existingowner(long int regno,string password):owner(regno,password){

}

void Newowner::setmenu(){
    int bfitems;
    int stb,etb;
    ofstream file(to_string(regnumber)+".txt");
    
    if(type=="Veg")
    cout<<"Only Veg items should be entered\n";
    cout<<"Enter the no of breakfast items"<<endl;
    cin>>bfitems;
    if(bfitems!=0)
    {
    do
    {
    cout<<"Enter the start time and end time of breakfast(Time slots within 6 to 11): "<<endl;
    cin>>stb>>etb;
    if(stb<6 || etb>11)
    cout<<"Invalid Input\n";
    }while(stb<6 || etb>11);
    }
    int litems;
    int stl,etl;
    cout<<"Enter the no of lunch items"<<endl;
    cin>>litems;
    if(litems!=0)
    {
    do
    {
    cout<<"Enter the start time and end time of lunch(Time Slots within 11 to 15): "<<endl;
    cin>>stl>>etl;
    if(stl<11 || etl>15)
    cout<<"Invalid Input\n";
    }while(stl<11 || etl>15);
    }
    int snitems;
    int stsn,etsn;
    cout<<"Enter the no of snacks items"<<endl;
    cin>>snitems;
    if(snitems!=0)
    {
    cout<<"Start time and End time of snacks are respectively 16 and 17"<<endl;
    stsn=16,etsn=17;
    }
    int ditems;
    int std,etd;
    cout<<"Enter the no of dinner items"<<endl;
    cin>>ditems;
    if(ditems!=0)
    {
    do
    {
    cout<<"Enter the start time and end time of dinner(Time Slots within 18 and 23): "<<endl;
    cin>>std>>etd;
    if(std<18 || etd>23)
    cout<<"Invalid Input\n";
    }while(std<18 || etd>23);
    }

    
    file << password << " "<< type << " " << stb << " " << etb << " " << stl << " " << etl << " " << stsn << " " << etsn << " " << std << " " << etd << " " << name <<'\n';
    if(bfitems!=0)
    {
    bf*course;
    cout << "Enter the Breakfast Items" <<endl;
    for(int i=0;i<bfitems;i++){
        string iname;
        int cost;
        string item_type;
        string c_type="maincourse";
        cout<<"Enter the item name: "<<endl;
        cin.ignore();
        getline(cin,iname);
        cout<<"Enter the cost: "<<endl;
        cin>>cost;
        if(type=="NonVeg")
        {
        do
        {
        cout<<"Enter the item_type(Veg,NonVeg)"<<endl;
        cin>>item_type;
        if(item_type!="Veg" && item_type!="NonVeg")
        cout<<"Invalid Input\n";
        }while(item_type!="Veg" && item_type!="NonVeg");
        }
        else{
        item_type="Veg";
        }
        maincourse m1(iname,cost,item_type,stb,etb);
        mc.push_back(m1);
        course=&m1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type<<" " <<course->course_type()<<" "<< course->availability_bf() <<" "<<iname<<'\n';
        
    }
    }

    if(litems!=0)
    {
        lunch*course[3];
    cout << "Enter the Lunch Items" <<endl;
    for(int i=0;i<litems;i++){
        string c_type;
        string iname;
        int cost;
        string item_type;
        cout<<"Enter the item name: "<<endl;
        cin.ignore();
        getline(cin,iname);
        cout<<"Enter the cost: "<<endl;
        cin>>cost;
       if(type=="NonVeg")
        {
        do
        {
        cout<<"Enter the item_type(Veg,NonVeg)"<<endl;
        cin>>item_type;
        if(item_type!="Veg" && item_type!="NonVeg")
        cout<<"Invalid Input\n";
        }while(item_type!="Veg" && item_type!="NonVeg");
        }
        else{
        item_type="Veg";
        }
        do
        {
        cout<<"Enter whether the dish is starter or maincourse or dessert: ";
        cin>>c_type;
        if(c_type!="starter" && c_type!="maincourse" && c_type!="dessert")
        cout<<"Invalid Input\n";
        }while(c_type!="starter" && c_type!="maincourse" && c_type!="dessert");
        if(c_type=="starter")
        {
        starter s1(iname,cost,item_type,stb,etb);
        stat.push_back(s1);
        course[0]=&s1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<" "<<course[0]->course_type()<<" "<< course[0]->availability_lunch() <<" "<<iname<<'\n';
        }
        if(c_type=="maincourse")
        {
        maincourse m1(iname,cost,item_type,stb,etb);
        mc.push_back(m1);
        course[1]=&m1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<" "<< course[1]->course_type()<<" "<<course[1]->availability_lunch() <<" "<<iname<<'\n';
        }
        if(c_type=="dessert")
        {
        dessert d1(iname,cost,item_type,stb,etb);
        dess.push_back(d1);
        course[2]=&d1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<" "<<course[2]->course_type()<<" "<< course[2]->availability_lunch() <<" "<<iname<<'\n';
        }
    }
    }

    if(snitems!=0)
    {
    cout << "Enter the Snacks Items" <<endl;
    for(int i=0;i<snitems;i++){
        string iname;
        int cost;
        string item_type;
        cout<<"Enter the item name: "<<endl;
        cin.ignore();
        getline(cin,iname);
        cout<<"Enter the cost: "<<endl;
        cin>>cost;
        if(type=="NonVeg")
        {
        do
        {
        cout<<"Enter the item_type(Veg,NonVeg)"<<endl;
        cin>>item_type;
        if(item_type!="Veg" && item_type!="NonVeg")
        cout<<"Invalid Input\n";
        }while(item_type!="Veg" && item_type!="NonVeg");
        }
        else{
        item_type="Veg";
        }
        snacks s1(iname,cost,item_type,stsn,etsn);
        snack.push_back(s1);
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<" "<<s1.course_type()<<" "<< s1.availability_snacks() <<" "<<iname<<'\n';

    }
    }

    if(ditems!=0)
    {
    dinner* course[3];
    cout << "Enter the Dinner Items" <<endl;
    for(int i=0;i<ditems;i++){
        string iname;
        int cost;
        string item_type,c_type;
        cout<<"Enter the item name: "<<endl;
        cin.ignore();
        getline(cin,iname);
        cout<<"Enter the cost: "<<endl;
        cin>>cost;
       if(type=="NonVeg")
        {
        do
        {
        cout<<"Enter the item_type(Veg,NonVeg)"<<endl;
        cin>>item_type;
        if(item_type!="Veg" && item_type!="NonVeg")
        cout<<"Invalid Input\n";
        }while(item_type!="Veg" && item_type!="NonVeg");
        }
        else{
        item_type="Veg";
        }
        do
        {
        cout<<"Enter whether the dish is starter or maincourse or dessert: ";
        cin>>c_type;
        if(c_type!="starter" && c_type!="maincourse" && c_type!="dessert")
        cout<<"Invalid Input\n";
        }while(c_type!="starter" && c_type!="maincourse" && c_type!="dessert");
        if(c_type=="starter")
        {
        starter s1(iname,cost,item_type,stb,etb);
        stat.push_back(s1);
        course[0]=&s1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<course[0]->course_type()<<" "<< course[0]->availability_dinner() <<" "<<iname<<'\n';
        }
        if(c_type=="maincourse")
        {
        maincourse m1(iname,cost,item_type,stb,etb);
        mc.push_back(m1);
        course[1]=&m1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type << course[1]->course_type()<<" "<<  course[1]->availability_dinner() <<" "<<iname<<'\n';
        }
        if(c_type=="dessert")
        {
        dessert d1(iname,cost,item_type,stb,etb);
        dess.push_back(d1);
        course[2]=&d1;
        file << to_string(++count)<<" "<< to_string(cost) <<" "<< item_type <<course[2]->course_type()<<" "<< course[2]->availability_dinner() <<" "<<iname<<'\n';
        }
    }  
    }
    file.close();  
}

void assign_new_owner(){
    long int registration_number ;
    string regno;
    string pass;
    string link1="new_owners.txt";
    string link2="existing_owners.txt";
    cout << "Enter the registration number"<<endl;
    cin>>registration_number;
    regno=to_string(registration_number);
    cout<<"Enter password"<<endl;
    cin>>pass;
    bool authresult=authenticate_new_owner(regno,pass,link1,link2);
    if(authresult==true){
        string hotelname;
        cout<<"Enter your desired hotel name\n";
        cin.ignore();
        getline(cin,hotelname);
        string t;
        do
        {
        cout<<"Enter the hotel type(Veg or NonVeg)\n";
        cin>>t;
        if(t!="Veg" && t!="NonVeg")
        cout<<"Invalid Input\n";
        }while(t!="Veg" && t!="NonVeg");
        Newowner n1(hotelname,t,registration_number,pass);
        n1.setmenu();
        cout<<n1;
    }
    else{
        cout << "You have either not registered with us or entered incorrect credentials." << endl;
    }
}

ostream & operator <<(ostream& i,Existingowner& o)
{
    ifstream file(to_string(o.regnumber)+".txt");
    string name,password,type,stb,etb,stl,etl,sts,ets,std,etd;
    file >> password>> type>> stb >> etb >> stl >>etl >> sts >> ets >> std >> etd;
    getline(file,name);
    string line;
    string itcount ,itcost , ittype , itname, itava,itcourse;
    cout<<endl<<"--------------------------------------------------------------";
	cout<<endl<<"                       Current Menu                           ";
	cout<<endl<<"--------------------------------------------------------------\n";
    while(file >> itcount >> itcost >> ittype >>itcourse>> itava&& getline(file,itname) )
    {
        cout << itcount << itname <<' '<< itcost<<' '<< itava <<' '<<itcourse<<' '<< ittype << endl;
    }
    cout<<'\n';
    file.close();
    return i;
}

ostream & operator <<(ostream& i,Newowner& o)
{
    ifstream file(to_string(o.regnumber)+".txt");
    string name,password,type,stb,etb,stl,etl,sts,ets,std,etd;
    file >> password>> type>> stb >> etb >> stl >>etl >> sts >> ets >> std >> etd;
    getline(file,name);
    string line;
    string itcount ,itcost , ittype , itname, itava,itcourse;
    cout<<endl<<"--------------------------------------------------------------";
	cout<<endl<<"                       Current Menu                           ";
	cout<<endl<<"--------------------------------------------------------------\n";
    while(file >> itcount >> itcost >> ittype >>itcourse>> itava&& getline(file,itname) )
    {
        cout << itcount << itname <<' '<< itcost<<' '<< itava <<' '<<itcourse<<' '<< ittype << endl;
    }
    cout<<'\n';
    file.close();
    return i;
}

void Existingowner::update_menu(Existingowner& o){
    string link2="existing_owners.txt";
    bool authresult=authenticate_existing_owner(to_string(regnumber),password,link2);
    if(authresult==true){
        int choice=1;
        string hotel_type;
        while(choice!=0){
            cout<<o<<'\n';
            cout<<"1.Add Breakfast"<<"\n"<<"2.Add Lunch"<<"\n"<<"3.Add Snacks"<<"\n"<<"4.Add dinner"<<"\n"<<"5.Delete Item in Menu\n"<<"0.Exit"<<endl;
            cin>>choice;
            switch(choice){
                case 1:{
                  bf* course;
                  ifstream Myfile(to_string(regnumber)+".txt");
                  ofstream file(to_string(regnumber)+".txt",ios::app);
                  Myfile>>hotel_type>>hotel_type;
                  if(hotel_type=="Veg")
                  cout<<"Add only Veg Items\n";
                  string bf_item;
                  int cost;
                  string item_type;
                  string item_no,stb,etb;
                  string remaining_line;
                  cout<<"Enter the breakfast item: ";
                  cin.ignore();
                  getline(cin,bf_item);
                  cout<<"Enter cost of the item: ";
                  cin>>cost;
                  if(hotel_type=="NonVeg")
                  {
                  do
                  {
                  cout<<"Enter the item type (Veg or NonVeg) :";
                  cin>>item_type;
                  if(item_type!="Veg" && item_type!="NonVeg")
                  cout<<"Invalid Invalid\n";
                  }while(item_type!="Veg" && item_type!="NonVeg");
                  }
                  else
                  item_type="Veg";
                  Myfile >> stb>>etb;
                  while(Myfile >> item_no && getline(Myfile,remaining_line))
                  {
                        count=stoi(item_no);
                  }
                  maincourse m1(bf_item,cost,item_type,stoi(stb),stoi(etb));
                  mc.push_back(m1);
                 course=&m1;
                 file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course->course_type()<<" "<< course->availability_bf()<<" "<<bf_item<<'\n';
                 Myfile.close();
                 file.close();
                 break;
                  
                }
                case 2:{
                  lunch* course[3];
                  ifstream Myfile(to_string(regnumber)+".txt");
                  ofstream file(to_string(regnumber)+".txt",ios::app);
                  Myfile>>hotel_type>>hotel_type;
                  if(hotel_type=="Veg")
                  cout<<"Add only Veg Items\n";
                  string l_item;
                  string remaining_line;
                  int cost;
                  string item_no;
                  string item_type,stl,etl;
                  cout<<"Enter the lunch item :";
                  cin.ignore();
                  getline(cin,l_item);
                  cout<<"Enter cost of the item: ";
                  cin>>cost;
                 if(hotel_type=="NonVeg")
                  {
                  do
                  {
                  cout<<"Enter the item type (Veg or NonVeg) :";
                  cin>>item_type;
                  if(item_type!="Veg" && item_type!="NonVeg")
                  cout<<"Invalid Invalid\n";
                  }while(item_type!="Veg" && item_type!="NonVeg");
                  }
                  else
                  item_type="Veg";
                  Myfile>>stl>>stl>>stl>>etl;
                  while(Myfile >> item_no && getline(Myfile,remaining_line))
                  {
                        count=stoi(item_no);
                  }
                  string c_type;
                  do
                  {
                  cout<<"Enter whether the item is starter or maincourse or dessert: ";
                  cin>>c_type;
                  if(c_type=="maincourse"){
                    maincourse m1(l_item,cost,item_type,stoi(stl),stoi(etl));
                    mc.push_back(m1);
                    course[0]=&m1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[0]->course_type()<<" "<< course[0]->availability_lunch()<<" "<<l_item<<'\n';
                  }
                  if(c_type=="dessert"){
                    dessert d1(l_item,cost,item_type,stoi(stl),stoi(etl));
                    dess.push_back(d1);
                    course[1]=&d1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[1]->course_type()<<" "<< course[1]->availability_lunch()<<" "<<l_item<<'\n';
                  }
                  if(c_type=="starter"){
                    starter s1(l_item,cost,item_type,stoi(stl),stoi(etl));
                    stat.push_back(s1);
                    course[2]=&s1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[2]->course_type()<<" "<< course[2]->availability_lunch()<<" "<<l_item<<'\n';
                  }
                  if(c_type!="maincourse" && c_type!="dessert" && c_type!="starter")
                  cout<<"Invalid Input\n";
                  }while(c_type!="maincourse" && c_type!="dessert" && c_type!="starter");
                  Myfile.close();
                  file.close();
                  break;

                }
                case 3:{
                  snacks* course;
                  ifstream Myfile(to_string(regnumber)+".txt");
                  ofstream file(to_string(regnumber)+".txt",ios::app);
                  Myfile>>hotel_type>>hotel_type;
                  if(hotel_type=="Veg")
                  cout<<"Add only Veg Items\n";
                  string s_item;
                  int cost;
                  string item_type;
                  string item_no;
                  string remaining_line;
                  cout<<"Enter the snacks item: ";
                  cin.ignore();
                  getline(cin,s_item);
                  cout<<"Enter cost of the item: ";
                  cin>>cost;
                  if(hotel_type=="NonVeg")
                  {
                  do
                  {
                  cout<<"Enter the item type (Veg or NonVeg) :";
                  cin>>item_type;
                  if(item_type!="Veg" && item_type!="NonVeg")
                  cout<<"Invalid Invalid\n";
                  }while(item_type!="Veg" && item_type!="NonVeg");
                  }
                  else
                  item_type="Veg";
                  while(Myfile >> item_no && getline(Myfile,remaining_line))
                  {
                        count=stoi(item_no);
                  }
                  snacks(s_item,cost,item_type,17,18);
                  file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<"snacks"<<" "<<course->availability_snacks()<<" "<<s_item<<'\n';
                  Myfile.close();
                  file.close();
                  break;

                }
                case 4:{
                  dinner* course[3];
                  ifstream Myfile(to_string(regnumber)+".txt");
                  ofstream file(to_string(regnumber)+".txt",ios::app);
                  Myfile>>hotel_type>>hotel_type;
                  if(hotel_type=="Veg")
                  cout<<"Add only Veg Items\n";
                  string d_item;
                  int cost;
                  string c_type;
                  string item_type;
                  string item_no,std,etd;
                  string remaining_line;
                  cout<<"Enter the dinner item: ";
                  cin.ignore();
                  getline(cin,d_item);
                  cout<<"Enter cost of the item: ";
                  cin>>cost;
                  if(hotel_type=="NonVeg")
                  {
                  do
                  {
                  cout<<"Enter the item type (Veg or NonVeg) :";
                  cin>>item_type;
                  if(item_type!="Veg" && item_type!="NonVeg")
                  cout<<"Invalid Invalid\n";
                  }while(item_type!="Veg" && item_type!="NonVeg");
                  }
                  else
                  item_type="Veg";
                  Myfile>>std>>std>>std>>std>>std>>std>>std>>etd;
                  getline(Myfile,remaining_line);
                  while(Myfile >> item_no && getline(Myfile,remaining_line))
                  {
                        count=stoi(item_no);
                  }
                  do
                  {
                  cout<<"Enter whether the item is starter or maincourse or dessert: ";
                  cin>>c_type;
                  int x=stoi(std),y=stoi(etd);
                  if(c_type=="maincourse"){
                    maincourse m1(d_item,cost,item_type,x,y);
                    mc.push_back(m1);
                    course[0]=&m1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[0]->course_type()<<" "<< course[0]->availability_dinner()<<" "<<d_item<<'\n';
                  }
                  if(c_type=="dessert"){
                    dessert d1(d_item,cost,item_type,stoi(std),stoi(etd));
                    dess.push_back(d1);
                    course[1]=&d1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[1]->course_type()<<" "<< course[0]->availability_dinner()<<" "<<d_item<<'\n';
                  }
                  if(c_type=="starter"){
                    starter s1(d_item,cost,item_type,stoi(std),stoi(etd));
                    stat.push_back(s1);
                    course[2]=&s1;
                    file << to_string(++count)<<" "<<to_string(cost)<<" "<<item_type<<" "<<course[2]->course_type()<<" "<< course[0]->availability_dinner()<<" "<<d_item<<'\n';
                  }
                  if(c_type!="maincourse" && c_type!="dessert" && c_type!="starter")
                  cout<<"Invalid Input\n";
                  }while(c_type!="maincourse" && c_type!="dessert" && c_type!="starter");
                  while(Myfile >> item_no && getline(Myfile,remaining_line))
                  {
                        count=stoi(item_no);
                  }
                  Myfile.close();
                  file.close();
                  break;

                }
                case 5:{
                  string filename=to_string(regnumber)+".txt";
                  ifstream file(to_string(regnumber)+".txt");
                  ofstream tempfile("temp.txt");
                  string item_number;
                  int check=0;
                  string count,remaining_line;
                  string name,password,type;

                  cout<<"Enter the Serial number of dish to be removed in menu: \n";
                  cin>>item_number;
                  file >> name >>password>> type;
                  tempfile<<name<<" "<<password<<" "<<type<<'\n';
                  while (file >> count && getline(file,remaining_line)) {
                        if(count!=item_number)
                        {
                            if(check==0)
                            tempfile<<count<<remaining_line<<'\n';
                            else
                            tempfile<<to_string(stoi(count)-1)<<remaining_line<<'\n';
                        }
                        else
                        check=1;

                  }
                  file.close();
                  tempfile.close();

                  // Replace original file with updated temp file
                  if (check) {
                      remove(filename.c_str());
                      rename("temp.txt", filename.c_str());
                  } else {
                      // Remove temp file if authentication fails
                      remove("temp.txt");
                  }
                  break;

                  
                }
                
                case 0:{
                    break;
                    
                }
                default:
                cout<<"Invalid Input\n";
            }
        }
    }
    else
    cout<< "Your are not an existing user\n";
}

void Existingowner::update_time(Existingowner& o)
{
    string link2="existing_owners.txt";
    bool authresult=authenticate_existing_owner(to_string(regnumber),password,link2);
    if(authresult==true){
    int choice=1;
    string password, type,stb,etb,stl,etl,stsn,etsn,std,etd;
    while(choice)
    {
    cout<<"1. Change Breakfast Time Slot\n"<<"2. Change Lunch Time Slot\n"<<"3.Change Dinner Time Slot\n"<<"0.Exit\n";
    cin>>choice;
    if(choice==1)
    {
        string stb_change,etb_change,line;
        do
        {
        cout<<"Enter the Breakfast Start Time(From 6): ";
        cin>>stb_change;
        cout<<"Enter the Breakfast End Time(till 11): ";
        cin>>etb_change;
        if(stoi(stb_change)<6 || stoi(etb_change)>11)
        cout<<"Invalid Input\n";
        }while(stoi(stb_change)<6 || stoi(etb_change)>11); 
        ifstream Myfile(to_string(regnumber)+".txt");
        ofstream file("temp.txt");
        Myfile>>password>>type>>stb>>etb;
        getline(Myfile,line);
        file<<password<<" "<<type<<" "<<stb_change<<" "<<etb_change<<line<<'\n';
        while(getline(Myfile,line))
        file<<line<<'\n';
        remove((to_string(regnumber)+".txt").c_str());
        rename("temp.txt",(to_string(regnumber)+".txt").c_str());
        Myfile.close();
        file.close();
    }

    else if(choice==2)
    {
        string stl_change,etl_change,line;
        do
        {
        cout<<"Enter the Lunch Start Time(From 11): ";
        cin>>stl_change;
        cout<<"Enter the Lunch End Time(Till 15): ";
        cin>>etl_change;
        if(stoi(stl_change)<11 || stoi(etl_change)>15)
        cout<<"Invalid Input\n";
        }while(stoi(stl_change)<11 || stoi(etl_change)>15);
        ifstream Myfile(to_string(regnumber)+".txt");
        ofstream file("temp.txt");
        Myfile>>password>>type>>stb>>etb>>stl>>etl;
        getline(Myfile,line);
        file<<password<<" "<<type<<" "<<stb<<" "<<etb<<" "<<stl_change<<" "<<etl_change<<line<<'\n';
        while(getline(Myfile,line))
        file<<line<<'\n';
        remove((to_string(regnumber)+".txt").c_str());
        rename("temp.txt",(to_string(regnumber)+".txt").c_str());
        Myfile.close();
        file.close();
    }

    else if(choice==3)
    {
        string std_change,etd_change,line;
        do
        {
        cout<<"Enter the Dinner Start Time(From 18): ";
        cin>>std_change;
        cout<<"Enter the Dinner End Time(Till 23): ";
        cin>>etd_change;
        if(stoi(std_change)<18 || stoi(etd_change)>23)
        cout<<"Invalid Input\n";
        }while(stoi(std_change)<18 || stoi(etd_change)>23);
        ifstream Myfile(to_string(regnumber)+".txt");
        ofstream file("temp.txt");
        Myfile>>password>>type>>stb>>etb>>stl>>etl>>stsn>>etsn>>std>>etd;
        file<<password<<" "<<type<<" "<<stb<<" "<<etb<<" "<<stl<<" "<<etl<<" "<<stsn<<" "<<etsn<<" "<<std_change<<" "<<etd_change;
        while(getline(Myfile,line))
        file<<line<<'\n';
        remove((to_string(regnumber)+".txt").c_str());
        rename("temp.txt",(to_string(regnumber)+".txt").c_str());
        Myfile.close();
        file.close();
    }
    else
    {
    if(choice!=0)
    cout<<"Invalid Input\n";
    }
    }
    }
}

string starter :: course_type()
{
    return "starter";
}

string maincourse :: course_type()
{
    return "maincourse";
}

string dessert :: course_type()
{
    return "dessert";
}

string bf :: availability_bf()
{
    return "breakfast";
}

string lunch :: availability_lunch()
{
    return "lunch";
}

string dinner :: availability_dinner()
{
    return "dinnner";
}

string snacks :: availability_snacks()
{
    return "snacks";
}

string snacks :: course_type(){
    return "snacks";
}

starter :: starter(string iname,int cost,string item_type,int sts,int ets):dinner(iname,cost,item_type,sts,ets),lunch(iname,cost,item_type,sts,ets),item(iname,cost,item_type)
{

}

dessert :: dessert(string iname,int cost,string item_type,int sts,int ets):dinner(iname,cost,item_type,sts,ets),lunch(iname,cost,item_type,sts,ets),item(iname,cost,item_type)
{

}

maincourse :: maincourse(string iname,int cost,string item_type,int sts,int ets):dinner(iname,cost,item_type,sts,ets),lunch(iname,cost,item_type,sts,ets),bf(iname,cost,item_type,sts,ets),item(iname,cost,item_type)
{

}






