/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#include "Course.h"

using namespace std;

// default constructor
Course::Course() : courseNo(0), courseUnits(0.0) { }

// setCourseInfo
void Course::setCourseInfo(const string& name, const string& prefix,
	int number, double units)
{
	courseName = name;
	coursePrefix = prefix;
	courseNo = number;
	courseUnits = units;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCoursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix;
}

// getCourseNo
int Course::getCourseNo() const
{
	return courseNo;
}

// getCourseUnits
double Course::getCourseUnits() const
{
	return courseUnits;
}

// printCourseInfo
void Course::printCourseInfo() const
{
	cout << coursePrefix << " " << courseNo;
	cout << setw(8) << right << fixed << setprecision(2)
		<< courseUnits;
}

// overloaded binary operator
bool Course::operator<(const Course& rhs) const
{
	return (this->coursePrefix < rhs.coursePrefix);
}

// destructor;
Course::~Course() { }