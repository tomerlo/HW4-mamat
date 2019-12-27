#pragma once
#ifndef _DUBBEDMOVIE_H_
#define _DUBBEDMOVIE_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Mat.H"
#include "Proj.H"
#include "Movie.H"

class DubbedMovie : public Movie
{
public:
	DubbedMovie(string movieName, int movieLength, string movieLanguage, int theaterNum);
	~DubbedMovie();
	BOOL addHebrewScreening() const;
	int getHebrewTheaterNum() const;
	BOOL getNextHebrewScreening() const;
private:
	int m_numOfRows;
	int m_numOfCols;
	int m_TheaterNum;
};


#endif