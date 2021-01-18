/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <vector>

class CourseList
{
public:
	// CourseList
	CourseList();

	// Overloaded constructor
	CourseList(int capacity);

	// Copy constructor
	CourseList(const CourseList& rhs);

	// addCourse
	void addCourse(const Course& course);

	// getCourseUnits
	double getCourseUnits(const std::string& prefix, int courseNo) const;

	// searchCourse
	bool searchCourse(const std::string& prefix, int courseNo) const;

	// overloaded operator=
	CourseList& operator=(const CourseList& rhs);

	// Ramy Meng
	// printCourseByUnits
	void printCourseByUnits(double units) const;

	// destructor
	~CourseList();

private:
	std::vector<Course> courseList;

};

#endif
