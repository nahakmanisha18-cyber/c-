#include <iostream>
#include <string>
using namespace std;


class LibraryItem {
    string title;
    string author;
    string dueDate;

public:
    // Getter
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    // Setter
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    // Constructor
    LibraryItem(string title, string author, string dueDate) {
        this->title = title;
        this->author = author;
        this->dueDate = dueDate;
    }

    // Destructor
    virtual ~LibraryItem() {}

    // Pure virtual functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

// ------------------- Book Class -------------------
class Book : public LibraryItem {
    int quantity;
    string ISBN;

public:
    Book(string title, string author, string dueDate, int quantity, string ISBN)
        : LibraryItem(title, author, dueDate) {
        if (quantity < 0)
            throw "Quantity cannot be negative";
        this->quantity = quantity;
        this->ISBN = ISBN;
    }

    void checkOut() {
        if (quantity > 0) {
            quantity--;
            cout << "Book checked out successfully\n";
        } else {
            cout << "Book not available\n";
        }
    }

    void returnItem() {
        quantity++;
        cout << "Book returned successfully\n";
    }

    void displayDetails() {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

// ------------------- DVD Class -------------------
class DVD : public LibraryItem {
    int duration;

public:
    DVD(string title, string author, string dueDate, int duration)
        : LibraryItem(title, author, dueDate) {
        if (duration < 0)
            throw "Invalid DVD duration";
        this->duration = duration;
    }

    void checkOut() {
        cout << "DVD checked out successfully\n";
    }

    void returnItem(){
        cout << "DVD returned successfully\n";
    }

    void displayDetails() {
        cout << "\n--- DVD Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes\n";
    }
};

// ------------------- Magazine Class -------------------
class Magazine : public LibraryItem {
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int issueNumber)
        : LibraryItem(title, author, dueDate) {
        if (issueNumber <= 0)
            throw "Invalid issue number";
        this->issueNumber = issueNumber;
    }

    void checkOut()  {
        cout << "Magazine checked out successfully\n";
    }

    void returnItem() {
        cout << "Magazine returned successfully\n";
    }

    void displayDetails() {
        cout << "\n--- Magazine Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

// ------------------- Main Function -------------------
int main() {
    LibraryItem* libraryItems[500];
    int count = 0;
    int choice;

    do {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string title, author, dueDate, ISBN;
                int quantity;

                cin.ignore();
                cout << "Title: ";
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Due Date: ";
                getline(cin, dueDate);
                cout << "Quantity: ";
                cin >> quantity;
                cin.ignore();
                cout << "ISBN: ";
                getline(cin, ISBN);

                libraryItems[count++] = new Book(title, author, dueDate, quantity, ISBN);
            } 
            else if (choice == 2) {
                string title, author, dueDate;
                int duration;

                cin.ignore();
                cout << "Title: ";
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Due Date: ";
                getline(cin, dueDate);
                cout << "Duration (minutes): ";
                cin >> duration;

                libraryItems[count++] = new DVD(title, author, dueDate, duration);
            } 
            else if (choice == 3) {
                string title, author, dueDate;
                int issue;

                cin.ignore();
                cout << "Title: ";
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Due Date: ";
                getline(cin, dueDate);
                cout << "Issue Number: ";
                cin >> issue;

                libraryItems[count++] = new Magazine(title, author, dueDate, issue);
            } 
            else if (choice == 4) {
                for (int i = 0; i < count; i++)
                    libraryItems[i]->displayDetails();
            } 
            else if (choice == 5) {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                
                if (index >= 0 && index < count) {
                	libraryItems[index]->checkOut();
				} 
                else {
                	cout << "Invalid index\n";
				}
                
            } 
            else if (choice == 6) {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                if (index >= 0 && index < count) {
                	libraryItems[index]->checkOut();
				} 
                else {
                	cout << "Invalid index\n";
				}
            }else{
            	cout << "Invalid index choice\n";
			}
            
        } 
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        } 
        catch (...) {
            cout << "Unknown error occurred\n";
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete libraryItems[i];

    cout << "Program exited successfully\n";
    return 0;
}
/*
output:

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 1
Title: Harry Potter and the Sorcerer's Stone
Author: J.K. Rowling
Due Date: 2026-03-15
Quantity: 3
ISBN: 978-0439708180

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 2
Title: Inception
Author: Christopher Nolan
Due Date: 2026-03-25
Duration (minutes): 148

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 3
Title: National Geographic
Author: National Geographic Society
Due Date: 2026-03-20
Issue Number: 150

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 4

--- Book Details ---
Title: Harry Potter and the Sorcerer's Stone
Author: J.K. Rowling
Due Date: 2026-03-15
Quantity: 3
ISBN: 978-0439708180

--- DVD Details ---
Title: Inception
Author: Christopher Nolan
Due Date: 2026-03-25
Duration: 148 minutes

--- Magazine Details ---
Title: National Geographic
Author: National Geographic Society
Issue Number: 150
Due Date: 2026-03-20

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 5
Enter item index: 2
Magazine checked out successfully

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 6
Enter item index: 1
DVD checked out successfully

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 6
Enter item index: 2
Magazine checked out successfully

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 6
Enter item index: 3
Invalid index

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 8
Invalid index choice

====== LIBRARY MANAGEMENT SYSTEM ======
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter choice: 0
Program exited successfully
*/
