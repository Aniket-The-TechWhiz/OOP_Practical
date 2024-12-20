#include <iostream>
#include <string>
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title(""), price(0.0) {}

    // Parameterized constructor
    Publication(string t, float p) : title(t), price(p) {}

    // Display method
    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : Publication(), pageCount(0) {}

    // Parameterized constructor
    Book(string t, float p, int pc) : Publication(t, p), pageCount(pc) {}

    // Display method for Book
    void display() {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }

    // Input method for Book
    void input() {
        cout << "Enter title for book: ";
        cin >> title;
        cout << "Enter price for book: ";
        cin >> price;
        cout << "Enter page count for book: ";
        cin >> pageCount;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playTime;

public:
    // Default constructor
    Tape() : Publication(), playTime(0.0) {}

    // Parameterized constructor
    Tape(string t, float p, float pt) : Publication(t, p), playTime(pt) {}

    // Display method for Tape
    void display() {
        Publication::display();
        cout << "Play Time (minutes): " << playTime << endl;
    }

    // Input method for Tape
    void input() {
        cout << "Enter title for tape: ";
        cin >> title;
        cout << "Enter price for tape: ";
        cin >> price;
        cout << "Enter play time (minutes) for tape: ";
        cin >> playTime;
    }
};

// Main function
int main() {
    try {
        Book book1;
        Tape tape1;

        // Input data for Book and Tape
        book1.input();
        tape1.input();

        // Display data for Book and Tape
        cout << "\nBook Data:" << endl;
        book1.display();
        cout << "\nTape Data:" << endl;
        tape1.display();
    } catch (...) {
        cout << "An error occurred. Resetting all values to zero." << endl;
        
        // Reset and display default data
        Book book1;
        Tape tape1;
        book1.display();
        tape1.display();
    }

    return 0;
}

