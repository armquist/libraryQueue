#ifndef Booklist_h
#define Booklist_h
#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "Employee.h"
#include "Date.h"
#include "priorityQueue.h"

class book {
public:
	book(); //Constructor if no arguments are entered
	book(const string& bookName); //Constructor if appropriate arguments are entered
	~book(); //destructor
	void setArchived(const Date& date); //will set archive flag on book and set end date for book
	void set_start_date(Date theDate); //will set the date that the book is circulated
	string getName(); //will return name of book
	void pushToQueue(employee*& personnel); //will push employee to priority queue
	void passOn(const Date& passDate); //will finihs book passing using elements from within the class
	bool getArchived(); //will get archive flag
	employee* pop_max(); //function inherited from prorityQueue
	employee* get_top(); //function inherited from prorityQueue

private:
	string name;
	bool archived;
	Date start_date;
	Date end_date;
	Date lastPass; //last time book was passed
	priorityQueue theQueue; //the priority q6ue6u6e defined for the book
};
#endif /* Booklist_h */