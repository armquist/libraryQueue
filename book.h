#ifndef Booklist_h
#define Booklist_h
#include <iostream>
#include <queue>
#include <string>
#include "Employee.h"
#include "Date.h"

class book {
public:
	book();
	book(const string& bookName);
	~book();
	void addToCirculation(const Date& date);
	void setArchived(const Date& date);
	Date get_start_date();
	void set_start_date(Date theDate);
	void set_end_date(Date theDate);
	Date get_end_date();
	string getName();
	void add_employee(employee*& personnel);
	void passOn(const Date& passDate);
	bool getArchived();

private:
	queue<employee*> waitingEmployees;
	string name;
	bool archived;
	Date start_date;
	Date end_date;
	Date lastPass;
};
#endif /* Booklist_h */