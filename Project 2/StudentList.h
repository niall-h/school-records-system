/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <list>
#include <map>

class StudentList
{
public:
	// default constructor
	StudentList();

	// Copy constructor
	StudentList(const StudentList& other);

	// addStudent
	void addStudent(const Student& student);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int studentID) const;

	// printStudentsByCourse
	void printStudentsByCourse(const std::string& prefix, int courseNo) const;

	// printStudentByName
	void printStudentByName(const std::string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold() const;

	// printAllStudents
	void printAllStudents() const;

	// Juyoung Park
	// filterByGpa
	void filterByGpa(double gpa) const;

	// overloaded operator=
	StudentList& operator=(const StudentList& rhs);

	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

private:
	std::list<Student>* studentList;

};

#endif

