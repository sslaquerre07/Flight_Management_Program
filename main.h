#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef main_h
#define main_h

#ifndef airline_h
#include "airline.h"
#endif

void print_title();
void menu_display();
int space_remover(ifstream& in_stream);
void read_header(ifstream& in_stream, string& flightid, string& rows, string& cols);
void read_passenger(ifstream& in_stream, string& fname, string& lname, string& phone, string& seat, string& id);
//Should be implemented in the flight class, but good enough for now.
int check_passenger(vector<passenger>& passenger_list, int& id_check);
int id_checker();
//To be fully implemented once flight has been defined.
void data_save(ofstream& out_stream, vector<passenger>& passenger_list, string& flightid, string& row, string& col);
//Should also be implemented in the flight class, but will work for now
void display_info(vector<passenger> passenger_list);

#endif