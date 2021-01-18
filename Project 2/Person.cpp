/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#include "Person.h"

using namespace std;

// default constructor
Person::Person() : firstName("N/A"), lastName("N/A") { }

// overloaded constructor
Person::Person(const string& firstName, const string& lastName)
	: firstName(firstName), lastName(lastName) { }

// setName
void Person::setName(const string& firstName, const string& lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

// getLastName
string Person::getLastName() const
{
	return lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName;
}

// destructor
Person::~Person() { }