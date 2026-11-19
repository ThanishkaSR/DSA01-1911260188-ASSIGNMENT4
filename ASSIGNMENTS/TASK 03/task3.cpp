#include <iostream>
using namespace std;

struct Person
{
    Person()
    {
        cout << "Person ";
    }

    ~Person()
    {
        cout << "~Person ";
    }
};

struct Student : virtual Person
{
    Student()
    {
        cout << "Student ";
    }

    ~Student()
    {
        cout << "~Student ";
    }
};

struct Staff : virtual Person
{
    Staff()
    {
        cout << "Staff ";
    }

    ~Staff()
    {
        cout << "~Staff ";
    }
};

struct TeachingAssistant : Student, Staff
{
    TeachingAssistant()
    {
        cout << "TA ";
    }

    ~TeachingAssistant()
    {
        cout << "~TA ";
    }
};

int main()
{
    cout << "Student object: ";
    {
        Student s;
    }

    cout << "\nStaff object: ";
    {
        Staff st;
    }

    cout << "\nTeachingAssistant object: ";
    {
        TeachingAssistant ta;
    }

    cout << endl;
    return 0;
}


#include <iostream>
using namespace std;

struct Engine
{
    Engine()
    {
        cout << "Engine ";
    }

    ~Engine()
    {
        cout << "~Engine ";
    }
};

struct Vehicle
{
    Vehicle()
    {
        cout << "Vehicle ";
    }

    ~Vehicle()
    {
        cout << "~Vehicle ";
    }
};

struct Car : Vehicle
{
    Engine e;

    Car()
    {
        cout << "Car ";
    }

    ~Car()
    {
        cout << "~Car ";
    }
};

int main()
{
    {
        Car c;
        cout << "| ";
    }

    cout << '\n';
}

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(const string& n, int a) : name(n), age(a) {}
};

class Address
{
    string city;
    int pin;

public:
    Address(const string& c, int p) : city(c), pin(p) {}

    string str() const
    {
        return city + "-" + to_string(pin);
    }
};

class Student : public Person
{
    long long regNo;
    Address home;

public:

    Student(const string& n, int a, long long r,
            const string& c, int p)
        : Person(n, a), regNo(r), home(c, p)
    {
    }

    void print() const
    {
        cout << regNo << ' ' << name << " (" << age << ") "
             << home.str() << '\n';
    }
};

int main()
{
    Student s("Kavya", 19, 192311001, "Salem", 636001);

    s.print();

    return 0;
}




