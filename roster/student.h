#ifndef student_h
#define student_h

#include <iostream>
#include <string>

#include "degree.h"

using namespace std;


/*
only function that is written in here should be the constructors for ease of reading
*/

class Student
{
    public: // constructer and destructor only in header
   Student()
    {
        studentID = "11QA";
        firstName = "NoFirst";
        lastName = "NoLast";
        email = "NoEmailProvided@null.com";
        degreeProgram = SOFTWARE;
        age = -1;
        daysToComplete[0] = -5;
        daysToComplete[1] = -10;
        daysToComplete[2] = -15;
   };
    Student(string idNum, string first, string last, string mail, int age, int day1, int day2, int day3, DegreeProgram degree)
    {
        this->studentID = idNum;
        this->firstName = first;
        this->lastName = last;
        this->email = mail;
        this->degreeProgram = degree;
        this->age = age;
        this->daysToComplete[0] = day1;
        this->daysToComplete[1] = day2;
        this->daysToComplete[2] = day3;
    };
    ~Student(){};
    void setID(string ID);
    string getID() const;
    void setFirst(string first);
    string getFirst() const;
    void setLast(string last);
    string getLast() const;
    void setEmail(string emailAddress);
    string getEmail() const;
    void setDegree(DegreeProgram degree);
    DegreeProgram getDegree() const;
    void setAge(int studentAge);
    int getAge() const;
    void setDays(int course1, int course2, int course3);
    int getDays(int number) const;
    void print(string selector) const;
    
    private: // vars with the default values noted
    string studentID; // 11QA
    string firstName; // NoFirst
    string lastName; // NoLast
    string email; // NoEmailProvided@null.com
    DegreeProgram degreeProgram; // NotSet
    int age; // -1
    int daysToComplete [3]; // -5, -10, -15
};

#endif
