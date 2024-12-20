#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Student {
    string name, class_name, dob, blood_group, contact_address, telephone, driving_license;
    int roll_no;
    char division;

public:
    static int student_count;

    // Default constructor
    Student() {
        name = "";
        class_name = "";
        dob = "";
        blood_group = "";
        contact_address = "";
        telephone = "";
        driving_license = "";
        division = 'A';
        roll_no = 0;
        student_count++;
    }

    // Parameterized constructor
    Student(string n, int r, string cn, char div, string db, string bg, string ca, string t, string dl) {
        name = n;
        roll_no = r;
        class_name = cn;
        division = div;
        dob = db;
        blood_group = bg;
        contact_address = ca;
        telephone = t;
        driving_license = dl;
        student_count++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        roll_no = other.roll_no;
        class_name = other.class_name;
        dob = other.dob;
        blood_group = other.blood_group;
        contact_address = other.contact_address;
        telephone = other.telephone;
        driving_license = other.driving_license;
        division = other.division;
        student_count++;
    }

    // Display method
    void display()  {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Class: " << class_name << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << blood_group << endl;
        cout << "Contact Address: " << contact_address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Driving License: " << driving_license << endl;
    }

    // Friend function
    friend void show_data( Student& s);

    // Static method to display total students
    static void totalStudent() {
        cout << "Total Students: " << student_count << endl;
    }

    // Destructor
    ~Student() {
        student_count--;
    }

    // Method for dynamic input with validation
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter class: ";
        cin >> class_name;
        cout << "Enter division: ";
        cin >> division;
        cout << "Enter date of birth (dd/mm/yyyy): ";
        cin >> dob;
        cout << "Enter blood group: ";
        cin >> blood_group;
        cout << "Enter contact address: ";
        cin>>contact_address;
        cout << "Enter telephone number: ";
        cin >> telephone;
        cout << "Enter driving license number: ";
        cin >> driving_license;
    }
};

int Student::student_count = 0;

void show_data(Student& s) {
    s.display();
}

// Main function
int main() {
    try {
        // Create a dynamic student object
        Student* s1 = new Student("Aniket", 42, "BE", 'A', "26/02/2005", "B+", "22 Park Street", "9067432344", "DL12345");
        show_data(*s1);
        cout << endl;

        // Create another student dynamically using input
        Student* s2 = new Student();
        s2->input();
        cout<<endl;
        show_data(*s2);
        cout << endl;

        // Display total students
        Student::totalStudent();

        // Clean up dynamic memory
        delete s1;
        delete s2;

        // Display total students after deletion
        Student::totalStudent();
    } catch (const bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}

