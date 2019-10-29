
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

string book::getName() {
	return name;
}

void book::add_employee(employee*& personnel) {
	waitingEmployees.push_back(personnel);
}

void book::setArchived(const Date& date) {
	archived = true;
	end_date = date;
}

void book::passOn(const Date& passDate) {
	employee*& temp = waitingEmployees.front();
	waitingEmployees.pop_front();
	temp->setRetainTime(lastPass - passDate);
	if (waitingEmployees.empty()) {
		setArchived(passDate);
	}
	else {
		waitingEmployees.front()->setWaitTime(start_date - passDate);
		lastPass = passDate;
	}
}

void book::set_start_date(Date theDate) {
	start_date = theDate;
	lastPass = theDate;
}
void book::set_end_date(Date theDate) {
	end_date = theDate;
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