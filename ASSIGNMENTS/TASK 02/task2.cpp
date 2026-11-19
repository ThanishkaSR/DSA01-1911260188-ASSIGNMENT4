#include <iostream>
using namespace std;

struct Person
{
    Person()
    {
        cout << "Person ";
    }
};

struct Student : virtual Person
{
    Student()
    {
        cout << "Student ";
    }
};

struct Staff : virtual Person
{
    Staff()
    {
        cout << "Staff ";
    }
};

struct TeachingAssistant : Student, Staff
{
    TeachingAssistant()
    {
        cout << "TA ";
    }
};

int main()
{
    TeachingAssistant ta;
    cout << '\\n';
}



#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
    {
        name = n;
        id = i;
        phone = p;
    }
};

class Student : virtual public Person
{
protected:
    string program;
    double cgpa;

public:
    Student(string n, int i, string p, string prog, double c)
        : Person(n, i, p)
    {
        program = prog;
        cgpa = c;
    }
};

class Staff : virtual public Person
{
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p)
    {
        department = d;
        salary = s;
    }
};

class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant(string n, int i, string p,
                     string prog, double c,
                     string d, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, d, s)
    {
    }
};

class ResearchScholar : public Student
{
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                   string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c)
    {
        fellowship = f;
    }
};
int main()
{
    TeachingAssistant ta("Arun", 101, "9876543210",
                        "CSE", 8.5, "IT", 30000);

    ResearchScholar rs("Priya", 102, "9876543211",
                      "CSE", 9.0, 15000);

    cout << "Classes created successfully!" << endl;

    return 0;
}
