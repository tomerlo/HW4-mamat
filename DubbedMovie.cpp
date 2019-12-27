#include "Mat.H"
#include "DubbedMovie.H"
//*****************************************************************************************************
//* function name: DubbedMovie
//* Description: DubbedMovie constructor (initializes the DubbedMovie to zeroes)
//* Parameters:numOfLines - int
//*            numOfCols - int
//* Return Value:None
//*****************************************************************************************************

DubbedMovie::DubbedMovie(string movieName, int movieLength, string movieLanguage, int theaterNum)
{
    Movie(movieName,movieLength,movieLanguage,theaterNum);
};


//*****************************************************************************************************
//* function name: addScreening
//* Description: Adds a screening time to m_streamingTimesMat
//* Parameters:day - int,
//*			   screeningTime - int
//* Return Value: TRUE (if succeeded) or FALSE (if failed)
//*****************************************************************************************************
BOOL DubbedMovie::addHebrewScreening(int day, int screeningTime)
{

	if (day < 1 || screeningTime < 1 || screeningTime>24) {
		return FALSE;
	}
	if (m_streamingTimesMat[day - 1][MAX_SCREENINGS_PER_DAY - 1] != 0) {
		return FALSE; //because it means the day is full of screenings
	}
	addScreening(day, screeningTime);
};



//*****************************************************************************************************
//* function name: getNextScreening
//* Description: Gets the next screening time available
//* Parameters:day - int,
//*			   time - int
//* Return Value: next screening time (if available) - int, or 0 if there is no next screening time available
//*****************************************************************************************************
int DubbedMovie::getNextHebrewScreening(int day, int time) const
{
	if (day < 1 || screeningTime < 1 || screeningTime>24) {
		return 0;
	}
	getNextScreening(day, time);
};


//*****************************************************************************************************
//* function name: getTheaterNum
//* Description: gets movie theater number
//* Parameters:None
//* Return Value: m_theaterNum - int
//*****************************************************************************************************
int DubbedMovie::getHebrewTheaterNum() const
{
	return m_theaterNum;
};