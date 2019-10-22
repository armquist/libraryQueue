
#include "stdafx.h"
#include "book.h"

using namespace std;

book::book(const string& bookName) {
	name = bookName;
	archived = false;
}

book::book() {
	name = "none";
	start_date = Date(2000, 1, 1, DateFormat::US);
	end_date = Date(2000, 1, 1, DateFormat::US);
	lastPass = start_date;
	archived = false;
}

book::~book() {

}

void book::addToCirculation(const Date& date) {
	start_date = date;
	lastPass = date;
}

void book::add_employee(employee*& personnel) {
	waitingEmployees.push(personnel);
}

void book::setArchived(const Date& date) {
	archived = true;
	end_date = date;
}

void book::passOn(const Date& passDate) {
	employee* temp = waitingEmployees.front();
	waitingEmployees.pop();
	temp->setRetainTime(lastPass - passDate);
	if (waitingEmployees.empty) {
		setArchived(passDate);
	}
	else {
		waitingEmployees.front()->setWaitTime(start_date - passDate);
		lastPass = passDate;
	}
	

}
 
Date book::get_start_date() {
	return start_date;
}

Date book::get_end_date() {
	return end_date;
}

bool book::getArchived() {
	return archived;
}