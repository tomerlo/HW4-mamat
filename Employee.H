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
	Employee (string workerName, int workerSalary, string* workHours);
	string getName() const;
	int getSalary() const;
	int calcWeeklySalary() const;
private:
	string m_name;
	int m_salary;
	string m_workHours[7];
};

#endif