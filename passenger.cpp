#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "passenger.h"
#include "seat.h"
using namespace std;

//Passenger Implementation
passenger::passenger(){
    seat_numberM = nullptr;
    passengerid = 0;
    fnameM = "", lnameM = "", phoneM = "";
}

passenger::passenger(int id, string fname, string lname, string phone, int row, int column){
    passengerid = id;
    fnameM = fname, lnameM = lname, phoneM = phone;
    seat_numberM = new seat(row, column, true);
}

passenger::passenger(const passenger& src){
    passengerid = src.passengerid;
    fnameM = src.fnameM, lnameM = src.lnameM, phoneM = src.phoneM;
    seat_numberM = new seat(src.seat_numberM->getrow(), src.seat_numberM->getcol(), true);
}

passenger& passenger::operator=(const passenger& rhs){
    if(this != &rhs){
        delete seat_numberM;
        passengerid = rhs.passengerid;
        fnameM = rhs.fnameM, lnameM = rhs.lnameM, phoneM = rhs.phoneM;
        seat_numberM = new seat(rhs.seat_numberM->getrow(), rhs.seat_numberM->getcol(), true);
    }
    return *this;    
}

passenger::~passenger(){
    seat_numberM = nullptr;
    passengerid = 0;
    fnameM = "", lnameM = "", phoneM = "";
}

void passenger::add_info(int& id){
    string row, col;
    passengerid = id;
    cout << "Please enter the passenger first name: ";
    cin >> fnameM;
    cout << "Please enter the passenger last name: ";
    cin >> lnameM;
    cout << "Please enter the passenger phone number with the following format(xxx-xxx-xxxx): ";
    cin >> phoneM;
    cout << endl;
    //Possibly have to consider a valid seat #??
    cout << "Enter the passenger's desired row: ";
    cin >> row;
    cout << "Enter the passenger's desired seat: ";
    cin >> col;
    int colI = col.at(0) - 'A';
    seat_numberM = new seat(stoi(row), colI, true);
    return;    
    
}