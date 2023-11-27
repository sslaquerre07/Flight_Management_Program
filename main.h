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
//To be implemented once flight has been defined.
void save_data(ofstream out_stream, flight flight_info, vector<passenger> passenger_list);
int id_checker();

#endif