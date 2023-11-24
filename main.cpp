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
passenger create_passenger(ifstream& in_stream, string& fname, string& lname, string& phone, string& seat, string& id);

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
    vector<passenger> passenger_list(8);
    

    //Reading the file and created associated objects from the file
    read_header(data_input, flight_id, rows, cols);
    #if 1
    while(!data_input.eof()){
        passenger_list.push_back(create_passenger(data_input, fname, lname, phone, seat, pass_id));
    }
    #endif


    //Read the option selection from the user and perform the function accordingly
    int option = 0;
    while(1){
        menu_display();
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
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced By: Sam Laquerre, Amielle El Makhzoumi" << endl;
    cout << "Year: 2023" << endl;
}

void menu_display(){
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
    while(ch == ' ' || ch == '\n' || ch == EOF){
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
    getline(in_stream, cols, ' ');
    space_remover(in_stream);
}



// Gets all passenger information from the file
passenger create_passenger(ifstream& in_stream, string& fname, string& lname, string& phone, string& seat, string& id){
    getline(in_stream, fname, ' ');
    space_remover(in_stream);
    getline(in_stream, lname, ' ');
    space_remover(in_stream);
    getline(in_stream, phone, ' ');
    space_remover(in_stream);
    //Some special consideration taken for the seat
    getline(in_stream, seat, ' ');
    int row, col;
    if(seat.at(1) >= '0' && seat.at(1) <= '9'){
        string rowS = seat.substr(0,2);
        char colS = seat.at(2);
        row = stoi(rowS);
        col = colS -'A';
    }
    else{
        char rowS = seat.at(0);
        char colS = seat.at(1);
        int row = rowS -'0';
        int col = colS - 'A';
    }
    space_remover(in_stream);
    getline(in_stream, id, ' ');
    //More consideration for id
    int idI = stoi(id);
    space_remover(in_stream);
    passenger new_pass(idI, fname, lname, phone, row, col);
}