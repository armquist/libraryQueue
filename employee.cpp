
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

void employee::setWaitTime(int theWaitTime) {
	waitTime = theWaitTime;
}

void employee::setRetainTime(int theRetainTime) {
	retainTime = theRetainTime;
}

int employee::getPriority() {
	return waitTime - retainTime;
}

