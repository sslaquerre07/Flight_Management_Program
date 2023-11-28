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

void passenger::add_info(int& id, int& rows, int& cols){
    string row, col;
    passengerid = id;
    cin.ignore(1, '\n');
    cout << "Please enter the passenger first name: ";
    getline(cin, fnameM);
    cout << "Please enter the passenger last name: ";
    getline(cin, lnameM);
    //Check for a valid phone number
    while(1){
        cout << "Please enter the passenger phone number with the following format(xxx-xxx-xxxx): ";
        int check = 1;
        getline(cin, phoneM);
        if(phoneM.size() == 12){
            for(int i = 0; i<12;i++){
                if(i == 3 || i == 7){
                    if(phoneM.at(i) == '-')
                        continue;
                    else{
                        check = 0;
                        break;
                    }
                }
                else{
                    if(isdigit(phoneM.at(i)))
                        continue;
                    else{
                        check = 0;
                        break;
                    }
                }
            }
        }
        else
            check = 0;
        if(check == 1)
            break;
        cout << "Invalid number entered, please try again" << endl;
    }
    cout << endl;
    //Possibly have to consider a valid seat #??
    while(1){
        int check = 1;
        cout << "Enter the passenger's desired row: ";
        cin >> row;
        for(int i = 0; i<row.size();i++){
            if(isdigit(row.at(i)))
                continue;
            else{
                check = 0;
                break;
            }
        }
        if(check == 0){
            cout << "Invalid row, please try again" << endl;
            continue;
        }
        if(stoi(row) <= 0 || stoi(row) > rows)
            check = 0;
        if(check == 0){
            cout << "Invalid row, please try again" << endl;
            continue;
        }
        break;
    }
    //Check for valid column
    int colI;
    while(1){
        int check = 1;
        cout << "Enter the passenger's desired column: ";
        cin >> col;
        char max_col = cols + 'A' - 1;
        string max_colS(1, max_col);
        if(col < "A" || col > max_colS)
            check = 0;
        if(check == 0){
            cout << "Invalid row, please try again" << endl;
            continue;
        }
        colI = col.at(0) - 'A';
        break;
    }
    seat_numberM = new seat(stoi(row), colI, true);
    return;    
    
}