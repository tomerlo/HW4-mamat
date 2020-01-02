#include "Mat.H"
#include "Proj.H"
//*****************************************************************************************************
//* function name: Mat
//* Description: Mat constructor (initializes the mat to zeroes)
//* Parameters:numOfLines - int
//*            numOfCols - int
//* Return Value:None
//*****************************************************************************************************

Mat::Mat(){}

Mat::Mat(int numOfLines, int numOfCols)
{
    m_numOfCols = numOfCols;
    m_numOfRows = numOfLines;
    m_array = new int* [m_numOfRows];
    int i = 0;
    for (; i < m_numOfRows; ++i) {
        m_array[i] = new int[m_numOfCols];
        int j = 0;
        for (;  j < m_numOfCols;j++) {
            m_array[i][j] = 0;
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
        delete m_array[i];
    }
    delete m_array;
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
    if (rowIndex < 1 || colIndex < 1 || rowIndex>m_numOfRows || colIndex>m_numOfCols) {
        return -1; //fail
    }
    return m_array[rowIndex-1][colIndex-1];   //because index starts from 1 (not from 0)
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
    if (rowIndex < 1 || colIndex < 1 || rowIndex>m_numOfRows || colIndex>m_numOfCols) {
        return; //fail
    }
    m_array[rowIndex - 1][colIndex - 1] = val; //because index starts from 1 (not from 0)
    return;
};