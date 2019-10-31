#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

#include "stdafx.h"
#include "employee.h"
#include "book.h"
#include <string>
#include <list>
#include "date.h"

using namespace std;

class library {
public:
	library(); //constructor
	~library();//destructor

	void add_employee(string name); // adds the name of the employee
	void add_book(string bookName); // adds the book
	void pass_on(string bookName, Date& book_pass); // passes the book from one employee to another
	void circulate_book(string bookName, Date& date_cir); // Puts the book into circulation

private:
	list <book> books_archived; // list of books at the end of circulation 
	list <book> books_circulated; // list of books in circulation
	list <employee*> employees; // list of the employees
};

#endif
