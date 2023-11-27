#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "seat.h"
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