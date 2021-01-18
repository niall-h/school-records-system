/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#include "StudentList.h"

using namespace std;

// default constructor
StudentList::StudentList()
{
	studentList = new list<Student>();
}

// Copy constructor
StudentList::StudentList(const StudentList& other)
{
	studentList = new list<Student>();
	studentList->assign(other.studentList->begin(), other.studentList->end());
}

// addStudent
void StudentList::addStudent(const Student& student)
{
	studentList->push_back(student);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}


// printStudentByID
void StudentList::printStudentByID(int studentID) const
{
	if (studentList->empty())
	{
		cerr << "List is empty" << endl;
	}
	else
	{
		bool found = false;
		auto iter = studentList->cbegin();
		auto end = studentList->cend();
		while (iter != end && !found)
		{
			if (iter->getID() == studentID)
			{
				iter->printStudentInfo();
				found = true;
			}
			++iter;
		}

		if (!found)
		{
			cout << "No student with ID " << studentID
				<< " found in the list." << endl;
		}
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& prefix,
	int courseNo) const
{
	if (studentList->empty())
	{
		cerr << "List is empty" << endl;
	}
	else
	{
		bool found = false;

		for (Student s : *studentList)
		{
			if (s.getNumberOfCourses() > 0 &&
				s.courseIsCompleted(prefix, courseNo))
			{
				s.printStudent();
				cout << endl;
				found = true;
			}
		}

		if (!found)
		{
			cout << "No student completed " << courseNo << endl;
		}
	}
}

// printStudentByName
void StudentList::printStudentByName(const string& lastName) const
{
	if (studentList->empty())
	{
		cerr << "List is empty" << endl;
	}
	else
	{
		bool found = false;

		for (Student s : *studentList)
		{
			if (s.getLastName() == lastName)
			{
				s.printStudent();
				cout << endl;
				found = true;
			}
		}
		
		if (!found)
		{
			cout << "No student with last name " << lastName
				<< " is in the list." << endl;
		}
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const
{
	if (studentList->empty())
	{
		cerr << "No students in the list." << endl;
	}
	else
	{
		bool found = false;

		for (Student s : *studentList)
		{
			if (!s.isTuitionPaid())
			{
				s.printStudentInfo();
				found = true;
			}
		}

		if (!found)
		{
			cout << "There are no students on hold." << endl;
		}
	}
}

// printAllStudents
void StudentList::printAllStudents() const
{
	for (Student s : *studentList)
	{
		s.printStudentInfo();
	}
}

// Juyoung Park
// filterByGpa
void StudentList::filterByGpa(double gpa) const
{
	if (studentList->empty())
	{
		cerr << "No students in the list." << endl;
	}
	else
	{
		cout << "Student GPA" << endl;
		
		multimap<double, Student> studentMap;
		for (Student s : *studentList)
		{
			if (s.getGpa() >= gpa)
			{
				studentMap.insert(make_pair(s.getGpa(), s));
			}
		}

		if (!studentMap.empty())
		{
			for (auto iter = studentMap.crbegin(); 
				iter != studentMap.crend(); ++iter)
			{
				iter->second.printName();
				cout << " " << iter->first << endl;
			}
		}
		else
		{
			cout << "No student over GPA " << gpa 
				<< " is in the list." << endl;
		}
	}
}

// overloaded operator=
StudentList& StudentList::operator=(const StudentList& rhs)
{
	if (&rhs != this)
	{
		studentList->assign(rhs.studentList->begin(), rhs.studentList->end());
	}
	else
	{
		cerr << "Attempted assignment to itself";
	}
	return *this;
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	studentList->clear();
}

// destructor
StudentList::~StudentList()
{
	delete studentList;
	studentList = nullptr;
}
