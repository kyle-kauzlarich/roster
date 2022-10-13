#include <iostream>
#include <string>

using namespace std;

#include "student.h"


// adding my setters with their respective getters
void Student::setID(string ID)
{
    this->studentID = ID;
};

string Student::getID() const
{
    return studentID;
};

void Student::setFirst(string first)
{
    firstName = first;
};

string Student::getFirst() const
{
    return firstName;
}

void Student::setLast(string last)
{
    lastName = last;
};

string Student::getLast() const
{
    return lastName;
}

void Student::setEmail(string emailAddress)
{
    email = emailAddress;
};

string Student::getEmail() const
{
    return email;
}

void Student::setDegree(DegreeProgram degree)
{
    degreeProgram = degree;
};

DegreeProgram Student::getDegree() const
{
    return degreeProgram;
};

void Student::setAge(int studentAge)
{
    this->age = studentAge;
};

int Student::getAge() const
{
    return this->age;
};

void Student::setDays(int course1, int course2, int course3)
{
    daysToComplete[0] = course1;
    daysToComplete[1] = course2;
    daysToComplete[2] = course3;
};

int Student::getDays(int number) const
{
    
    if (number == 1) { return daysToComplete[0]; }
    else if (number == 2) { return daysToComplete[1]; }
    else if (number == 3) { return daysToComplete[2]; }
    else { return 00; };
};

void Student::print(string selector) const
{
    if (selector == "studentID") { cout << this->getID(); }
    else if (selector == "firstName") { cout << this->getFirst(); }
    else if (selector == "lastName") { cout << this->getLast(); }
    else if (selector == "email") { cout << this->getEmail(); }
    else if (selector == "age") { cout << this->getAge(); }
    else if (selector == "days")
    {
        cout << "daysInCourse: {";
        cout << this->getDays(1) << ", " << this->getDays(2) << ", " << this->getDays(3);
        cout << "}";
    }
    else if (selector == "degree")
    { // converting degree programs binary to the types
        if (this->getDegree() == 0) { cout << "SOFTWARE"; };
        if (this ->getDegree() == 1) { cout << "SECURITY"; };
        if (this->getDegree() == 2) { cout << "NETWORK"; };
        
    }

    else { cout << "FixME: student print"; }

};
