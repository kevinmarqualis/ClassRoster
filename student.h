#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student 
{
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourse[3];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram program);
	~Student();

	// Getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	// Setters
	void setStudentId(string id);
	void setFirstName(string name);
	void setLastName(string name);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int days[]);
	void setDegreeProgram(DegreeProgram program);

	void print();
};

