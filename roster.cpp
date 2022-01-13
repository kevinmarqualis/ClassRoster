#include "roster.h"

void Roster::parse(string studentData)
{
	// Parse ID
	int nextComma = studentData.find(",");
	string studentId = studentData.substr(0, nextComma);
	// Parse First Name
	int previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	string firstName = studentData.substr(previousComma, nextComma - previousComma);
	// Parse Last Name
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	string lastName = studentData.substr(previousComma, nextComma - previousComma);
	// Parse Email Address
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	string emailAddress = studentData.substr(previousComma, nextComma - previousComma);
	// Parse age and convert to int
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int age = std::stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse1
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse1 = std::stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse2
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse2 = std::stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse3
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse3 = std::stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse Degree Program
	previousComma = nextComma + 1;
	string program = studentData.substr(previousComma);
	if (program.compare(degreePrograms[0]) == 0)
	{
		DegreeProgram degreeProgram = SECURITY;
	}
	else if (program.compare(degreePrograms[1]) == 0)
	{
		DegreeProgram degreeProgram = NETWORK;
	}
	else
	{
		DegreeProgram degreeProgram = SOFTWARE;
	}
	
	add()

}
