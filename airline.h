#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef airline_h
#define airline_h

#ifndef flight_h
#include "flight.h"
#endif

// Declaration of airline class
class airline{
    public:
        //All constructors/destructors
        airline(string name, vector<flight> flights, int total_num);
        airline(const airline& src);
        airline& operator=(const airline& rhs);
        ~airline();
        //Getters and setters
        string get_name()const {return nameM;}
        vector<flight> get_list()const {return flight_listM;}
        int get_num()const {return number_of_flightsM;}
        void set_name(const string new_name) {nameM = new_name;}
        void set_list_item(const flight new_flight, int index) {flight_listM.at(index) = new_flight;}
        void set_num(int num) {number_of_flightsM = num;}
        //Possibly more functions as necessary

    private:
        string nameM;
        vector<flight> flight_listM;
        int number_of_flightsM;
        //Possibly more functions as necessary

};

#endif