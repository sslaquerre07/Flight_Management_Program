#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "airline.h"
using namespace std;

airline::airline(string name, vector<flight> flights, int total_num = 0){
    nameM = name;
    flight_listM = flights;
    number_of_flightsM = total_num;
}

airline::airline(const airline& src){
    nameM = src.nameM;
    flight_listM = src.flight_listM;
    number_of_flightsM = src.number_of_flightsM;
}

airline& airline::operator=(const airline& rhs){
    if(this != &rhs) {
        nameM = rhs.nameM;
        flight_listM = rhs.flight_listM;
        number_of_flightsM = rhs.number_of_flightsM;
    }
    return *this;
}

airline::~airline(){
    int number_of_flights = 0;
    nameM.clear();
    flight_listM.clear();
}

