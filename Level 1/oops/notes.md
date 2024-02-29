Object-oriented programming (OOP) is a programming paradigm that uses objects – instances of classes – for designing and organizing code. C++ is a multi-paradigm programming language that supports both procedural and object-oriented programming. Below is a brief overview of key concepts in object-oriented programming using C++:

### Classes and Objects:

**Class:**
- A class is a user-defined data type that represents a blueprint for creating objects.
- It encapsulates data (attributes) and functions (methods) that operate on that data.
- Example:

  ```cpp
  class Car {
  public:
      // Data members (attributes)
      string brand;
      int year;

      // Member functions (methods)
      void accelerate() {
          // Code for accelerating the car
      }
  };
  ```

**Object:**
- An object is an instance of a class.
- It represents a real-world entity and has a state (attributes) and behavior (methods).
- Example:

  ```cpp
  Car myCar; // Creating an object of the Car class
  myCar.brand = "Toyota";
  myCar.year = 2022;
  myCar.accelerate();
  ```

In C++, when you do p3 = p1;, you are performing a member-wise copy, and the values of p1 are copied to p3. After this operation, p3 and p1 become independent objects, and changing the value of p3.age does not affect p1.age.

If you want p1 and p3 to share the same data (i.e., modifying one should reflect in the other), you need to implement a copy constructor or use pointers/reference for dynamic memory allocation.

### Constructors and Destructors:

**Constructor:**

- A constructor is a special member function that is automatically called when an object of a class is created.

- It is used to initialize the data members of a class.

- It has the same name as the class and does not have a return type.

- It can be overloaded to accept different types of arguments.

- If a constructor is not defined, the compiler provides a default constructor.

- Example:

  ```cpp
  class Car {
  public:
      string brand;
      int year;

      // Default constructor
      Car() {
          cout << "A car object is created." << endl;
      }

      // Parameterized constructor
      Car(string b, int y) {
          brand = b;
          year = y;
          cout << "A car object is created." << endl;
      }
  };

  int main() {
      Car myCar;  // Output: A car object is created.
      myCar.brand = "Toyota";
      myCar.year = 2022;

      Car myCar2("Toyota", 2022);  // Output: A car object is created.
      return 0;
  }
  ```

In C++, a constructor is a special member function of a class that is called automatically when an object of that class is created. Constructors are used to initialize the object's data members or perform any other necessary setup.

Here are the key points about constructors:

1. **Default Constructor:**
   - A default constructor is one that takes no parameters. If you do not provide a constructor for your class, the compiler will generate a default constructor.
   - Example:

     ```cpp
     class Person {
     public:
         // Default Constructor
         Person() {
             // Initialization code goes here
         }
     };
     ```

2. **Parameterized Constructor:**
   - A parameterized constructor takes one or more parameters to initialize the object's data members with specific values.
   - Example:

     ```cpp
     class Person {
     public:
         // Parameterized Constructor
         Person(int a, string n) {
             age = a;
             name = n;
         }
     };
     ```

3. **Copy Constructor:**
   - A copy constructor is used to create a new object as a copy of an existing object.
   - Example:

     ```cpp
     class Person {
     public:
         // Copy Constructor
         Person(const Person& other) {
             age = other.age;
             name = other.name;
         }
     };
     ```

4. **Constructor Overloading:**
   - Like other functions, constructors can be overloaded by providing different sets of parameters.
   - Example:

     ```cpp
     class Person {
     public:
         // Default Constructor
         Person() {
             // Initialization code for default constructor
         }

         // Parameterized Constructor
         Person(int a, string n) {
             age = a;
             name = n;
         }

         // Copy Constructor
         Person(const Person& other) {
             age = other.age;
             name = other.name;
         }
     };
     ```

5. **Initialization List:**
   - Initialization lists are used in constructors to initialize member variables before the body of the constructor is executed.
   - Example:

     ```cpp
     class Person {
     public:
         // Parameterized Constructor with Initialization List
         Person(int a, string n) : age(a), name(n) {
             // Other initialization code if needed
         }
     };
     ```

Constructors play a crucial role in setting up the initial state of an object and ensuring that it is ready for use. They are automatically called when objects are created and cannot be called explicitly like regular functions.

**Destructor:**

- A destructor is a special member function that is automatically called when an object of a class is destroyed.

