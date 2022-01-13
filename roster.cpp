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
	int age = stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse1
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse1 = stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse2
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse2 = stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse DaysInCourse3
	previousComma = nextComma + 1;
	nextComma = studentData.find(",", previousComma);
	int daysToCompleteCourse3 = stoi(studentData.substr(previousComma, nextComma - previousComma));
	// Parse Degree Program
	previousComma = nextComma + 1;
	DegreeProgram degreeProgram;
	string program = studentData.substr(previousComma);

	if (program.compare(degreePrograms[0]) == 0)
	{
		degreeProgram = SECURITY;
	}
	else if (program.compare(degreePrograms[1]) == 0)
	{
		degreeProgram = NETWORK;
	}
	else
	{
		degreeProgram = SOFTWARE;
	}
	
	// add student to roster
	add(studentId, firstName, lastName, emailAddress, age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3, degreeProgram);
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3 };

	classRosterArray[++index] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::remove(string studentId)
{
	bool remove = false;
	for (int i = 0; i <= Roster::index; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			remove = true;
			if (i < classSize - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[classSize - 1];
				classRosterArray[classSize - 1] = temp;
			}
			Roster::index--;
		}
	}
	if (!remove)
	{
		cout << "Student " << studentId << " not found" << endl;
	}
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::index; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::index; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= Roster::index; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			cout << classRosterArray[i]->getStudentId() << ": ";
			cout << (classRosterArray[i]->getDaysToCompleteCourse()[0] + classRosterArray[i]->getDaysToCompleteCourse()[1] + classRosterArray[i]->getDaysToCompleteCourse()[2]) / 3.0 << endl;
		}
	}
}

// include at('@') and period('.'); not include a space(' ')
void Roster::printInvalidEmails()
{
	bool invalid = false;
	for (int i = 0; i <= Roster::index; i++)
	{
		string email = (classRosterArray[i]->getEmail());
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
		{
			invalid = true;
			cout << "Invalid email found: " << email << endl;
		}
	}

	if (!invalid)
	{
		cout << "No Invalid Emails Found";
	}
}

Roster::~Roster()
{
	for (int i = 0; i < classSize; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

