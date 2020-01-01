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
	Movie(string movieName, int movieLength, string movieLanguage, int theaterNum);
	string getName() const;
	int getLength() const;
	string getLanguage() const;
	int getTheaterNum() const;
	int getTicketPrice() const;
	BOOL addScreening(int day, int screeningTime);
	int getNextScreening(int day, int time) const;

private:
	static int m_ticketPrice;
	string m_movieName;
	int m_movieLength; //in minutes
	string m_movieLanguage;
	int m_theaterNum; //we assume that in one theater there is only one movie per week
	Mat m_streamingTimesMat;

};

#endif