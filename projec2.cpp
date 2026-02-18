#include <iostream>
#include <cstring>
using namespace std;

// ================= Train Class =================
class Train {
private:
    int train_num;
    char train_name[50];
    char train_src[50];
    char desti[50];
    char train_time[50];

    static int traincount;

public:
    // Default Constructor
    Train() {
        train_num = 0;
        strcpy(train_name, "");
        strcpy(train_src, "");
        strcpy(desti, "");
        strcpy(train_time, "");
    }

    // Parameterized Constructor
    Train(int num, const char* name, const char* src,
          const char* dest, const char* time) {
        train_num = num;
        strcpy(train_name, name);
        strcpy(train_src, src);
        strcpy(desti, dest);
        strcpy(train_time, time);
        traincount++;
    }

    // Destructor
    ~Train() {
        if (train_num != 0)
            traincount--;
    }

    // Setters
    void setTrainNumber(int num) {
        train_num = num;
    }

    void setName(const char* name) {
        strcpy(train_name, name);
    }

    void setSource(const char* src) {
        strcpy(train_src, src);
    }

    void setDestination(const char* dest) {
        strcpy(desti, dest);
    }

    void setTrainTime(const char* time) {
        strcpy(train_time, time);
    }

    // Getter
    int getTrainNumber() {
        return train_num;
    }

    // Input
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> train_num;

        cout << "Enter Train Name: ";
        cin >> train_name;

        cout << "Enter Source: ";
        cin >> train_src;

        cout << "Enter Destination: ";
        cin >> desti;

        cout << "Enter Train Time: ";
        cin >> train_time;
        
        cout<<"\n";
        traincount++;
    }

    // Display
    void displayTrainDetails() {
        cout << "\nTrain Number: " << train_num;
        cout << "\nTrain Name: " << train_name;
        cout << "\nSource: " << train_src;
        cout << "\nDestination: " << desti;
        cout << "\nTrain Time: " << train_time << endl;
    }

    static int getTrainCount() {
        return traincount;
    }
};

int Train::traincount = 0;

// =================| RailwaySystem Class |=================
class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train limit reached!";
        }
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "No train records found!"<<endl;
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        bool found = false;

        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Train not found!";
    }
};

// =================| Main |=================
int main() {
    RailwaySystem system;
    int choice, number;

    cout << "Enter details of minimum 3 trains:\n";
    for (int i = 0; i < 3; i++) {
        system.addTrain();
    }

    do {
        cout << "\n--- Railway Reservation System Menu ---";
        cout << "\n1. Add New Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            cout << "Enter Train Number to search: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;
        case 4:
            cout << "Exiting system. Goodbye!";
            break;
        default:
            cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}

/*
Enter details of minimum 3 trains:
Enter Train Number: 100
Enter Train Name: Rajdhani
Enter Source: Dehli
Enter Destination: Mumbai
Enter Train Time: 06:00am

Enter Train Number: 101
Enter Train Name: Shatabdi
Enter Source: Ahamadabad
Enter Destination: Jaipur
Enter Train Time: 09:00pm

Enter Train Number: 103
Enter Train Name: GaribRath
Enter Source: Surat
Enter Destination: Delhi
Enter Train Time: 02:15pm


--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 104
Enter Train Name: Intercity
Enter Source: Vadodara
Enter Destination: Indore
Enter Train Time: 10:45am


--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 2

Train Number: 100
Train Name: Rajdhani
Source: Dehli
Destination: Mumbai
Train Time: 06:00am

Train Number: 101
Train Name: Shatabdi
Source: Ahamadabad
Destination: Jaipur
Train Time: 09:00pm

Train Number: 103
Train Name: GaribRath
Source: Surat
Destination: Delhi
Train Time: 02:15pm

Train Number: 104
Train Name: Intercity
Source: Vadodara
Destination: Indore
Train Time: 10:45am

--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to search: 102
Train not found!
--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to search: 103

Train Number: 103
Train Name: GaribRath
Source: Surat
Destination: Delhi
Train Time: 02:15pm

--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 5
Invalid choice!
--- Railway Reservation System Menu ---
1. Add New Train
2. Display All Trains
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting system. Goodbye!
*/
