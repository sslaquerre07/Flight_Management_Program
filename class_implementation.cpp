#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "header.h"
using namespace std;

//Seat Implementation
seat::seat(){
    rowM = 0;
    colM = 0;
    statusM = false;
}

seat::seat(int row, int col, bool status){
    rowM = row;
    colM = col;
    statusM = status;
}

seat::seat(const seat& src){
    rowM = src.rowM;
    colM = src.colM;
    statusM = src.statusM;
}

seat& seat::operator=(const seat& rhs){
    if(this != &rhs){
        rowM = rhs.rowM;
        colM = rhs.colM;
        statusM = rhs.statusM;
    }
    return *this;
}

seat::~seat(){
    rowM = 0;
    colM = 0;
    statusM = false;
}


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