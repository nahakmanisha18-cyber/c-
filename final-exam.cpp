#include <iostream>
#include <string>
using namespace std;

//program : 1
//================ Movie Class ================
class Movie {
   public:
    string title;
    string genre;
    int releasedYear;
};

//================ Bank Account ================
class BankAccount {
private:
    int accountNumber;
    double balance;
    string ownerName;

   public:
	
    // Setter functions
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposit successfully.\n";
    }
    
    //program :2


    // Credit function (add money)
    void credit(double amount) {
        balance += amount;
        cout << "Amount credited successfully.\n";
    }

    // Debit function (withdraw money)
    void debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount debited successfully.\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    // Display balance
    void displayBalance() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

//program : 3
//================ Base Class: Vehicle ================
class Vehicle{
	string model; 
	int speed;
	
   public:
   	
	void setModel(string m) {
        model = m;
    }

    void setSpeed(double s) {
        speed = s;
    }

    // Getters
    string getModel() {
        return model;
    }

    double getSpeed() {
        return speed;
    }
    
    virtual double calculateTime(double distance) = 0;
    //program:4
    virtual void displayDetails() = 0;
};

// ---------- Derived Class: Car ----------
class Car : public Vehicle {
    public:
    	
    double calculateTime(double distance) {
        return distance / getSpeed();
    }
    
    //program:4
    void displayDetails() {
        cout << "Vehicle Type: Car\n";
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/hr\n\n";
    }
};

// ---------- Derived Class: Bike ----------
class Bike : public Vehicle {
    public:
    	
    double calculateTime(double distance) {
        return distance / getSpeed();
    }
    
    //program:4
    void displayDetails() {
        cout << "Vehicle Type: Bike\n";
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/hr\n\n";
    }
    
};

//program : 5
//================ Base Class: Shape ================
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual
    virtual void draw() = 0;            // Pure virtual
};

// ---------- Derived Class: Circle ----------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double calculateArea() {
        return 3.14 * radius * radius;
    }

    void draw() {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};


// ---------- Derived Class: Rectangle ----------
// ---------- Derived Class: Rectangle ----------
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double len, double wid) {
        length = len;
        width = wid;
    }

    double calculateArea() override {
        return length * width;
    }

    void draw() override {
        cout << "Drawing a Rectangle with length "
             << length << " and width " << width << endl;
    }
};

int main() {
	cout<<"======= Program:1 ======="<<endl;
    // Array of Movie objects
    Movie movies[3];

    // Object 1
    movies[0].title = "3 Idiots";
    movies[0].genre = "Comedy/Drama";
    movies[0].releasedYear = 2009;

    // Object 2
    movies[1].title = "Bahubali";
    movies[1].genre = "Action";
    movies[1].releasedYear = 2015;

    // Object 3
    movies[2].title = "Dangal";
    movies[2].genre = "Sports Drama";
    movies[2].releasedYear = 2016;

    // Accessing and displaying data
    for(int i = 0; i < 3; i++) {
        cout << "\nMovie " << i + 1 << endl;
        cout << "Title: " << movies[i].title << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << "Release Year: " << movies[i].releasedYear << endl;
    }

    cout<<"\n";
    
    BankAccount acc1(101, "Manisha", 5000);

    acc1.displayBalance();
    acc1.deposit(2000); 
    
    //program : 2
    cout<<"======= Program:2 ======="<<endl;
    acc1.credit(2000);
    acc1.debit(1500);
    acc1.displayBalance();
   
     cout<<"\n";
    //program : 3
    Vehicle* v1;
    Vehicle* v2;

    Car car;
    Bike bike;

    car.setModel("Honda City");
    car.setSpeed(60);   

    bike.setModel("Yamaha");
    bike.setSpeed(40);  

    v1 = &car;
    v2 = &bike;

    double distance = 120; 
    
    cout<<"======= Program:3 ======="<<endl;
    cout << "Car Time: " << v1->calculateTime(distance) << " hours\n";
    cout << "Bike Time: " << v2->calculateTime(distance) << " hours\n";
    
    cout<<"\n";
    //program :4 
    cout<<"======= Program:4 ======="<<endl;
    Vehicle* vehicles[2];
    vehicles[0] = &car;
    vehicles[1] = &bike;

    // Polymorphism demonstration
    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();
    }
    
    cout<<"\n";
    //program :5
    cout<<"======= Program:5 ======="<<endl;
    Shape* shapes[2];

    Circle c(5);
    Rectangle r(4, 6);

    shapes[0] = &c;
    shapes[1] = &r;

    // Polymorphism demonstration
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl << endl;
    }
}

/*
output:
======= Program:1 =======

Movie 1
Title: 3 Idiots
Genre: Comedy/Drama
Release Year: 2009

Movie 2
Title: Bahubali
Genre: Action
Release Year: 2015

Movie 3
Title: Dangal
Genre: Sports Drama
Release Year: 2016


Account Number: 101
Owner Name: Manisha
Current Balance: 5000
Amount deposit successfully.
======= Program:2 =======
Amount credited successfully.
Amount debited successfully.

Account Number: 101
Owner Name: Manisha
Current Balance: 7500

======= Program:3 =======
Car Time: 2 hours
Bike Time: 3 hours

======= Program:4 =======
Vehicle Type: Car
Model: Honda City
Speed: 60 km/hr

Vehicle Type: Bike
Model: Yamaha
Speed: 40 km/hr


======= Program:5 =======
Drawing a Circle with radius 5
Area: 78.5

Drawing a Rectangle with length 4 and width 6
Area: 24

 */




