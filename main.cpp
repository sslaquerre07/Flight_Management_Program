#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include "header.h"
using namespace std;

void print_title();
void menu_display();
void space_remover(ifstream& in_stream);
void read_header(ifstream& in_stream, string& flightid, string& rows, string& cols);
void read_passenger(ifstream& in_stream, string& fname, string& lname, string& phone, string& seat, string& id);

int main(){
    //Print the title screen
    print_title();

    //Open and check the file connection
    ifstream data_input("input.txt");
    if(data_input.fail()){
        cout << "file failed to open";
        return 0;
    }

    //Declaration of variables used for creating new objects
    string flight_id, rows, cols, fname, lname, phone, seat, pass_id;
    vector<passenger> passenger_list;

    //Reading the file and created associated objects from the file
    read_header(data_input, flight_id, rows, cols);
    //Initialization of flight should go here
    while(!data_input.eof()){
        read_passenger(data_input, fname, lname, phone, seat, pass_id);
        //Manipulate the data to fit the parameters
        int idI = stoi(pass_id);
        int rowI, colI;
        int seat_size = seat.length();
        //Accounts for different seat formatting, up to double digit rows
        if(seat_size > 2){
            rowI = stoi(seat.substr(0,2));
            colI = seat.at(2)-'A';
        }
        else{
            rowI = seat.at(0)-'0';
            colI = seat.at(1)-'A';
        }
        passenger_list.push_back(passenger(idI, fname, lname, phone, rowI, colI));
    }


    //Read the option selection from the user and perform the function accordingly
    int option = 0;
    while(1){
        menu_display();
        cout << "What task would you like to perform today?: ";
        cin >> option;
        //Check if the option is a valid integer here.
        if(option == 1){
            //seat_map display function
        }
        else if(option == 2){
            //Display Passenger Function
        }
        else if(option == 3){
            //Add Passenger Function
            cout << endl;
            int id_check;
            int id_bool = 0;
            cout << "Please enter passenger id" << endl;
            cin >> id_check;
            //Checks if the id already exists.
            for(int i = 0; i<passenger_list.size();i++){
                if(passenger_list.at(i).get_id() == id_check){
                    cout << "Passenger already exists, cannot be added" << endl;
                    id_bool = 1;
                    break;
                }  
            }
            if(id_bool == 1)
                continue;
            passenger new_pass;
            //Additional checks still required in this member function on other file
            new_pass.add_info(id_check);
            passenger_list.push_back(new_pass);
            cout << new_pass.get_fname() << endl;
        }
        else if(option == 4){
            //Remove data function
        }
        else if(option == 5){
            //Save Data Function
        }
        else if(option == 6){
            cout << "Goodbye";
            break;
        }
        else{
            cout << "Invalid option selection, please pick another, or 6 to quit" << endl;
        }
    }
}



//All general function implementations here
void print_title(){
    cout << endl;
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced By: Sam Laquerre, Amielle El Makhzoumi" << endl;
    cout << "Year: 2023" << endl;
}

void menu_display(){
    cout << endl;
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passenger Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove an Existing Passenger" << endl;
    cout << "5. Save data" << endl;
    cout << "6. Quit" << endl;
}

//Acts as a buffer for the file
void space_remover(ifstream& in_stream){
    char ch = in_stream.peek();
    while(ch == ' ' || ch == '\n'){
        char consume = in_stream.get();
        ch = in_stream.peek();
    }
    return;
}

//Reads the top line of the file
void read_header(ifstream& in_stream, string& flightid, string& rows, string& cols){
    getline(in_stream, flightid, ' ');
    space_remover(in_stream);
    getline(in_stream, rows, ' ');
    space_remover(in_stream);
    getline(in_stream, cols, '\n');
    space_remover(in_stream);
}

// Gets all passenger information from the file
void read_passenger(ifstream& in_stream, string& fname, string& lname, string& phone, string& seat, string& id){
    getline(in_stream, fname, ' ');
    space_remover(in_stream);
    getline(in_stream, lname, ' ');
    space_remover(in_stream);
    getline(in_stream, phone, ' ');
    space_remover(in_stream);
    getline(in_stream, seat, ' ');
    space_remover(in_stream);
    getline(in_stream, id, '\n');
    space_remover(in_stream);
}