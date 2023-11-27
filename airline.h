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
        airline(string name, vector<flight> flights, int total_num = 0);
        airline(const airline& src);
        airline& operator=(const airline& rhs);
        ~airline();
        //Getters and setters
        string get_name()const {return name;}
        vector<flight> get_list()const {return flight_list;}
        int get_num()const {return number_of_flights;}
        void set_name(const string new_name) {name = new_name;}
        void set_list_item(const flight new_flight, int index) {flight_list.at(index) = new_flight;}
        void set_num(int num) {number_of_flights = num;}
        //Possibly more functions as necessary

    private:
        string name;
        vector<flight> flight_list;
        int number_of_flights;
        //Possibly more functions as necessary

};

#endif