#ifndef _MAT_H_
#define _MAT_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Proj.H"

class Mat
{
public:
	Mat();
	Mat(int numOfLines, int numOfCols);
	~Mat();
	int getRowsNum() const;
	int getColumnsNum() const;
	int getElement(int rowIndex, int colIndex) const;
	void setElement(int rowIndex, int colIndex, int val);
private:
	int m_numOfRows;
	int m_numOfCols;
	int** m_array;
};


#endif