- It is used to free the resources that were allocated by a constructor or any other class member function.

- It has the same name as the class preceded by a tilde (~) and does not have a return type.

- It cannot be overloaded or inherited.

- If a destructor is not defined, the compiler provides a default destructor.

- Example:

  ```cpp
  class Car {
  public:
      string brand;
      int year;

      // Default constructor
      Car() {
          cout << "A car object is created." << endl;
      }

      // Parameterized constructor
      Car(string b, int y) {
          brand = b;
          year = y;
          cout << "A car object is created." << endl;
      }

      // Destructor
      ~Car() {
          cout << "A car object is destroyed." << endl;
      }
  };

  int main() {
      Car myCar;  // Output: A car object is created.
      myCar.brand = "Toyota";
      myCar.year = 2022;

      Car myCar2("Toyota", 2022);  // Output: A car object is created.
      return 0;  // Output: A car object is destroyed.
  }
  ```

### Access Modifiers:

- Access modifiers are keywords that define the scope of class members.

- They are used to enforce encapsulation.

- There are three access modifiers in C++: `public`, `private`, and `protected`.

- Example:

  ```cpp
  class Car {
  public:
      string brand;  // Public attribute
      int year;  // Public attribute

      void accelerate() {  // Public method
          // Code for accelerating the car
      }

  private:
      int speed;  // Private attribute

      void setSpeed(int s) {  // Private method
          speed = s;
      }
  };

  int main() {
      Car myCar;
      myCar.brand = "Toyota";  // OK
      myCar.year = 2022;  // OK
      myCar.speed = 200;  // Not OK
      myCar.setSpeed(200);  // Not OK
      return 0;
  }
  ```
Access modifiers in C++ are keywords used to control the visibility and accessibility of class members (variables and functions). There are three main access modifiers in C++:

1. **Public:**
   - Members declared as public are accessible from any part of the program.
   - They can be accessed by objects of the class and by code outside the class.
   - Syntax: `public:`

2. **Private:**
   - Members declared as private are only accessible within the class.
   - They cannot be accessed directly by objects or functions outside the class.
   - Syntax: `private:`

3. **Protected:**
   - Members declared as protected are accessible within the class and its subclasses (derived classes).
   - They are similar to private members but with the additional feature of inheritance.
   - Syntax: `protected:`

Here's an example demonstrating the use of access modifiers:

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    // Public member variable
    int publicVar;

    // Public member function
    void publicFunction() {
        cout << "Public Function" << endl;
    }

private:
    // Private member variable
    int privateVar;

    // Private member function
    void privateFunction() {
        cout << "Private Function" << endl;
    }

protected:
    // Protected member variable
    int protectedVar;

    // Protected member function
    void protectedFunction() {
        cout << "Protected Function" << endl;
    }
};

