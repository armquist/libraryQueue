#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "stdafx.h"
#include "date.h"
#include <string>
#include <queue>

using namespace std;
//template <typename T> causes crashes when put into .cpp
class employee {
private:
	string name;
	int waitTime;
	int retainTime;
public:
	employee();
	employee(string theName, int wTime, int rTime);
//	push(const T&the_data); probably should go in priorityQueue class
//	pop(); probably should go in priorityQueue class
	int getWaitTime();
	int getRetainTime();
	void setRetainTime(int theRetainTime);
	void setWaitTime(int theWaitTime);
	int getPriority();
};

#endif
