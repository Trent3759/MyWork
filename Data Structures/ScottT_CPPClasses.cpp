/*
 Name: Trent Scott
 Date: 02/11/16
 Description: Vehicle class.
 
 This program is intended to test setting up classes in C++
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;



class Vehicle {
public:
    Vehicle();  //Default constructor
    Vehicle(string make, string model, int year,
            bool manual);//default constructor for Vehicle
    ~Vehicle();  //destructor
    
    //getters
    string get_make();
    string get_model();
    int get_year();
    bool get_manual();
    
    //setters
    void set_make(string x);
    string set_model();
    int set_year();
    bool set_manual();
    void rebuild(string make, string model, int year, bool manual);
    void revert();
    
    bool operator== (const Vehicle& rhs) const;  //Overload for ==
    friend ostream& operator<< (ostream& out, const Vehicle& p);
    
private:
    string make;
    string old_make;
    string model;
    string old_model;
    int year;
    int old_year;
    bool manual;
    bool old_manual;
};
//default constructor
Vehicle::Vehicle() {
    make = "default";
    old_make = make;
    model = "default";
    old_model = model;
    year = 2015;
    old_year = year;
    manual = false;
    old_manual = manual;
    
    }
//'Vehicle' constructor;
Vehicle::Vehicle(string make, string model, int year, bool manual){
    make = make;
    old_make = make;
    model = model;
    old_model = model;
    year = year;
    old_year = year;
    manual = manual;
    old_manual = manual;
    
}

//destructor
Vehicle::~Vehicle(){}

/*
	Class Methods
 */

void Vehicle::rebuild(string make, string model, int year, bool manual){
    make = make;
    model = model;
    year = year;
    manual = manual;
}

void Vehicle::revert(){
    make = old_make;
    model = old_model;
    year = old_year;
    manual = old_manual;
    
}


string Vehicle::get_make(){
    return make;
}
string Vehicle::get_model(){
    return model;
}
int Vehicle::get_year(){
    return year;
}
bool Vehicle::get_manual(){
    return manual;
}
void Vehicle::set_make(string x){
    make = x;
}
//overload for == operator
bool Vehicle::operator== (const Vehicle& rhs) const {
    if ((make == rhs.make) && (model == rhs.model && year == rhs.year &&
                               manual == rhs.manual))
        return true;
    else
        return false;
}
//overload for << operator
ostream& operator<< (ostream& ost, const Vehicle& v) {
    cout << v.year << " " << v.make << " " << v.model << " "
    << ((v.manual)? ", Manual Transmission" : ", Automatic Transmission");
    return ost;
}

int main(){
    if (true)
        cout << "It works";
        cout << "It works!";
    
    
    

}