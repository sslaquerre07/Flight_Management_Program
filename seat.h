#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef seat_h
#define seat_h

// Declaration of seat class
class seat{
    public:
        //All constructors/destructors
        seat();
        seat(int row, int col, bool status);
        seat(const seat& src);
        seat& operator=(const seat& rhs);
        ~seat();
        //Getters and setters
        int getrow()const {return rowM;}
        int getcol()const {return colM;}
        bool getstatus()const {return statusM;}
        void set_row(const int new_row) {rowM = new_row;}
        void set_col(const int new_col) {colM = new_col;}
        void change_status(const bool new_status) {statusM = new_status;}
        //More functions as needed.

    private:
        int rowM, colM;
        bool statusM;
};

#endif