#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "stdafx.h"
#include "date.h"
#include <string>

using namespace std;

class employee {
private:
	//privatizing specific employee information
	string name;
	int waitTime;
	int retainTime;
public:
	//getting and setting the employee
	employee();
	employee(string theName);
	
	//getting name for employee
	string getName();
	
	//calculating retain time based on our date class
	void setRetainTime(Date currentDate, Date lastPass);
	
	//calculating our wait time based on our date class
	void setWaitTime(Date firstDate, Date currentDate);
	
	//setting the priority based on the wait and retain time
	int getPriority();
};

#endif
