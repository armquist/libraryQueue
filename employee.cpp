
#include "stdafx.h"
#include "employee.h"

using namespace std;

employee::employee() {
	name = "none";
	waitTime = 0;
	retainTime = 0;
}

employee::employee(string theName) {
	name = theName;
	waitTime = 0;
	retainTime = 0;
}

int employee::getRetainTime() {
	return retainTime;
}

int employee::getWaitTime() {
	return waitTime;
}

void employee::setWaitTime(Date firstDate, Date currentDate) {
	waitTime = currentDate - firstDate;
}

void employee::setRetainTime(Date currentDate, Date lastPass) {
	retainTime = currentDate - lastPass;
}

int employee::getPriority() {
	return waitTime - retainTime;
}

