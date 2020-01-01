#pragma once
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


using namespace std;

class Employee 
{
public:
	Employee (char* workerName, int workerSalary, char* workHours[7]);
	char* getName() const;
	int getSalary() const;
	int calcWeeklySalary() const;
private:
	char* m_name;
	int m_salary;
	char* m_workHoursBegin;
};

#endif