
#include "stdafx.h"
#include "employee.h"

using namespace std;

//getting employee information to initiate
employee::employee() {
	name = "none";
	waitTime = 0;
	retainTime = 0;
}

// intitializing employee information for employee information
employee::employee(string theName) {
	name = theName;
	waitTime = 0;
	retainTime = 0;
}

//calculating wait time for employee
void employee::setWaitTime(Date firstDate, Date currentDate) {
	waitTime = currentDate - firstDate;
}

//calculating the retain time for employee
void employee::setRetainTime(Date currentDate, Date lastPass) {
	retainTime = currentDate - lastPass;
}

//setting the priority for employee based on wait and retain time calculation
int employee::getPriority() {
	return waitTime - retainTime;
}

//making employee name available
string employee::getName() {
	return name;
}
