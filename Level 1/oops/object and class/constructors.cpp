// #include <iostream>
// #include <string>
// using namespace std;

// class Person {
// public:
//     // Default Constructor
//     Person() {
//         age = 0;
//         name = "Unknown";
//         cout << "Default Constructor called." << endl;
//     }

//     // Parameterized Constructor
//     Person(int a, string n){
//         age = a;
//         name = n;
//         cout << "Parameterized Constructor called." << endl;
//     }

    
//     // Person(int a, string n) : age(a), name(n) {
//     //     cout << "Parameterized Constructor called." << endl;
//     // }

//     // Copy Constructor
//     Person(const Person& other) {
//         age = other.age;
//         name = other.name;
//         cout << "Copy Constructor called." << endl;
//     }

//     // Member function to display information
//     void displayInfo() {
//         cout << "Name: " << name << ", Age: " << age << endl;
//     }

//     // Destructor
//     ~Person() {
//         cout << "Destructor called for " << name << endl;
//     }

// private:
//     int age;
//     string name;
// };

// int main() {
//     // Using Default Constructor
//     cout << "Creating p1 using Default Constructor" << endl;
//     Person p1;
//     p1.displayInfo();
//     cout << endl;

//     // Using Parameterized Constructor
//     cout << "Creating p2 using Parameterized Constructor" << endl;
//     Person p2(25, "Alice");
//     p2.displayInfo();
//     cout << endl;

//     // Using Copy Constructor
//     cout << "Creating p3 using Copy Constructor from p2" << endl;
//     Person p3 = p2;
//     p3.displayInfo();
//     cout << endl;

//     // Explicitly calling Parameterized Constructor
//     cout << "Creating p4 using Parameterized Constructor explicitly" << endl;
//     Person p4 = Person(30, "Bob");
//     p4.displayInfo();
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    // Default Constructor
    Person() : age(0), name("Unknown") {
        cout << "Default Constructor called." << endl;
    }

    // Parameterized Constructor with Initialization List
    Person(int a, string n) : age(a), name(n) {
        cout << "Parameterized Constructor with Initialization List called." << endl;
    }

    // Copy Constructor
    Person(const Person& other) : age(other.age), name(other.name) {
        cout << "Copy Constructor with Initialization List called." << endl;
    }

    // Member function to display information
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Destructor
    ~Person() {
        cout << "Destructor called for " << name << endl;
    }

private:
    int age;
    string name;
};

int main() {
    // Using Parameterized Constructor with Initialization List
    cout << "Creating p1 using Parameterized Constructor with Initialization List" << endl;
    Person p1(25, "Alice");
    p1.displayInfo();
    cout << endl;

    return 0;
}
