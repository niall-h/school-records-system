/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#include "Student.h"

using namespace std;

// default constructor
Student::Student()
	: studentID(0), tuitionWasPaid(false), totalCourses(0) { }

// setStudentInfo
void Student::setStudentInfo(const string& firstName,
	const string& lastName, int id, bool tuitionPaid,
	const multimap<Course, char>& courses)
{
	Person::setName(firstName, lastName);
	studentID = id;
	tuitionWasPaid = tuitionPaid;
	totalCourses = static_cast<int>(courses.size());
	coursesCompleted = courses;
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return totalCourses;
}

// getUnitsCompleted
double Student::getUnitsCompleted() const
{
	double units = 0.0;
	for (auto i : coursesCompleted)
	{
		units += (i.first).getCourseUnits();
	}
	return units;
}

// getGpa
double Student::getGpa() const
{
	double gpa = 0.0;
	for (auto i : coursesCompleted)
	{
		switch (i.second)
		{
			case 'A' :
				gpa += (i.first).getCourseUnits() * 4.0;
				break;
			case 'B' :
				gpa += (i.first).getCourseUnits() * 3.0;
				break;
			case 'C' :
				gpa += (i.first).getCourseUnits() * 2.0;
				break;
			case 'D':
				gpa += (i.first).getCourseUnits();
				break;
			case 'F':
				break;
			default :
				cerr << "Invalid Course Grade";
		}
	}
	gpa /= getUnitsCompleted();
	return gpa;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted(const string& prefix, int courseNo) const
{
	for (auto i : coursesCompleted)
	{
		if ((i.first).getCoursePrefix() == prefix &&
			(i.first).getCourseNo() == courseNo)
		{
			return true;
		}
	}
	return false;
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	Person::printName();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << "Student Name: ";
	Student::printName();
	cout << "\n\n";

	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses << "\n\n";

	cout << setw(7) << left << "Course";
	cout << setw(8) << right << "Units";
	cout << setw(10) << right << "Grade" << endl;

	for (auto i : coursesCompleted)
	{
		(i.first).printCourseInfo();
		if (tuitionWasPaid)
		{
			cout << setw(8) << right << i.second << endl;
		}
		else
		{
			cout << setw(10) << right << "***" << endl;
		}
	}
	cout << endl;

	cout << "Total number of unit hours: "
		<< static_cast<int>(getUnitsCompleted()) << endl;

	if (tuitionWasPaid)
	{
		cout << "Current Term GPA: " << getGpa() << "\n\n";
	}
	else
	{
		cout << "*** Grades are being held for not paying the tuition. ***"
			<< "\n\n";
	}

	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
Student::~Student() { }