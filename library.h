#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

#include "stdafx.h"
#include "employee.h"
#include "book.h"
#include <string>
#include <queue>
#include <list>

using namespace std;
template <typename T>
class library {
private:
	list <Book> books_archieved;
	list <Book> books_circulated;
	list <Employees>* employees;
	
	
public:
	Library();
	~Library();

	void add_employee(string name);
	void add_book(string bookName);
	void pass_on(string bookName Date book_pass);
	void circulate_book(string bookName Date date_cir);
};

#endif
