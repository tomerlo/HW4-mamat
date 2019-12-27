#pragma once
#ifndef _THEATER_H_
#define _THEATER_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Mat.H"
#include "Proj.H"


class Theater : public Mat 
{
public:
	Theater(int TheaterNum, int numOfLines, int numOfCols);
	//~Theater(); I dont think we need a distractor here
	int getTheaterNum() const;
	void Reset();
private:
	int m_numOfRows;
	int m_numOfCols;
	int m_TheaterNum;
};


#endif