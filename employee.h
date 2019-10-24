#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "stdafx.h"
#include "date.h"
#include <string>
#include <queue>

using namespace std;

class employee {
private:
	string name;
	int waitTime;
	int retainTime;
public:
	employee();
	employee(string theName);
	int getWaitTime();
	int getRetainTime();
	void setRetainTime(int theRetainTime);
	void setWaitTime(int theWaitTime);
	int getPriority();
};

#endif