#include "Movie.H"

//*****************************************************************************************************
//* function name: Movie
//* Description: Movie constructor
//* Parameters:movieName - string,
//*            movieLength - int,
//*			   movieLanguage - string
//*			   theaterNum - int
//* Return Value: None
//*****************************************************************************************************
using namespace std;
Movie::Movie(char* movieName, int movieLength, char* movieLanguage, int theaterNum) :
	 m_movieLength(movieLength), m_theaterNum(theaterNum)
{
	m_ticketPrice = 35;
	m_streamingTimesMat =new Mat(7, MAX_SCREENINGS_PER_DAY);
	strcpy(m_movieName, movieName);
	strcpy(m_movieLanguage, movieLanguage);
	int i = 0, j = 0;
	for (; i < 7; i++) {
		for (; j < MAX_SCREENINGS_PER_DAY; j++) {
			m_streamingTimesMat->setElement(i, j, 0);
		}
	}
};

//*****************************************************************************************************
//* function name: ~Movie
//* Description: Movie destructor
//* Parameters:None
//* Return Value: None
//*****************************************************************************************************
Movie::~Movie()
{
	delete m_streamingTimesMat;
};

//*****************************************************************************************************
//* function name: getName
//* Description: gets movie name
//* Parameters:None
//* Return Value: m_movieName - string
//*****************************************************************************************************
char* Movie::getName() const
{
	return m_movieName;
};

//*****************************************************************************************************
//* function name: getLength
//* Description: gets movie length in minutes
//* Parameters:None
//* Return Value: m_movieLength - int
//*****************************************************************************************************
int Movie::getLength() const
{
	return m_movieLength;
};

//*****************************************************************************************************
//* function name: getLanguage
//* Description: gets movie language
//* Parameters:None
//* Return Value: m_movieLanguage - string
//*****************************************************************************************************
char* Movie::getLanguage() const
{
	return m_movieLanguage;
};

//*****************************************************************************************************
//* function name: getTheaterNum
//* Description: gets movie theater number
//* Parameters:None
//* Return Value: m_theaterNum - int
//*****************************************************************************************************
int Movie::getTheaterNum() const
{	
	return m_theaterNum;
};

//*****************************************************************************************************
//* function name: getTicketPrice
//* Description: gets movie ticket price
//* Parameters:None
//* Return Value: m_ticketPrice - int
//*****************************************************************************************************
int Movie::getTicketPrice()
{
	return m_ticketPrice;
};

//*****************************************************************************************************
//* function name: addScreening
//* Description: Adds a screening time to m_streamingTimesMat
//* Parameters:day - int,
//*			   screeningTime - int
//* Return Value: TRUE (if succeeded) or FALSE (if failed)
//*****************************************************************************************************
BOOL Movie::addScreening(int day, int screeningTime)
{
	if (day < 1 || day>7 || screeningTime < 1 || screeningTime>24) {
		return FALSE;
	}
	if (m_streamingTimesMat->getElement(day, MAX_SCREENINGS_PER_DAY) != 0) {
		return FALSE; //because it means the day is full of screenings already
	}
	int j = 0;
	for (; j < MAX_SCREENINGS_PER_DAY && m_streamingTimesMat->getElement(day, j) != 0; j++) {//check if
		//there is a screening in the same day which haven't finished yet
		if (m_streamingTimesMat->getElement(day, j) + getLength() > screeningTime) { //found a movie which haven't finished yet 
			return FALSE;
		}
	}
	//if we reached here it means we found an empty place and all previous screenings have finished already
	m_streamingTimesMat->setElement(day,j, screeningTime); //put it in the mat
	return TRUE;
};

//*****************************************************************************************************
//* function name: getNextScreening
//* Description: Gets the next screening time available
//* Parameters:day - int,
//*			   time - int
//* Return Value: next screening time (if available) - int, or 0 if there is no next screening time available
//*****************************************************************************************************
int Movie::getNextScreening(int day, int time) const
{
	if (day < 1 || day>7 || time < 1 || time>24) {
		return 0;
	}
	int j = 0;
	for (; j < MAX_SCREENINGS_PER_DAY; j++) {
		if (m_streamingTimesMat->getElement(day, j) != 0 &&
			(m_streamingTimesMat->getElement(day, j) <= time || m_streamingTimesMat->getElement(day, j) + getLength() <= time)) {
			continue; //current screening was started or finished already
		}
		break; //found a screening which haven't started yet or reached a 0 in m_streamingTimesMat
	}
	if (j == MAX_SCREENINGS_PER_DAY) {//means all movies were started or finished before 'time'
		return 0;
	}
	else if (m_streamingTimesMat->getElement(day, j) == 0 && m_streamingTimesMat->getElement(day, j) <= time) {//means all screening times available are in the past
		return 0;
	}
	else {
		return m_streamingTimesMat->getElement(day, j); //valid next screening time
	}
};