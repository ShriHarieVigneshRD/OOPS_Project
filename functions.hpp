// functions.hpp
#include <iostream>
#include <fstream>
#include "newowner.hpp"
using namespace std;
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
/*
bool authenticate_new_owner(const string& regNumber, const string& password, const string& filename,string& filename2) {
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    bool isAuthenticated = false;
    ofstream existing_owner(filename2);
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
        cout<<"Enter your desired hotel name";
        getline(cin,hotelname);
        char t;
        cout<<"Enter the hotel type";
        cin>>t;
        Newowner n1(hotelname,t,registration_number,pass);
        n1.setmenu();
    }
}*/
bool authenticate_new_owner(const string& arg1, const string& arg2, const string& arg3, string& arg4);
bool authenticate_existing_owner(const string& arg1, const string& arg2, const string& arg3);
void assign_new_owner();
#endif // FUNCTIONS_HPP
