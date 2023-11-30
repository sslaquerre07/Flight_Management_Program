#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "flight.h"
using namespace std;

flight::flight(string flightID, int rows, int cols){
    flightIdM = flightID, rowsM = rows, colsM = cols;
    map.resize(rows);
    for(int i = 0; i<rows;i++){
        map.at(i).resize(cols);
    }
    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            map.at(i).at(j) = new seat(i, j, false);
        }
    }
}

flight::flight(const flight& src){
    flightIdM = src.flightIdM, rowsM = src.rowsM, colsM = src.colsM;
    passenger_listM = src.passenger_listM;
    map.resize(rowsM);
    for(int i = 0; i<rowsM;i++){
        map.at(i).resize(colsM);
    }
    for(int i = 0;i<rowsM;i++){
        for(int j=0;j<colsM;j++){
            for(int k=0;k<passenger_listM.size();k++){
                if(passenger_listM.at(k).get_seat()->getrow() == i && passenger_listM.at(k).get_seat()->getcol() == j){
                    map.at(i).at(j) = new seat(i, j, true);
                    break;
                }
            }
            if(map.at(i).at(j) == nullptr)
                map.at(i).at(j) = new seat(i, j, false);
        }
    }
}

flight& flight::operator=(const flight& rhs){
    if(this != &rhs){
        for(int i = 0;i<rhs.rowsM;i++){
            for(int j = 0;j<rhs.colsM;j++){
                delete map.at(i).at(j);
            }
        }
        flightIdM = rhs.flightIdM, rowsM = rhs.rowsM, colsM = rhs.colsM;
        for(int i = 0;i<rowsM;i++){
            for(int j=0;j<colsM;j++){
                for(int k=0;k<passenger_listM.size();k++){
                    if(passenger_listM.at(k).get_seat()->getrow() == i && passenger_listM.at(k).get_seat()->getcol() == j){
                        map.at(i).at(j) = new seat(i, j, true);
                        break;
                    }
                }
                if(map.at(i).at(j) == nullptr)
                    map.at(i).at(j) = new seat(i, j, false);
            }
        }
    }
    return *this;
}

flight::~flight(){
    vector<passenger> empty;
    for(int i = 0;i<rowsM;i++){
        for(int j = 0;j<colsM;j++){
            delete map.at(i).at(j);
        }
    }
    flightIdM = "", rowsM = 0, colsM = 0;
    passenger_listM = empty;
}

void flight::add_passenger(const passenger& pass){
    passenger_listM.push_back(pass);
    map.at(pass.get_seat()->getrow()).at(pass.get_seat()->getcol())->change_status(true);
    return;
}

void flight::remove_passenger(int pos){
    passenger tb_removed = passenger_listM.at(pos);
    map.at(tb_removed.get_seat()->getrow()).at(tb_removed.get_seat()->getcol())->change_status(false);
    passenger_listM.erase(passenger_listM.begin()+pos);
}

int flight::check_passenger(int& id_check){
    for(int i = 0; i<passenger_listM.size();i++){
        int id = passenger_listM.at(i).get_id();
        if(id == id_check){
            return i;
        }  
    }
    return -1;
}
