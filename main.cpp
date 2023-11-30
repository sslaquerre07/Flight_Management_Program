#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "main.h"
using namespace std;

int main(){
    //Print the title screen
    print_title();

    //Open and check the file connection
    ifstream data_input("flight_info.txt");
    if(data_input.fail()){
        cout << "file failed to open";
        return 0;
    }

    //Declaration of variables used for creating new objects
    string flight_id, rows, cols, fname, lname, phone, seat, pass_id;

    //Reading the file and created associated objects from the file
    read_header(data_input, flight_id, rows, cols);
    //Initialization of flight should go here
    flight f0(flight_id, stoi(rows), stoi(cols));
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
        passenger new_pass(idI, fname, lname, phone, rowI, colI);
        f0.add_passenger(new_pass);
    }


    //Read the option selection from the user and perform the function accordingly
    string optionS;
    while(1){
        int option;
        menu_display();
        cout << "What task would you like to perform today?: ";
        cin >> optionS;
        //Check for valid option selection
        if(isdigit(optionS.at(0)))
            option = stoi(optionS);
        else{
            cout << "Invalid Option, returning to the main menu ..." << endl << endl;
            continue;
        }
        //Check if the option is a valid integer here.
        if(option == 1){
            //seat_map display function
            display_seatmap(f0.get_map());
        }
        else if(option == 2){
            //Display Passenger Function
            display_info(f0.get_list());
        }
        else if(option == 3){
            //Add Passenger Function
            cout << endl;
            cout << "You have selected to add a new passenger" << endl;
            //Check if it's a valid ID
            int id_check = id_checker();
            if(id_check == 0)
                continue;
            //Checks if the id already exists.
            int id_info = f0.check_passenger(id_check);
            if(id_info != -1){
                cout << "Passenger already exists, please try again";
                continue;
            }
            passenger new_pass;
            //Additional checks still required in this member function on other file
            int flight_rows = stoi(rows), flight_cols = stoi(cols);
            while(1){
                new_pass.add_info(id_check, flight_rows, flight_cols);
                int check = 1;
                for(int i = 0;i<f0.get_list().size();i++){
                    if(new_pass.get_seat()->getrow() == f0.get_list().at(i).get_seat()->getrow() && new_pass.get_seat()->getcol() == f0.get_list().at(i).get_seat()->getcol()){
                        check = 0;
                        break;
                    }
                }
                if(check == 0){
                    cout << "Passenger with this seat already exists, please try again" << endl;
                    continue;
                }
                f0.add_passenger(new_pass);
                break;
            }
        }
        else if(option == 4){
            //Remove data function
            cout << endl;
            cout << "You have selected to remove a passenger" << endl;
            //Checks if user has inputted a valid id to be processed
            int id_check = id_checker();
            if(id_check == 0)
                continue;
            //Checks if valid id is in the database. 
            int id_info = f0.check_passenger(id_check);
            if(id_info == -1){
                cout << "No passenger with this ID found" << endl;
                continue;
            }
            f0.remove_passenger(id_info);
            cout << "Passenger Successfully Erased" << endl;
        }
        else if(option == 5){
            //Save Data Function
            ofstream output("flight_info.txt");
            vector<passenger> list_copy = f0.get_list();
            data_save(output, list_copy, flight_id, rows, cols);
            output.close();
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
int space_remover(ifstream& in_stream){
    int space_count = 0;
    char ch = in_stream.peek();
    while(ch == ' ' || ch == '\n'){
        char consume = in_stream.get();
        ch = in_stream.peek();
        space_count++;
    }
    space_count++;
    return space_count;
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
    int spaces;
    getline(in_stream, fname, ' ');
    spaces = space_remover(in_stream);
    //Checks if a passenger has two first names
    string space(1, ' ');
    if(spaces == 1){
        fname += space;
        string add_name;
        getline(in_stream, add_name, ' ');
        fname+=add_name;
        space_remover(in_stream);
    }
    getline(in_stream, lname, ' ');
    spaces = space_remover(in_stream);
    //Checks if a passenger has two last names
    if(spaces == 1){
        lname += space;
        string add_name;
        getline(in_stream, add_name, ' ');
        lname+=add_name;
        space_remover(in_stream);
    }
    getline(in_stream, phone, ' ');
    space_remover(in_stream);
    getline(in_stream, seat, ' ');
    space_remover(in_stream);
    getline(in_stream, id, '\n');
    space_remover(in_stream);
}

//Checks if id entered by the user is valid for use before insertion/deletion
//RETURNS: 0 if invalid ID, converted ID otherwise.
int id_checker(){
    int id;
    string id_checkS;
    cout << "Please enter passenger id" << endl;
    cin >> id_checkS;
    //Check if it's a valid ID
    int id_bool = 1;
    if(id_checkS.size() == 5){
        for(int i = 0; i<5;i++){
            if(isdigit(id_checkS.at(i)))
                continue;
            else
                id_bool = 0; 
        }
    }
    if(id_bool == 0 || id_checkS.size() != 5){
        cout << "Invalid ID, returning to the main menu ..." << endl << endl;
        return 0;
    }
    id = stoi(id_checkS);
    return id;
}


//Saves data back into the file
void data_save(ofstream& out_stream, vector<passenger>& passenger_list, string& flightid, string& row, string& col){
    out_stream << left << setw(9) << flightid << left << setw(6) << row << left << setw(2) << col << '\n';
    int list_size = passenger_list.size();
    for(int i = 0; i<list_size;i++){
        out_stream << left << setw(20) << passenger_list.at(i).get_fname();
        out_stream << left << setw(20) << passenger_list.at(i).get_lname();
        out_stream << left << setw(20) << passenger_list.at(i).get_phone();
        seat* pass_seat = passenger_list.at(i).get_seat();
        int row = pass_seat->getrow();
        char colC = pass_seat->getcol() + 'A';
        string rowS = to_string(row);
        string colS(1, colC);
        string seatM = rowS+colS;
        out_stream << left << setw(4) << seatM;
        out_stream << left << setw(5) << passenger_list.at(i).get_id() << '\n';
    }
    cout << "Data Successfully Saved. Returning to Main Page\n";
}

//Displays passenger info in a table, will be implemented in the flight class later
void display_info(vector<passenger> passenger_list){
    string line(90, '-');
    cout << "Passenger Information:" << endl << endl;
    cout << left << setw(20) << "First Name";
    cout << left << setw(20) << "Last Name";
    cout << left << setw(20) << "Phone";
    cout << left << setw(10) << "Row";
    cout << left << setw(10) << "Seat";
    cout << left << setw(10) << "ID" << endl;
    cout << line << endl;
    for(int i=0;i<passenger_list.size();i++){
        cout << left << setw(20) << passenger_list.at(i).get_fname();
        cout << left << setw(20) << passenger_list.at(i).get_lname();
        cout << left << setw(20) << passenger_list.at(i).get_phone();
        int row = passenger_list.at(i).get_seat()->getrow(), col = passenger_list.at(i).get_seat()->getcol();
        char colC = col + 'A';
        cout << left << setw(10) << row;
        cout << left << setw(10) << colC;
        cout << left << setw(10) << passenger_list.at(i).get_id() << endl;
        cout << line << endl;
    }
}

void printGrid(const vector<vector<char>>& grid) {
    int rowLabelWidth = to_string(grid.size()).size() + 1;
    int columnLabelWidth = 3; // Width for each column label

    // Print column labels (alphabetical)
    cout << setw(rowLabelWidth) << " ";
    for (char c = 'A'; c < 'A' + grid[0].size(); ++c) {
        cout << setw(columnLabelWidth) << c << " ";
    }
    cout << endl;

    int rowNum = 1;
    for (const auto& row : grid) {
        int halfSpaces = (rowLabelWidth - to_string(rowNum).size()) / 2;
        cout << string(halfSpaces, ' '); // Center row number
        cout << setw(rowLabelWidth - halfSpaces) << rowNum++ << " "; // Print row label
        for (char cell : row) {
            cout << "+---";
        }
        cout << "+" << endl;

        cout << setw(rowLabelWidth) << " ";
        for (char cell : row) {
            cout << "| " << cell << " ";
        }
        cout << "|" << endl;
    }

    cout << setw(rowLabelWidth) << " ";
    for (size_t i = 0; i < grid[0].size(); ++i) {
        cout << "+---";
    }
    cout << "+" << endl;
}

void display_seatmap(const seatmap map){

    vector<vector<char>> grid(map.size(), vector<char>(map[0].size(), ' '));

    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            if (map[i][j]->getstatus() == true) {
                grid[i-1][j] = 'X';
            }
        }
    }
    
    cout << "\tAircraft Seat Map" << endl;
    printGrid(grid);
}