#include "Mat.H"
#include "DubbedMovie.H"
using namespace std;

//*****************************************************************************************************
//* function name: DubbedMovie
//* Description: DubbedMovie constructor (initializes the DubbedMovie to zeroes)
//* Parameters:movieName - string,
//*            movieLength - int,
//*			   movieLanguage - string
//*			   theaterNum - int
//*			   DubbedTheaterNum - int
//* Return Value:None
//*****************************************************************************************************


DubbedMovie::DubbedMovie(char* movieName, int movieLength, char* movieLanguage, int theaterNum, int DubbedTheaterNum): Movie (movieName, movieLength, movieLanguage, theaterNum),
 m_TheaterHebrewNum(DubbedTheaterNum)
{
	m_streamingDubbedTimesMat = new Mat(7, MAX_SCREENINGS_PER_DAY);
	int i = 0, j = 0;
	for (; i < 7; i++) {
		for (; j < MAX_SCREENINGS_PER_DAY; j++) {
			m_streamingDubbedTimesMat->setElement(i, j, 0);
		}
	}
};

//*****************************************************************************************************
//* function name: ~DubbedMovie
//* Description: DubbedMovie destructor
//* Parameters:None
//* Return Value: None
//*****************************************************************************************************
DubbedMovie::~DubbedMovie()
{
	delete m_streamingDubbedTimesMat;
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
	if (day < 1 || day>7 || screeningTime < 1 || screeningTime>24) {
		return FALSE;
	}
	if (m_streamingDubbedTimesMat->getElement(day, MAX_SCREENINGS_PER_DAY) != 0) {
		return FALSE; //because it means the day is full of screenings
	}
	int j = 0;
	for (; j < MAX_SCREENINGS_PER_DAY && (m_streamingDubbedTimesMat->getElement(day,j)) != 0; j++) 
	{//check if
		//there is a screening in the same day which haven't finished yet
		if (m_streamingDubbedTimesMat->getElement(day, j) + getLength() > screeningTime) { //found a movie which haven't finished yet 
			return FALSE;
		}
	}
	//if we reached here it means we found an empty place and all previous screenings have finished already
	m_streamingDubbedTimesMat->setElement(day, j, screeningTime); //put it in the mat
	return TRUE;
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
	if (day < 1 || day>7 || time < 1 || time>24) {
		return 0;
	}
	int j = 0;
	for (; j < MAX_SCREENINGS_PER_DAY; j++) {
		if (m_streamingDubbedTimesMat->getElement(day, j) != 0 &&
			(m_streamingDubbedTimesMat->getElement(day, j) <= time || m_streamingDubbedTimesMat->getElement(day, j) + getLength() <= time)) {
			continue; //current screening was started or finished already
		}
		break; //found a screening which haven't started yet or reached a 0 in m_streamingTimesMat
	}
	if (j == MAX_SCREENINGS_PER_DAY) {//means all movies were started or finished before 'time'
		return 0;
	}
	else if (m_streamingDubbedTimesMat->getElement(day, j) == 0 && m_streamingDubbedTimesMat->getElement(day, j) <= time) {//means all screening times available are in the past
		return 0;
	}
	else {
		return m_streamingDubbedTimesMat->getElement(day, j); //valid next screening time
	}
};


//*****************************************************************************************************
//* function name: 
//* Description: gets movie theater number
//* Parameters:None
//* Return Value: m_theaterNum - int
//*****************************************************************************************************
int DubbedMovie::getHebrewTheaterNum() const
{
	return m_TheaterHebrewNum;
};