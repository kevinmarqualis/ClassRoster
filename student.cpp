#include "student.h"

using namespace std;

Student::Student()
{
	this->studentId = -1;
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = -1;
	for (int i = 0; i < 3; i++)
	{
		this->daysToCompleteCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::Security;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentId() { return this->studentId; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysToCompleteCourse() { return this->daysToCompleteCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentId(string id) { this->studentId = id; }
void Student::setFirstName(string name) { this->firstName = name; }
void Student::setLastName(string name) { this->lastName = name; }
void Student::setEmail(string email) { this->emailAddress = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(int daysToCompleteCourse[])
{
	for (int i = 0; i < 3; i++)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}
void Student::setDegreeProgram(DegreeProgram program) { this->degreeProgram = program; }

void Student::print()
{
	std::cout << "Student's Information" << endl;
	std::cout << "Student ID: " << this->getStudentId() << endl;
	std::cout << "Name: " << this->getFirstName() << " " << this->getLastName() << endl;
	std::cout << "Email: " << this->getEmail() << endl;
	std::cout << "Age: " << this->getAge() << endl;
	std::cout << "Days to complete courses: " << this->getDaysToCompleteCourse()[0] << ", ";
	std::cout << this->getDaysToCompleteCourse()[1] << ", ";
	std::cout << this->getDaysToCompleteCourse()[2] << endl;
	std::cout << degreePrograms[this->getDegreeProgram()] << endl;
}
