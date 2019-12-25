#include "Mat.H"

//*****************************************************************************************************
//* function name: Mat
//* Description: Mat constructor (initializes the mat to zeroes)
//* Parameters:numOfLines - int
//*            numOfCols - int
//* Return Value:None
//*****************************************************************************************************

Mat::Mat(int numOfLines, int numOfCols)
{
    if (numOfLines < 0 || numOfCols < 0) {
        return;
    }
    m_numOfCols = numOfCols;
    m_numOfRows = numOfLines;
    int** array = new int* [m_numOfRows];
    int i = 0;
    for (; i < m_numOfRows; ++i) {
        array[i] = new int[m_numOfCols];
        int j = 0;
        for (; j++; j < m_numOfCols) {
            array[i][j] = 0;
        }
    }
};

//*****************************************************************************************************
//* function name: ~Mat
//* Description: Mat destructor (frees dynamic memory allocation)
//* Parameters:None
//* Return Value:None
//*****************************************************************************************************
Mat::~Mat()
{
    int i = 0, j = 0;
    for (; i < m_numOfRows; i++) {
        for (; j < m_numOfCols; j++) {
            delete array[i][j];
        }
        delete a[i];
    }
};

//*****************************************************************************************************
//* function name: getRowsNum
//* Description: gets number of rows in a mat
//* Parameters:None
//* Return Value:m_numOfRows (int)
//*****************************************************************************************************
int Mat::getRowsNum() const
{
    return m_numOfRows;
};

//*****************************************************************************************************
//* function name: getColumnsNum
//* Description: gets number of cols in a mat
//* Parameters:None
//* Return Value: m_numOfCols - int
//*****************************************************************************************************
int Mat::getColumnsNum() const
{
    return m_numOfCols;
};

//*****************************************************************************************************
//* function name: getElement
//* Description: gets number of cols in a mat
//* Parameters:rowIndex - int,
//*            colIndex - int
//* Return Value: element's value in mat - int
//*****************************************************************************************************
int Mat::getElement(int rowIndex, int colIndex) const
{
    if (rowIndex < 0 || colIndex < 0) {
        return -1; //fail
    }
    return array[rowIndex-1][colIndex-1];   //because index starts from 1 (not from 0)
};

//*****************************************************************************************************
//* function name: setElement
//* Description: sets a val in a place in a mat
//* Parameters:rowIndex - int,
//*            colIndex - int,
//*            val - int
//* Return Value: None
//*****************************************************************************************************

void Mat::setElement(int rowIndex, int colIndex, int val)
{
    if (rowIndex < 0 || colIndex < 0 || rowIndex>m_numOfRows || colIndex>m_numOfCols) {
        return; //fail
    }
    array[rowIndex - 1][colIndex - 1] = val; //because index starts from 1 (not from 0)
    return;
};