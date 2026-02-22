#include <iostream>
#include <cstring>
using namespace std;

/* =============== Base Class : Vehicle =============== */
class Vehicle {
private:
    int vehicleID;
    char manufacturer[30];
    char model[30];
    int year;

public:
    static int totalVehicles;

    Vehicle() {
        vehicleID = 0;
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, const char* man, const char* mod, int y) {
        vehicleID = id;
        strcpy(manufacturer, man);
        strcpy(model, mod);
        year = y;
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    int getVehicleID() {
        return vehicleID;
    }

    virtual void display() {
        cout << "Vehicle ID   : " << vehicleID << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model        : " << model << endl;
        cout << "Year         : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

/* =============== Car : Single Inheritance =============== */
class Car : public Vehicle {
private:
    char fuelType[20];

public:
    Car(int id, const char* man, const char* mod, int y, const char* fuel): Vehicle(id, man, mod, y) 
	{
        strcpy(fuelType, fuel);
    }

    void display() {
        Vehicle::display();
        cout << "Fuel Type    : " << fuelType << endl;
    }
};

/* =============== ElectricCar : Multilevel =============== */
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(int id, const char* man, const char* mod, int y,const char* fuel, int battery) : Car(id, man, mod, y, fuel) 
	{
        batteryCapacity = battery;
    }

    void display() {
        Car::display();
        cout << "Battery (kWh): " << batteryCapacity << endl;
    }
};

/* =============== SportsCar : Multilevel =============== */
class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar(int id, const char* man, const char* mod, int y,const char* fuel, int battery, int speed) : ElectricCar(id, man, mod, y, fuel, battery) 
	{
        topSpeed = speed;
    }

    void display() {
        ElectricCar::display();
        cout << "Top Speed    : " << topSpeed << " km/h" << endl;
    }
};

/*=============== VehicleRegistry =============== */
class VehicleRegistry {
private:
    Vehicle* vehicles[50];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }

    void addVehicle(Vehicle* v) {
        if (count < 50) {
            vehicles[count++] = v;
        } else {
            cout << "Registry Full!\n";
        }
    }

    void displayAll() {
        if (count == 0) {
            cout << "No vehicles available.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "\n----------------------\n";
            vehicles[i]->display();
        }
    }

    void searchById(int id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\nVehicle Found:\n";
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

/* =============== Main Function =============== */
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- Vehicle Management System ---\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. Add Sports Car\n";
        cout << "4. View All Vehicles\n";
        cout << "5. Search Vehicle by ID\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, year;
            char manu[30], model[30], fuel[20];

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            registry.addVehicle(new Car(id, manu, model, year, fuel));
        }

        else if (choice == 2) {
            int id, year, battery;
            char manu[30], model[30], fuel[20];

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity: ";
            cin >> battery;

            registry.addVehicle(
                new ElectricCar(id, manu, model, year, fuel, battery)
            );
        }

        else if (choice == 3) {
            int id, year, battery, speed;
            char manu[30], model[30], fuel[20];

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity: ";
            cin >> battery;
            cout << "Enter Top Speed: ";
            cin >> speed;

            registry.addVehicle(
                new SportsCar(id, manu, model, year, fuel, battery, speed)
            );
        }

        else if (choice == 4) {
            registry.displayAll();
        }

        else if (choice == 5) {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchById(id);
        }

        else if (choice == 6) {
            cout << "Exiting system. Goodbye!\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

}


/*
output:
--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 1
Enter ID: 101
Enter Manufacturer: Toyota
Enter Model: Innova
Enter Year: 2022
Enter Fuel Type: Diesel

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 2
Enter ID: 102
Enter Manufacturer: Tesla
Enter Model: Model3
Enter Year: 2023
Enter Fuel Type: Electric
Enter Battery Capacity: 75

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 3
Enter ID: 103
Enter Manufacturer: Tesla
Enter Model: Roadster
Enter Year: 2024
Enter Fuel Type: Electric
Enter Battery Capacity: 100
Enter Top Speed: 400

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 4
----------------------
Vehicle ID   : 101
Manufacturer : Toyota
Model        : Innova
Year         : 2022
Fuel Type    : Diesel

----------------------
Vehicle ID   : 102
Manufacturer : Tesla
Model        : Model3
Year         : 2023
Fuel Type    : Electric
Battery (kWh): 75

----------------------
Vehicle ID   : 103
Manufacturer : Tesla
Model        : Roadster
Year         : 2024
Fuel Type    : Electric
Battery (kWh): 100
Top Speed    : 400 km/h

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 5
Enter Vehicle ID to search: 102
Vehicle Found:
Vehicle ID   : 102
Manufacturer : Tesla
Model        : Model3
Year         : 2023
Fuel Type    : Electric
Battery (kWh): 75

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 5
Enter Vehicle ID to search: 999
Vehicle not found!

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 8
Invalid choice!

--- Vehicle Management System ---
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. View All Vehicles
5. Search Vehicle by ID
6. Exit
Enter choice: 6
Exiting system. Goodbye!

*/
