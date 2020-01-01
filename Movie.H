#pragma once
#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Mat.H"
#include "Proj.H"

using namespace std;

class Movie
{
public:
	Movie(char* movieName, int movieLength, char* movieLanguage, int theaterNum);
	virtual ~Movie(); //polymorphic type
	char* getName() const;
	int getLength() const;
	char* getLanguage() const;
	int getTheaterNum() const;
	static int getTicketPrice();
	BOOL addScreening(int day, int screeningTime);
	int getNextScreening(int day, int time) const;

private:
	static int m_ticketPrice;
	char* m_movieName;
	int m_movieLength; //in minutes
	char* m_movieLanguage;
	int m_theaterNum; //we assume that in one theater there is only one movie per week
	Mat *m_streamingTimesMat;

};

#endif