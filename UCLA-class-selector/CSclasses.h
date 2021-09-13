#pragma once

#include <string>
#include <list>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Course {
	public:
		string subject;
		string courseNum;
		string preReqs;
		int preReqAmt;

		Course(string subjName, string num, string preReqstr, int numPreReq) {
			subject = subjName;
			courseNum = num;
			preReqs = preReqstr;
			preReqAmt = numPreReq;
		}

		void printPreReq() {
			/*cout << "Prereq's for " << subject << courseNum << ":\n";
			for (int i = 0; i < preReqAmt; i++)
				cout << preReqs[i] << "\n";
				*/
			//return 0;
		}
};

list <Course> Classes() {
	list <Course> csList;
	//CS Courses
	csList.push_back(Course("CS", "1", "", 0));

	csList.push_back(Course("CS", "31", "", 0));

	csList.push_back(Course("CS", "32", "CS31", 1));

	csList.push_back(Course("CS", "33", "CS32", 1));

	csList.push_back(Course("CS", "35L", "CS31", 1));

	csList.push_back(Course("CS", "M51A", "", 0));

	csList.push_back(Course("CS", "97", "", 0));

	csList.push_back(Course("CS", "111", "CS32,CS33,CS35L", 3));

	csList.push_back(Course("CS", "118", "CS111", 1));

	csList.push_back(Course("CS", "130", "CS111,CS131", 2));

	csList.push_back(Course("CS", "131", "CS33,CS35L", 2));

	csList.push_back(Course("CS", "132", "CS131", 1));

	csList.push_back(Course("CS", "M151B", "CS33,CSM51A", 2));

	csList.push_back(Course("CS", "M152A", "CSM51A", 1));

	csList.push_back(Course("CS", "180", "CS32,MATH61", 2));

	csList.push_back(Course("CS", "181", "CS180", 1));

	//PHYSICS Courses
	csList.push_back(Course("PHYSICS", "1A", "MATH31A,MATH31B", 2));

	csList.push_back(Course("PHYSICS", "1B", "PHYSICS1A,MATH31B,MATH32A", 3));

	csList.push_back(Course("PHYSICS", "1C", "PHYSICS1A,PHYSICS1B,MATH32A,MATH32B", 4));

	csList.push_back(Course("PHYSICS", "4AL", "PHYSICS1A", 1));
	//MATH Courses
	csList.push_back(Course("MATH", "31A", "", 0));

	csList.push_back(Course("MATH", "31B", "MATH31A", 1));

	csList.push_back(Course("MATH", "32A", "MATH31A", 1));

	csList.push_back(Course("MATH", "32B", "MATH31B,MATH32A", 2));

	csList.push_back(Course("MATH", "33A", "MATH31B", 1));

	csList.push_back(Course("MATH", "33B", "MATH31B", 1));

	csList.push_back(Course("MATH", "61", "MATH31A,MATH31B", 2));


	return csList;
}

list <string> parseClasses(string classes) {
	list <string> classList;
	int CourseAmt = 0;
	list <int> commaPos;

	if (classes == "NONE")
		return classList;

	if (classes.length() != 0)
		CourseAmt = 1;

	for (unsigned int i = 0; i < classes.length(); i++) {
		if (classes[i] == ',') {
			CourseAmt++;
			commaPos.push_back(i);
		}
	}

	int prev = 0;
	int end = 0;

	for (int i = CourseAmt; i > 1; i--) {
		end = commaPos.front();
		commaPos.pop_front();
		classList.push_back(classes.substr(prev, end - prev));
		prev = end + 1;
	}

	classList.push_back(classes.substr(prev, classes.length()));

	return classList;
}

list <string> promptEntry(string subject) {
	cout << "Please Enter all " << subject << " Courses you have taken (In format \"31,M51,33\" etc., or NONE)\n";

	string Courses;
	int CourseAmt = 0;
	list <int> commaPos;
	list <string> returnList;
	getline(cin, Courses);
	Courses.erase(std::remove(Courses.begin(), Courses.end(), ' '), Courses.end());

	if (Courses == "NONE")
		return returnList;

	if (Courses.length() != 0)
		CourseAmt = 1;

	for (unsigned int i = 0; i < Courses.length(); i++) {
		if (Courses[i] == ',') {
			CourseAmt++;
			commaPos.push_back(i);
		}
	}

	list <string> CourseStr;
	int prev = 0;
	int end = 0;

	for (int i = CourseAmt; i > 1; i--) {
		end = commaPos.front();
		commaPos.pop_front();
		CourseStr.push_back(Courses.substr(prev, end - prev));
		prev = end + 1;
	}

	CourseStr.push_back(Courses.substr(prev, Courses.length()));
	cout << "\nLet's see... so far you have taken " << CourseAmt << " " << subject << " class(es), the following:\n";

	while (!CourseStr.empty()) {
		string fullCourseName = subject + CourseStr.front();
		returnList.push_back(fullCourseName);
		cout << fullCourseName << "\n";
		CourseStr.pop_front();
	}
	cout << "\n";
	return returnList;
}

bool PreReqMet(Course potentialCourse, list <Course> taken) {

	if (potentialCourse.preReqAmt == 0) {
		return true;
	}

	list <string> classList = parseClasses(potentialCourse.preReqs);
	list <string>::iterator it;
	list <Course>::iterator takenIt;
	bool reqMet = false;

	for (it = classList.begin(); it != classList.end(); it++) {
		reqMet = false;

		for (takenIt = taken.begin(); takenIt != taken.end(); takenIt++) {
			if (*it == (*takenIt).subject + (*takenIt).courseNum) {

				reqMet = true;
				break;
			}
		}
		if (!reqMet)
			return false;
	}

	return true;

}

list <list <Course>> checkCourses(list <string> classesTaken, list <Course> classPool) {
	list <Course> taken, available, preReqNeeded;

	list <string>::iterator it;
	list <Course>::iterator poolIt, removeIt;

	//check for classes that have been taken first, to get prereq's more easy
	for (it = classesTaken.begin(); it != classesTaken.end(); it++) {
		for (poolIt = classPool.begin(); poolIt != classPool.end(); poolIt++)
			if (*it == (*poolIt).subject + (*poolIt).courseNum) {
				taken.push_back(*poolIt);
			}
	}

	for (poolIt = taken.begin(); poolIt != taken.end(); poolIt++) {
		for (removeIt = classPool.begin(); removeIt != classPool.end(); removeIt++) {
			if ((*poolIt).courseNum == (*removeIt).courseNum && (*poolIt).subject == (*poolIt).subject) {
				classPool.erase(removeIt);
				break;
			}
		}
	}

	for (poolIt = classPool.begin(); poolIt != classPool.end(); poolIt++) {
		if (PreReqMet(*poolIt, taken))
			available.push_back(*poolIt);
		else
			preReqNeeded.push_back(*poolIt);
	}

	list <list<Course>> diffLists;
	diffLists.push_back(taken);
	diffLists.push_back(available);
	diffLists.push_back(preReqNeeded);

	return diffLists;
}