int main() {
    MyClass obj;

    // Accessing public members
    obj.publicVar = 10;
    obj.publicFunction();

    // Cannot access private members directly (results in a compilation error)
    // obj.privateVar = 20;  // Error
    // obj.privateFunction(); // Error

    // Cannot access protected members directly (results in a compilation error)
    // obj.protectedVar = 30;  // Error
    // obj.protectedFunction(); // Error

    return 0;
}
```

In this example:

- `publicVar` and `publicFunction` are public members accessible outside the class.
- `privateVar` and `privateFunction` are private members accessible only within the class.
- `protectedVar` and `protectedFunction` are protected members accessible within the class and its derived classes.

```cpp
class DerivedClass : public MyClass {
public:
    void anotherFunction() {
        protectedVar = 123; // Accessing protectedVar in the derived class
    }
};
```

### Accessors and Mutators:

- Accessors (getters) and mutators (setters) are special methods that are used to access and modify the private attributes of a class.

- They are used to enforce encapsulation.

- Example:

  ```cpp
  class Car {
  private:
      int speed;

  public:
      int getSpeed() {
          return speed;
      }

      void setSpeed(int s) {
          speed = s;
      }
  };

  int main() {
      Car myCar;
      myCar.setSpeed(200);
      cout << myCar.getSpeed() << endl;  // Output: 200
      return 0;
  }
  ```

Accessors and mutators, often referred to as getters and setters, are methods used to access and modify the private members (variables) of a class. They are commonly employed to implement encapsulation by providing controlled access to the internal state of a class.

1. **Accessor (Getter):**
   - An accessor is a member function that retrieves the value of a private member variable.
   - It provides read-only access to the private data.
   - Accessors usually return the value of the private member without allowing modification.

    ```cpp
    class MyClass {
    private:
        int myVar;

    public:
        // Accessor (Getter)
        int getMyVar() const {
            return myVar;
        }
    };
    ```

2. **Mutator (Setter):**
   - A mutator is a member function that modifies the value of a private member variable.
   - It provides a way to change the internal state of the object.
   - Mutators often take a parameter representing the new value and update the private member accordingly.

    ```cpp
    class MyClass {
    private:
        int myVar;

    public:
        // Mutator (Setter)
        void setMyVar(int newValue) {
            myVar = newValue;
        }
    };
    ```

3. **Use of `const` in Accessors:**
   - It is common to declare accessor functions as `const` if they do not modify the object's state.
   - This allows accessor methods to be called on constant objects and within constant member functions.

    ```cpp
    class MyClass {
    private:
        int myVar;

    public:
        // Accessor (Getter) with const
        int getMyVar() const {
            return myVar;
        }
    };
    ```

4. **Benefits of Accessors and Mutators:**
   - They provide a controlled interface to access and modify private data.
   - They allow the class to enforce validation rules or perform additional actions when data is accessed or modified.
   - They contribute to encapsulation by hiding the implementation details of the class.

Here's an example illustrating the use of accessors and mutators:

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Accessors (Getters)
    int getLength() const {
        return length;
    }

    int getWidth() const {
        return width;
    }

    // Mutators (Setters)
    void setLength(int l) {
        if (l > 0) {
            length = l;
        } else {
            cout << "Invalid length. Setting to default (1)." << endl;
            length = 1;
        }
    }

    void setWidth(int w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Invalid width. Setting to default (1)." << endl;
            width = 1;
        }
    }

    // Function to calculate area
    int calculateArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rectangle;
    rectangle.setLength(5);
    rectangle.setWidth(3);

    cout << "Length: " << rectangle.getLength() << endl;
    cout << "Width: " << rectangle.getWidth() << endl;
    cout << "Area: " << rectangle.calculateArea() << endl;

    return 0;
}
```

In this example, the `Rectangle` class uses accessors (`getLength()` and `getWidth()`) and mutators (`setLength()` and `setWidth()`) to control access to its private members. The mutators enforce the rule that length and width should be positive values.


### Static Members:

- Static members are class members that are shared by all objects of a class.

- They are declared using the `static` keyword.

- They are accessed using the class name and the scope resolution operator (::).

- Example:

  ```cpp
  class Car {
  public:
      static int count;

      Car() {
          count++;
      }
  };

  int Car::count = 0;

  int main() {
      Car myCar1;
      Car myCar2;
      cout << Car::count << endl;  // Output: 2
      return 0;
  }
  ```
Static members in C++ are class members that belong to the class rather than instances of the class (objects). They are shared among all instances of the class and can be accessed using the class name without creating an object. There are two types of static members: static variables (data members) and static methods.

1. **Static Data Members:**
   - A static data member is a class variable shared by all objects of that class.
   - It is declared using the `static` keyword and initialized outside the class.
   - Static data members have a single instance shared across all objects.

    ```cpp
    class MyClass {
    public:
        static int staticVar; // Declaration

        // Other non-static members...

    };

    int MyClass::staticVar = 0; // Initialization
    ```

   - Example usage:

    ```cpp
    MyClass obj1, obj2;
    obj1.staticVar = 10;
    cout << obj2.staticVar; // Outputs 10 (shared among all objects)
    ```

2. **Static Member Functions:**
   - A static member function is a class method that operates on static members or does not have access to the instance-specific `this` pointer.
   - It is declared using the `static` keyword.

    ```cpp
    class MyClass {
    public:
        static void staticFunction() {
            // Some code
        }

        // Other non-static members...

    };
    ```

   - Example usage:

    ```cpp
    MyClass::staticFunction(); // Called using the class name, not an object
    ```

   - A static member function can only access static members (data or functions) and cannot access non-static members directly.

Here's a complete example demonstrating the use of static members:

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    static double interestRate; // Static data member

