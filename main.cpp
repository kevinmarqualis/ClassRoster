#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Kevin,McBride,kmcbr50@wgu.edu,25,40,30,21,SOFTWARE" 
	};

	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Language Used: C++" << endl;
	cout << "Name: Kevin McBride, ID: 010009106" << endl;
	cout << endl;
	cout << endl;

	Roster classRoster; // create instance of Roster
	const int classSize = 5;

	// add each student to roster
	for (int i = 0; i < classSize; i++)
	{
		classRoster.parse(studentData[i]);
	}

	// print all
	cout << "Printing All Students" << endl;
	classRoster.printAll();
	cout << endl;

	// print invalid emails
	cout << "Printing Invalid Emails" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	// print average days in course
	cout << "Printing Average Days in Course" << endl;
	for (int i = 0; i <= classRoster.index; i++)
	{
		string id = classRoster.classRosterArray[i]->getStudentId();
		classRoster.printAverageDaysInCourse(id);
	}
	cout << endl;

	// print by program SOFTWARE
	cout << "Printing by Degree Program(SOFTWARE)" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	cout << endl;

	// remove and print all to check, try second removal
	cout << "Removing Student" << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3");

	classRoster.~Roster();
	return 0;
}