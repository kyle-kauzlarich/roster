#include <iostream>

using namespace std;

#include "roster.h"
#include "student.h"

/*

Name: Kyle "Vic" Kauzlarich
Class: Scripting and Programming - Applications – C867

*/

int main()
{
    
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "000519760" << endl;
    cout << "Vic Kauzlarich" << endl;
    
    Roster classRoster;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    

    return 0;
};
