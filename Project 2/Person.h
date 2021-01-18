/****************************
	CodeX

	Htet, Niall
	Meng, Ramy
	Park, Juyoung

	CS A250 - Fall 2020

	Project 1
****************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	// default constructor
	Person();

	// overloaded constructor
	Person(const std::string& firstName, const std::string& lastName);

	// setName
	void setName(const std::string& firstName, const std::string& lastName);

	// getLastName
	std::string getLastName() const;

	// printName
	void printName() const;

	// destructor
	~Person();

private:
	std::string firstName;
	std::string lastName;
};

#endif 