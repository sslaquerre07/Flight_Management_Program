#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "header.h"
using namespace std;

int main(){
    print_title();
    //Read text file provided with info and assign accordingly
    int option = 0;
    while(1){
        //Menu display function
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