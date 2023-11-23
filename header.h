#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Still unsure about if this should be a bool type or not
typedef vector<vector<bool>> seatmap;

// Declaration of seat class
class seat{
    public:
        //All constructors/destructors
        seat(int rowM, int colM, bool status);
        seat(const seat& src);
        seat& operator=(const seat& src);
        ~seat();
        //Getters and setters
        const int getrow()const {return rowM;}
        const int getcol()const {return colM;}
        const bool getstatus()const {return status;}
        void set_row(const int new_row) {rowM = new_row;}
        void set_col(const int new_col) {colM = new_col;}
        void change_status(const bool new_status) {status = new_status;}
        //More functions as needed.

    private:
        int rowM, colM;
        bool status;
};

// Declaration of passenger class
class passenger{
    public:
        //All constructors/destructors
        passenger(int id, string fname, string lname, seat* number);
        passenger(const passenger& src);
        passenger& operator=(const passenger& rhs);
        ~passenger();
        //Getters and setters
        const int get_id()const {return passengerid;}
        const string get_fname()const {return fname;}
        const string get_lname()const {return lname;}
        const string get_phone()const {return phone;}
        const seat* get_seat()const {return seat_number;}
        void set_id(const int new_id) {passengerid = new_id;}
        void set_name(const string* name) {fname = name[0], lname = name[1];}
        void set_num(const string number) {phone = number;}
        //More functions as needed.

    private:
        int passengerid;
        string fname, lname, phone;
        seat* seat_number;
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
        const string get_ID()const {return flightID;}
        const int getrowsM()const {return rowsM;}
        const int getcolsM()const {return colsM;}
        const vector<passenger> get_list()const {return passenger_list;}
        const seatmap get_map()const {return map;}
        void set_ID(const string new_ID) {flightID = new_ID;}
        void setrowsM(const int rows) {rowsM = rows;}
        void setcolsM(const int cols) {colsM = cols;}
        void set_passenger(const passenger new_passenger, int index) {passenger_list.at(index) = new_passenger;}
        //Still unsure what the setter for the seatmap should look like
        //More functions as needed.

    private:
        string flightID;
        int rowsM, colsM;
        vector<passenger> passenger_list;
        seatmap map;

};

// Declaration of airline class
class airline{
    public:
        //All constructors/destructors
        airline(string name, vector<flight> flights, int total_num = 0);
        airline(const airline& src);
        airline& operator=(const airline& rhs);
        ~airline();
        //Getters and setters
        const string get_name()const {return name;}
        const vector<flight> get_list()const {return flight_list;}
        const int get_num()const {return number_of_flights;}
        void set_name(const string new_name) {name = new_name;}
        void set_list_item(const flight new_flight, int index) {flight_list.at(index) = new_flight;}
        void set_num(int num) {number_of_flights = num;}
        //Possibly more functions as necessary

    private:
        string name;
        vector<flight> flight_list;
        int number_of_flights;
        //Possibly more functions as necessary

};

//Function prototypes of additional functions
void print_title();