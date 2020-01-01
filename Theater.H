#ifndef THEATER_H
#define THEATER_H
#include "Mat.H"


class Theater : public Mat {
public:
	Theater(int TheaterNum, int numOfLines, int numOfCols);
	int getTheaterNum() const;
	void Reset();
protected:
	int m_numOfRows;
	int m_numOfCols;
	int m_TheaterNum;
};

#endif