public:
    int accountNumber;
    double balance;

    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    // Static member function
    static void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Member function using the static data member
    void applyInterest() {
        balance += balance * interestRate;
    }

    // Static member function to get the interest rate
    static double getInterestRate() {
        return interestRate;
    }
};

// Initialization of static data member
double BankAccount::interestRate = 0.03;

int main() {
    BankAccount account1(1001, 5000.0);
    BankAccount account2(1002, 8000.0);

    cout << "Initial balances:" << endl;
    cout << "Account 1: $" << account1.balance << endl;
    cout << "Account 2: $" << account2.balance << endl;

    // Accessing static data member and using static member function
    BankAccount::setInterestRate(0.05);

    // Applying interest using non-static member function
    account1.applyInterest();
    account2.applyInterest();

    cout << "\nBalances after applying interest:" << endl;
    cout << "Account 1: $" << account1.balance << endl;
    cout << "Account 2: $" << account2.balance << endl;

    // Accessing static member function to get the interest rate
    cout << "\nCurrent Interest Rate: " << BankAccount::getInterestRate() << endl;

    return 0;
}
```

In this example, `interestRate` is a static data member shared among all instances of the `BankAccount` class. The `setInterestRate` and `getInterestRate` are static member functions demonstrating the use of static methods. The `applyInterest` member function uses the static data member to apply interest to each account.

### Friend Functions:

- A friend function is a non-member function that has access to the private members of a class.

- It is declared using the `friend` keyword.

- It is not a member of the class.

- It can be declared in the private or public section of the class.

- Example:

  ```cpp
  class Car {
  private:
      string brand;

  public:
      Car(string b) {
          brand = b;
      }

      friend void printBrand(Car car);
  };

  void printBrand(Car car) {
      cout << car.brand << endl;
  }

  int main() {
      Car myCar("Toyota");
      printBrand(myCar);  // Output: Toyota
      return 0;
  }
  ```

### Operator Overloading:

- Operator overloading allows operators to be redefined for user-defined types.

- It is achieved by defining operator functions.

- Example:

  ```cpp
  class Car {
  private:
      int speed;

  public:
      Car() {
          speed = 0;
      }

      Car(int s) {
          speed = s;
      }

      Car operator+(Car car) {
          Car newCar;
          newCar.speed = this->speed + car.speed;
          return newCar;
      }

      int getSpeed() {
          return speed;
      }
  };

  int main() {
      Car myCar1(100);
      Car myCar2(200);
      Car myCar3 = myCar1 + myCar2;
      cout << myCar3.getSpeed() << endl;  // Output: 300
      return 0;
  }
  ```

### Encapsulation:

- Encapsulation refers to bundling the data (attributes) and the methods that operate on the data within a single unit (class).
- It helps in hiding the internal details and exposing only what is necessary.

### Inheritance:

- Inheritance allows a class (derived or child class) to inherit the properties and behaviors of another class (base or parent class).
- It promotes code reusability and the creation of a hierarchy of classes.

  ```cpp
  class Animal {
  public:
      void eat() {
          cout << "Animal is eating." << endl;
      }
  };

  class Dog : public Animal {
  public:
      void bark() {
          cout << "Dog is barking." << endl;
      }
  };
  ```

### Polymorphism:

- Polymorphism allows objects of different types to be treated as objects of a common type.
- It can be achieved through function overloading and virtual functions.

  ```cpp
  class Shape {
  public:
      virtual void draw() {
          cout << "Drawing a shape." << endl;
      }
  };

  class Circle : public Shape {
  public:
      void draw() override {
          cout << "Drawing a circle." << endl;
      }
  };
  ```

### Abstraction:

- Abstraction involves simplifying complex systems by modeling classes based on the essential features they share.
- It focuses on what an object does rather than how it does it.

### Example:

Here's a simple example combining these concepts:

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks." << endl;
    }
};

int main() {
    Animal *animal = new Dog();
    animal->sound();  // Output: Dog barks

    delete animal;
    return 0;
}
```

This example demonstrates polymorphism with virtual functions. The `Dog` class inherits from the `Animal` class, and the `sound` function is overridden in the `Dog` class.

This is a high-level overview of object-oriented programming in C++. Each of these concepts can be explored in more detail based on specific programming needs and requirements.