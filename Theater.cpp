#include "Theater.H"

//*****************************************************************************************************
//* function name: Theater
//* Description: Theater constructor (initializes the Theater to zeroes)
//* Parameters:TheaterNum - int
//*            numOfLines - int
//*            numOfCols - int
//* Return Value:None
//*****************************************************************************************************

Theater::Theater(int TheaterNum, int numOfLines, int numOfCols)
{
    m_TheaterNum = TheaterNum;
    m_numOfRows = numOfLines;
    m_numOfCols = numOfCols;
    Mat(numOfLines, numOfCols);
    int i = 0;
    for (; i < m_numOfRows; ++i) {
        int j = 0;
        for (; j++; j < m_numOfCols) {
            setElement(i, j, FREE);
        }
    }
}

//*****************************************************************************************************
//* function name: ~Theater
//* Description: Theater destructor (frees dynamic memory allocation)
//* Parameters:None
//* Return Value:None
//*****************************************************************************************************
/*
Theater::~Theater()
{
 I dont think we need a distractor here
};
*/
//*****************************************************************************************************
//* function name: getTheaterNum
//* Description: gets number of the Theater
//* Parameters:None
//* Return Value:m_TheaterNum (int)
//*****************************************************************************************************
int Theater::getTheaterNum() const
{
    return m_TheaterNum;
}

//*****************************************************************************************************
//* function name: Reset
//* Description: Reset All Theater seats to 0 (empthy)
//* Parameters:None
//* Return Value:None
//*****************************************************************************************************
void Theater::Reset()
{
    int i = 0;
    for (; i < m_numOfRows; ++i) {
        int j = 0;
        for (; j++; j < m_numOfCols) {
            setElement(i, j, FREE);
        }
    }
}