#include <iostream>
#include <vector>
#include <string>

#ifndef passenger_h
#define passenger_h

#ifndef seat_h
#include "seat.h"
#endif

// Declaration of passenger class
class passenger{
    public:
        //All constructors/destructors
        passenger();
        passenger(int id, string fname, string lname, string phone, int row, int column);
        passenger(const passenger& src);
        passenger& operator=(const passenger& rhs);
        ~passenger();
        //Getters and setters
        int get_id()const {return passengerid;}
        string get_fname()const {return fnameM;}
        string get_lname()const {return lnameM;}
        string get_phone()const {return phoneM;}
        seat* get_seat()const {return seat_numberM;}
        void set_id(const int new_id) {passengerid = new_id;}
        void set_name(const string* name) {fnameM = name[0], lnameM = name[1];}
        void set_num(const string number) {phoneM = number;}
        //More functions as needed.
        void read_passenger(ifstream& in_stream, passenger& new_pass);
        void add_info(int& id, int& rows, int& cols);

    private:
        int passengerid;
        string fnameM, lnameM, phoneM;
        seat* seat_numberM;
};

#endif