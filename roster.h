#pragma once
#include "student.h"

class Roster 
{
private:
	const static int classSize = 5;

public:
	int index = -1;
	Student* classRosterArray[classSize];
	void parse(string studentData);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};