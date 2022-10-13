#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "roster.h"
#include "student.h"

//private function to populate the roster
void Roster::dataPopulation(string data)
{ // clean up a little by moving all vars to the top and move this function to the end of the file
    string testID = "22";
    char moded[256];
    strcpy(moded, data.c_str());
    int i = 0;
    int b = 0;
    char a[256];
    string ID;
    string fName;
    string lName;
    string email;
    string hold; // using for the rest of the non string data types
    int age;
    int days1;
    int days2;
    int days3;
    DegreeProgram deg;
    
    
    while (moded[i] != ',')
    {
        a[i] = moded[i];
        i++;
    };
    i++;
    ID = a;
    memset(a, 0, 255);
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    fName = a;
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    lName = a;
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    email = a;
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    hold = a;
    age = stoi(hold);
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    hold = a;
    days1 = stoi(hold);
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    hold = a;
    days2 = stoi(hold);
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != ',')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    hold = a;
    days3 = stoi(hold);
    memset(a, 0, 255);
    b = 0;
    
    while (moded[i] != '\0')
    {
        a[b] = moded[i];
        b++;
        i++;
    };
    i++;
    hold = a;
    memset(a, 0, 255);
    b = 0;
    deg = SECURITY;
    if (hold == "SOFTWARE") { deg = SOFTWARE; };
    if (hold == "SECURITY") { deg = NETWORK; };
    
    
    /*
     vars used
     ID
     fName
     lName
     email
     age
     days1
     days2
     days3
     hold
     deg
     */
    
    this->add(ID, fName, lName, email, age, days1, days2, days3, deg);

};

// public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    this->emailValidater(emailAddress);
    classRosterArray[size] = new Student (studentID, firstName, lastName, this->validEmail, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

    size++;
    

}


// public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID)
{
    int control = size;
    bool flag = false;
    for (int z = 0; z < size; z++)
    {
        if (classRosterArray[z]->getID() == studentID)
        {
            for (int x = z; x < control; x++)
            {
                if (x + 1 != control)
                {
                    classRosterArray[x] = classRosterArray[x+1];
                    
                    // adding the size reduction once here
                    // running delete once to free the memory
                    if (size == control)
                    {
                        size--;
                        classRosterArray[size]->~Student();
                    };
                };
                
                if (flag == false) { flag = true; };
                
                
            };
        };
    };
    
    if (flag == false)
    {
        cout << "a student with this ID was not found" << endl;
    };
    
};

// check if email is valid if it is call set email with the good email if not add to invalid array
void Roster::emailValidater(string email) // ToDo add invalid to array
{

    char emailTemp[256];
    strcpy(emailTemp, email.c_str());


    char aTSign = '@';
    char space = ' ';
    const char* firstAt = strchr(emailTemp, aTSign);
    const char* lastAt = strrchr(emailTemp, aTSign);
    const char* ifSpace = strrchr(emailTemp, space);

    // logic for email validator
    if (firstAt == nullptr || ifSpace != nullptr)
    {
        //cout << "email has no @" << endl;
        invalidEmails[emailCounter] = email;
        emailCounter += 1;
        
    }
    else if(firstAt == lastAt)
    {
        validEmail = email;
    }
    else
    {
        //cout << "email is invalid" << endl;
        invalidEmails[emailCounter] = email;
        emailCounter += 1;
    }


};

// public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in Roster and call the print() function for each student.
void Roster::printAll() const
{
    
    // print selector runs on the following selector strings
    /*
     studentID
     firstName
     lastName
     email
     age
     days
     degree
     */

    for (int z = 0; z < size; z++)
    {   
        classRosterArray[z]->print("studentID");
        cout << '\t';
        classRosterArray[z]->print("firstName");
        cout << '\t';
        classRosterArray[z]->print("lastName");
        cout << '\t';
        classRosterArray[z]->print("email");
        cout << '\t';
        classRosterArray[z]->print("age");
        cout << '\t';
        classRosterArray[z]->print("days");
        cout << '\t';
        classRosterArray[z]->print("degree");
        cout << endl;
    };

    // call all the getters and seperate the cout with a slash t (you dont have backslash by default vic)
};

// public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) const
{
    
    for (int z = 0; z < size; z++)
    {
        if (classRosterArray[z]->getID() == studentID)
        {
            int average = classRosterArray[z]->getDays(1) + classRosterArray[z]->getDays(2) + classRosterArray[z]->getDays(3);
            cout << average/3 << endl;
        };
    };
};

// public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() const
{
    for (int i = 0; i < emailCounter; i++)
    {
        cout << invalidEmails[i] << endl;
    };
};

// public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
    for (int z = 0; z < size; z++)
    {
        if (classRosterArray[z]->getDegree() == degreeProgram)
        { // same as print all
            classRosterArray[z]->print("studentID");
            cout << '\t';
            classRosterArray[z]->print("firstName");
            cout << '\t';
            classRosterArray[z]->print("lastName");
            cout << '\t';
            classRosterArray[z]->print("email");
            cout << '\t';
            classRosterArray[z]->print("age");
            cout << '\t';
            classRosterArray[z]->print("days");
            cout << '\t';
            classRosterArray[z]->print("degree");
            cout << endl;
        };
    };
    
};
