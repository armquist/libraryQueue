
#include "stdafx.h"
#include "book.h"

using namespace std;

book::book(const string& bookName) { //Constructor if appropriate arguments are entered
	name = bookName;
	archived = false;
}

book::book() {  //Constructor if no arguments are entered
	name = "none";
	start_date = Date(2000, 1, 1, DateFormat::US);
	end_date = Date(2000, 1, 1, DateFormat::US);
	lastPass = start_date;
	archived = false;
}

book::~book() { //Destructor

}

string book::getName() { //will return name of book
	return name;
}

void book::pushToQueue(employee*& personnel) {  //will push employee to priority queue O(1)
	theQueue.push(personnel);
}

void book::setArchived(const Date& date) { //will set archive flag on book and set end date for book
	archived = true;
	end_date = date;
}

void book::passOn(const Date& passDate) { //will finish book passing using elements from within the class: O(1)
	employee *mostNeeded; //highest priority employee
	employee *otherEmployee; //employee at top after mostNeeded gets popped
	cout << "Book " << name << " has been passed from " << theQueue.get_top()->getName(); //user feedback
	mostNeeded = pop_max(); //pos highest priority item
	mostNeeded->setRetainTime(passDate, lastPass); //sets the time user had book
	if (theQueue.isEmpty()) { //pass to archives once queue is empty
		setArchived(passDate);
		cout << " to " << "the Archives" << " on " << end_date << endl;
	}
	else {	//get employee at top of queue and set their wait time, set the time the book was passed
		otherEmployee = get_top();
		otherEmployee->setWaitTime(start_date, passDate);
		lastPass = passDate;
		cout << " to " << theQueue.get_top()->getName() << " on " << lastPass << endl; //user feedback
	}
}

void book::set_start_date(Date theDate) { //will set the date that the book is circulated
	start_date = theDate;
	lastPass = theDate;
}

bool book::getArchived() { //will get archive flag
	return archived;
}

employee* book::pop_max() { //function inherited from prorityQueue
	return theQueue.pop_max();
}

employee* book::get_top() { //function inherited from prorityQueue
	return theQueue.get_top();
}
