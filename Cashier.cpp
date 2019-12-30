#include "Cashier.H"

//*****************************************************************************************************
//* function name: Cashier
//* Description: Cashier constructor
//* Parameters:None
//* Return Value:None
//*****************************************************************************************************

Cashier::Cashier() : Employee(string workerName, int workerSalary, string* workHours), m_ticketProfit(0){}

//*****************************************************************************************************
//* function name: getTicketProfit
//* Description: Outputs the ticket profit of the specific cashier
//* Parameters:None
//* Return Value:m_ticketProfit - int
//*****************************************************************************************************

int Cashier::getTicketProfit() const
{
	return m_ticketProfit;
}

//*****************************************************************************************************
//* function name: sellTickets
//* Description: Outputs the toatl price of tickets which were asked to purchase
//* Parameters:pmovie - pointer to a movie
//*			   ptheater - pointer to a theater
//*			   isDubbed - boolean parameter
//*			   numOfTickets - int
//*			   wantedRow - int
//*			   mostRightCol - int
//* Return Value: totalPrice - int
//*****************************************************************************************************

int Cashier::sellTickets(Movie* pmovie, Theater* ptheater, BOOL isDubbed, int numOfTickets, int wantedRow, int mostRightCol)
{
	if (pmovie->getTheaterNum != ptheater->getTheaterNum)
		return 0;

}