/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#include "CourseList.h"

using namespace std;

const int CAP = 10;

// CourseList
CourseList::CourseList()
{
	courseList.reserve(CAP);
}

// Overloaded constructor
CourseList::CourseList(int capacity)
{
	courseList.reserve(capacity);
}

// Copy constructor
CourseList::CourseList(const CourseList& rhs)
{
	courseList = rhs.courseList;
}

// addCourse
void CourseList::addCourse(const Course& course)
{
	if (courseList.size() == courseList.capacity())
	{
		courseList.reserve(courseList.capacity() * 2);
	}
	courseList.push_back(course);
}

// getCourseUnits
double CourseList::getCourseUnits(const string& prefix,
	int courseNo) const
{
	for (Course c : courseList)
	{
		if (c.getCoursePrefix() == prefix && c.getCourseNo() == courseNo)
		{
			return c.getCourseUnits();
		}
	}
	return 0;
}

// searchCourse
bool CourseList::searchCourse(const string& prefix, int courseNo) const
{
	for (Course c : courseList)
	{
		if (c.getCoursePrefix() == prefix && c.getCourseNo() == courseNo)
		{
			return true;
		}
	}
	return false;
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& rhs)
{
	if (&rhs != this)
	{
		courseList = rhs.courseList;
	}
	else
	{
		cerr << "Self-Assignment attempted." << endl;
	}
	return *this;
}

// Ramy Meng
// printCourseByUnits
void CourseList::printCourseByUnits(double units) const
{
	cout << setw(15) << left << "Course Name"
		<< setw(10) << left << "Prefix"
		<< setw(10) << left << "CourseNo" << "Units" << endl;
	bool found = false;
	for (Course c : courseList)
	{
		if (c.getCourseUnits() == units)
		{
			cout << setw(15) << left << c.getCourseName()
				<< setw(10) << left << c.getCoursePrefix()
				<< setw(10) << left << c.getCourseNo()
				<< static_cast<int>(units) << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << endl << "No courses with " << units << " unit(s) exist"
			<< endl;
	}
	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
CourseList::~CourseList() { }