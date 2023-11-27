#include <iostream>
#include <vector>
#include <string>

#ifndef flight_h
#define flight_h

#ifndef passenger_h
#include "passenger.h"
#endif

//Still unsure about if this should be a bool type or not
typedef vector<vector<bool>> seatmap;

// Declaration of flight class
class flight{
    public:
        //All constructors/destructors
        flight(string flightID, int rows, int cols, vector<passenger> list, seatmap map);
        flight(const flight& src);
        flight& operator=(const flight& src);
        ~flight();
        //Getters and setters
        const string get_ID()const {return flightID;}
        const int getrowsM()const {return rowsM;}
        const int getcolsM()const {return colsM;}
        const vector<passenger> get_list()const {return passenger_list;}
        const seatmap get_map()const {return map;}
        void set_ID(const string new_ID) {flightID = new_ID;}
        void setrowsM(const int rows) {rowsM = rows;}
        void setcolsM(const int cols) {colsM = cols;}
        void set_passenger(const passenger new_passenger, int index) {passenger_list.at(index) = new_passenger;}
        //Still unsure what the setter for the seatmap should look like
        //More functions as needed.

    private:
        string flightID;
        int rowsM, colsM;
        vector<passenger> passenger_list;
        seatmap map;

};

#endif