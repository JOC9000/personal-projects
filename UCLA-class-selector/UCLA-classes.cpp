// UCLA-classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CSclasses.h"
using namespace std;

int main()
{
    cout << "Hello CS UCLA goer!\n";

    cout << "Loading Classes...";
    list <Course> allCS = getRequiredClasses();
	list <Course> electiveCS = getElectiveClasses();
    cout << " All classes loaded!\n";

    list <string> CSclassesTaken = promptEntry("CS");
    list <string> MATHclassesTaken = promptEntry("MATH");
    list <string> PHYSICSclassesTaken = promptEntry("PHYSICS");

    list <string> classesTaken;
    list <string>::iterator iter;
    for (iter = CSclassesTaken.begin(); iter != CSclassesTaken.end(); iter++)
        classesTaken.push_back(*iter);
    for (iter = MATHclassesTaken.begin(); iter != MATHclassesTaken.end(); iter++)
        classesTaken.push_back(*iter);
    for (iter = PHYSICSclassesTaken.begin(); iter != PHYSICSclassesTaken.end(); iter++)
        classesTaken.push_back(*iter);
	
	// The stats requirement is special, and is coded as STATS100A regardless of actual class fulfilled
	if (promptStatsRequirement()) {
		classesTaken.push_back("STATS100A");
	}

    list <list<Course>> multLists = checkCourses(classesTaken, allCS);

    list <list<Course>>::iterator it = multLists.begin();
    list <Course> taken = *it;
    it++;
    list <Course> available = *it;
    it++;
    list <Course> preReqNeeded = *it;

    list <Course>::iterator availIt;
    cout << "Required classes you can take are: \n";
    for (availIt = available.begin(); availIt != available.end(); availIt++) {
        cout << (*availIt).subject << (*availIt).courseNum << "\n";
    }
	
	// Get the list of CS elective courses with qualified prerequisites
	list <list<Course>> electiveMultiList = checkCourses(classesTaken, electiveCS);
	it = electiveMultiList.begin();
	it++;
	available = *it;
	
	// Print the list
    cout << endl << "CS electives you can take are:" << endl;
    for (availIt = available.begin(); availIt != available.end(); availIt++) {
        cout << (*availIt).subject << (*availIt).courseNum << endl;
    }

}
