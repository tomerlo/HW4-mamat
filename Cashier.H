#pragma once
#ifndef _CASHIER_H_
#define _CASHIER_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Employee.H"
#include "DubbedMovie.H"
#include "Theater.H"


class Cashier : public Employee
{
public:
	Cashier(char* workerName, int workerSalary, char* workHours[7]);
	int getTicketProfit() const;
	int sellTickets(Movie* pmovie, Theater* ptheater, BOOL isDubbed, int numOfTickets, int wantedRow, int mostRightCol);

private:
	int m_ticketProfit;
};

#endif