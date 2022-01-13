#pragma once
#include "student.h"

class Roster 
{
private:
	Student* classRosterArray[5];

public:
	void parse(string item);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};