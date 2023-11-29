#include <iostream>
#include <vector>
#include <string>

#ifndef flight_h
#define flight_h

#ifndef passenger_h
#include "passenger.h"
#endif

//Still unsure about if this should be a bool type or not
typedef vector<vector<seat*>> seatmap;

// Declaration of flight class
class flight{
    public:
        //All constructors/destructors
        flight(string flightID, int rows, int cols);
        flight(const flight& src);
        flight& operator=(const flight& src);
        ~flight();
        //Getters and setters
        string get_ID()const {return flightIdM;}
        int getrowsM()const {return rowsM;}
        int getcolsM()const {return colsM;}
        vector<passenger> get_list()const {return passenger_listM;}
        seatmap get_map()const {return map;}
        void set_ID(const string new_ID) {flightIdM = new_ID;}
        void setrowsM(const int rows) {rowsM = rows;}
        void setcolsM(const int cols) {colsM = cols;}
        void set_passenger(const passenger new_passenger, int index) {passenger_listM.at(index) = new_passenger;}
        //Still unsure what the setter for the seatmap should look like
        //More functions as needed.
        void add_passenger(const passenger& pass);
        void remove_passenger(int pos);
        int check_passenger(int& id_check);

    private:
        string flightIdM;
        int rowsM, colsM;
        vector<passenger> passenger_listM;
        seatmap map;

};

#endif