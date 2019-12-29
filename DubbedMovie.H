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

	DubbedMovie(int DubbedTheaterNum);
	BOOL addHebrewScreening(int day, int screeningTime);
	int getHebrewTheaterNum() const;
	int getNextHebrewScreening(int day, int time) const;

private:

	int m_TheaterHebrewNum;
	Mat m_streamingDubbedTimesMat(7, MAX_SCREENINGS_PER_DAY);

};


#endif