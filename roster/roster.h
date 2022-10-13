#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>

using namespace std;



#include "student.h"
#include "degree.h"

// to do create the data type DegreeProgram and update from string

// double check that the add will create a new student then update the pointers to add it into the roster probabally going to have to use this to do it

class Roster
{
    public: // constructer and destructor only in header
    Roster()
    {
        const string studentData[] =

        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Vic,Kauzlarich,redacted@redacted.edu,29, 30,35,30,SOFTWARE"};
        
        // populate time
        for (int i = 0; i < (sizeof(studentData)/sizeof(studentData[0])); i++)
        {
            this->dataPopulation(studentData[i]);
        }
    };
    ~Roster() {};
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void emailValidater(string email);
    void printAll() const;
    void printAverageDaysInCourse(string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    private: // contains my variables and the private data processor 
    void dataPopulation(string data);
    int size = 0;
    int index = 0;
    string invalidEmails[256];
    int emailCounter = 0;
    string validEmail = "roster@emailValidator.com";
    Student* classRosterArray[5];

};

#endif
