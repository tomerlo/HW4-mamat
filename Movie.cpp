#include"Movie.H"

//*****************************************************************************************************
//* function name: Movie
//* Description: Movie constructor
//* Parameters:movieName - string,
//*            movieLength - int,
//*				movieLanguage - string
//*				theaterNum - int
//* Return Value: None
//*****************************************************************************************************

Movie::Movie(string movieName, int movieLength, string movieLanguage, int theaterNum) : m_ticketPrice(35),
m_movieLength(movieLength), m_theaterNum(theaterNum)
{
	strcpy(m_movieName, movieName);
	strcpy(m_movieLanguage, movieLanguage);
	int i = 0, j = 0;
	for (; i < 7; i++) {
		for (; j < MAX_SCREENINGS_PER_DAY; j++) {
			m_streamingTimesMat[i][j] = 0;
		}
	}
};

//*****************************************************************************************************
//* function name: getName
//* Description: gets movie name
//* Parameters:None
//* Return Value: m_movieName - string
//*****************************************************************************************************
string Movie::getName() const
{
	return m_movieName;
}

//*****************************************************************************************************
//* function name: getLength
//* Description: gets movie length in minutes
//* Parameters:None
//* Return Value: m_movieLength - int
//*****************************************************************************************************
int Movie::getLength() const
{
	return m_movieLength;
}

//*****************************************************************************************************
//* function name: getLanguage
//* Description: gets movie language
//* Parameters:None
//* Return Value: m_movieLanguage - string
//*****************************************************************************************************
string Movie::getLanguage() const
{
	return m_movieLanguage;
}

//*****************************************************************************************************
//* function name: getTheaterNum
//* Description: gets movie theater number
//* Parameters:None
//* Return Value: m_theaterNum - int
//*****************************************************************************************************
int Movie::getTheaterNum() const
{
	return m_theaterNum;
}

//*****************************************************************************************************
//* function name: getTicketPrice
//* Description: gets movie ticket price
//* Parameters:None
//* Return Value: m_ticketPrice - int
//*****************************************************************************************************
int Movie::getTicketPrice() const
{
	return m_ticketPrice;
}

