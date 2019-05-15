/*
 Name: Trent Scott
 Date: 02/11/16
 Description: Vehicle class extended to include inheritance. 
 
 This program is intended to demonstrate inheritance through
 in c++
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
    Vehicle( const Vehicle &obj);  // copy constructor
    ~Vehicle();  //destructor

    
    //getters
    string get_make();
    string get_model();
    int get_year();
    bool get_manual();
    virtual string isGas(){
        return "Dont know. Vehicles can be anything these days. ";
    }
    
    //setters
    void set_make(string inputMake);
    void set_model(string inputModel);
    void set_year(int inputYear);
    void set_manual(bool inputManual);
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
    cout << "\n\t***Default Vehicle Constructor Called***\n";
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
Vehicle::Vehicle(string carMake, string carModel, int carYear, bool isManual){
    cout << "\n\t***Variable Vehicle Constructor Called***\n";
    make = carMake;
    old_make = make;
    model = carModel;
    old_model = model;
    year = carYear;
    old_year = year;
    manual = isManual;
    old_manual = manual;
}

//destructor
Vehicle::~Vehicle(){
    cout << "\n\t***Vehicle Destructor Called***\n";
}

//copy constructor
Vehicle::Vehicle (const Vehicle& vhcl) {
    make = vhcl.make;
    model = vhcl.model;
    year = vhcl.year;
    manual = vhcl.manual;
}



/*
	Class Methods
 */

void Vehicle::rebuild(string carMake, string carModel, int carYear, bool isManual){
    make = carMake;
    model = carModel;
    year = carYear;
    manual = isManual;
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

void Vehicle::set_make(string inputMake){
    make = inputMake;
}
void Vehicle::set_model(string inputModel){
    model = inputModel;
}
void Vehicle::set_year(int inputYear){
    year = inputYear;
}
void Vehicle::set_manual(bool inputManual){
    manual = inputManual;
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


class SUV: public Vehicle {
public:
    SUV();
    SUV(string make, string model, int year,
        bool manual, int numOfSeats, bool isFourWheelDrive);
     bool is4X4();
    int numOfSeats();
    string isGas(){
        return "Yup. SUV's love gas!";
    }
    ~SUV();//destructor
private:
    int seats;
    bool fourWheelDrive = true;
};

//suv default constructor
SUV::SUV(){
    cout << "\n\t***Default SUV Constructor Called***\n";
    seats = 5;
    fourWheelDrive = true;
}


//suv constructor
SUV::SUV(string make, string model, int year, bool manual,
         int numOfSeats, bool isFourWheelDrive):Vehicle(make, model, year, manual){
    cout << "\n\t***Variable SUV Constructor Called***\n";
    seats = numOfSeats;
    fourWheelDrive = isFourWheelDrive;
}
bool SUV::is4X4(){
    return fourWheelDrive;
}

int SUV::numOfSeats(){
    return seats;
}

SUV::~SUV(){
    cout << "\n\t***SUV Destructor Called***\n";
};


int main(){
    Vehicle car2;
    car2.set_make("Ford");
    Vehicle car1(car2);
    
    cout << car1.get_make() << "\n-------------\n\n";
    
    
    SUV suv1;
    
    cout << (suv1.is4X4() ? "4X4 |" : "Not 4X4") << " # of seats: " << suv1.numOfSeats() << " | " << suv1.get_make();
    
    cout << "\n\n";
    
    SUV* suv2 = new SUV("Ford", "Freestyle", 2007, false, 8, true);
    
    cout << (suv2->is4X4() ? "4X4 |" : "Not 4X4 |") << " # of seats: " << suv2->numOfSeats() << " | " << suv2->get_make();
    
    cout << "\n-----------------\n";
    cout << "Is car2 gas?: " << car2.isGas() << "\n";
    //object.isGas() is used instead of object->isGas() b/c of the way they are declared.
    cout << "Is suv2 gas?: " << suv2->isGas() << "\n";
    
    //tested destructors by commented out getchar() code to allow to program to exit.
    
    getchar(); //pause output
    return 0; //return success;
    
}