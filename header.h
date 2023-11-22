#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Still unsure about if this should be a bool type or not
typedef vector<vector<bool>> seatmap;

// Declaration of airline class
class airline{
    public:
        //All constructors/destructors
        airline(string name, vector<flight> flights, int total_num = 0);
        airline(const airline& src);
        airline& operator=(const airline& rhs);
        ~airline();
        //Getters and setters
        const string get_name()const {return name;};
        const vector<flight> get_list()const {return flight_list;};
        const int get_num()const {return number_of_flights;};
        void set_name(const string new_name) {name = new_name;};
        void set_list_item(const flight new_flight, int index) {flight_list.at(index) = new_flight;};
        void set_num(int num) {number_of_flights = num;};
        //Possibly more functions as necessary

    private:
        string name;
        vector<flight> flight_list;
        int number_of_flights;
        //Possibly more functions as necessary

};

// Declaration of flight class
class flight{
    public:
        //All constructors/destructors
        flight(string flightID, int rows, int cols, vector<passenger> list, seatmap map);
        flight(const flight& src);
        flight& operator=(const flight& src);
        ~flight();
        //Getters and setters
        const string get_ID()const {return flightID;};
        const int getrowsM()const {return rowsM;};
        const int getcolsM()const {return colsM;};
        const vector<passenger> get_list()const {return passenger_list;};
        const seatmap get_map()const {return map;};
        void set_ID(const string new_ID) {flightID = new_ID;};
        void setrowsM(const int rows) {rowsM = rows;};
        void setcolsM(const int cols) {colsM = cols;};
        void set_passenger(const passenger new_passenger, int index) {passenger_list.at(index) = new_passenger;};

    private:
        string flightID;
        int rowsM, colsM;
        vector<passenger> passenger_list;
        seatmap map;

};

// Declaration of passenger class
class passenger{
    public:

    private:
    
};

// Declaration of seat class
class seat{
    public:

    private:
    
};