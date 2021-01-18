/****************************
	CodeX

	Htet, Niall (Main.cpp)
	Meng, Ramy (Selection 6)
	Park, Juyoung (Selection 7)

	CS A250 - Fall 2020

	Project 1
****************************/

#include "InputHandler.h"
#include "CourseList.h"
#include "StudentList.h"
#include "ExceptionHandler.h"

#include<algorithm> 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void displayMenu();
void processChoice(const StudentList& studentList,
	const CourseList& courseList);

int main()
{
	system("Color 1A");
	CourseList courseList;
	StudentList studentList;

	readData(courseList, studentList);
	displayMenu();
	processChoice(studentList, courseList);

	//cout << endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Search student by last name" << endl;
	cout << "    2: Print student information" << endl;
	cout << "    3: Print all students" << endl;
	cout << "    4: Print students by course" << endl;
	cout << "    5: Print students on hold" << endl;
	cout << "    6: Print all courses with specified number of units" << endl;
	cout << "    7: Filter students by GPA" << endl;
	cout << "    8: Exit" << endl;
}

void processChoice(const StudentList& studentList,
	const CourseList& courseList)
{
	int id = 0, courseNo = 0;
	double units = 0.0, gpa = 0.0;
	bool valid = false;
	string inputID, inputCourseNo, input, coursePrefix, lastName;
	ExceptionHandler exception;

	cout << "\nEnter your selection: ";
	getline(cin, input);
	int selection = exception.validateSelection(input);
	cout << endl;

	cout << fixed << showpoint << setprecision(2); 

	while (selection != 8)
	{
		string fName, lName;

		switch (selection)
		{

			// Search student by last name
		case 1:
			cout << "  => Please enter the student's last name: ";
			getline(cin, lastName);
			exception.lastNameValid(lastName);
			cout << endl;
			if (exception.lastNameValid(lastName))
				studentList.printStudentByName(lastName);
			else
				cout << "Incorrect input. Try again.\n";
			cout << endl;
			
			break;

			// Print student information
		case 2:
			cout << "  => Please enter student's ID: ";
			getline(cin, input);
			cout << endl;
			if(exception.validateID(input, id))
				studentList.printStudentByID(id);
			cout << endl;

			break;

			// Print all students
		case 3:
			studentList.printAllStudents();
			cout << endl;

			break;

			// Print students by course 
		case 4:
			cout << "  => Please enter the course prefix (CSC, HIS, etc.): ";
			getline(cin, coursePrefix);
			cout << "  => Please enter the course number: ";
			getline(cin, inputCourseNo);
			cout << endl;
			valid = exception.validateCoursePrefix(coursePrefix);			
			if(exception.validateCourseNo(inputCourseNo, courseNo) && valid)
			{				
				if (!courseList.searchCourse(coursePrefix, courseNo))
					cout << "This course is not in the catalog." << endl;
				else
					studentList.printStudentsByCourse(coursePrefix, courseNo);
			}
			cout << endl;

			break;

			// Print students on hold
		case 5:
			studentList.printStudentsOnHold();
			cout << endl;

			break;

			// Print all courses with specified number of units
		case 6:
			cout << "  => Enter number of units: ";
			cin >> units;
			cin.ignore();
			cout << endl;
			courseList.printCourseByUnits(units);
			cout << endl;

			break;

			// Filter by GPA
		case 7:
			cout << "  => Enter GPA to filter by: ";
			cin >> gpa;
			cin.ignore();
			cout << endl;
			studentList.filterByGpa(gpa);
			cout << endl;

			break;

			// Incorrect selection
		default:
			cout << "  => Invalid entry. Please try again.\n\n";

			break;
		}

		cout << "  => ";
		system("Pause");
		cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		displayMenu();

		cout << "\nEnter your selection: ";		
		getline(cin, input);
		selection = exception.validateSelection(input);
		cout << endl;
	}

	if (selection == 8)
		cout << "Thank you for using our software! Good-bye!\n";
	cout << endl;
}