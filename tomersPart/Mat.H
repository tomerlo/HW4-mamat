#pragma once
#ifndef _MAT_H_
#define _MAT_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Mat
{
public:
	Mat(int numOfLines, int numOfCols);

private:
	int m_numOfLines;
	int m_numOfCols;
};


#endif