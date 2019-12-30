#include "Cashier.H"

//*****************************************************************************************************
//* function name: Cashier
//* Description: Cashier constructor
//* Parameters: workerName - string
//*				workerSalary - int
//*				workHours - string*
//* Return Value:None
//*****************************************************************************************************

Cashier::Cashier(string workerName, int workerSalary, string* workHours) : Employee(workerName, workerSalary, workHours), m_ticketProfit(0){}

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
	if (pmovie == NULL || ptheater==NULL || numOfTickets<=0 || wantedRow<0|| wantedRow>ptheater->getRowsNum ||
		mostRightCol<0 || mostRightCol-numOfTickets<0 || pmovie->getTheaterNum != ptheater->getTheaterNum)
		return 0;
	if (isDubbed == TRUE) {
		//DubbedMovie dMovie(pmovie ->getName, pmovie->getLength, pmovie->getLanguage, pmovie->getTheaterNum, ptheater->getTheaterNum);
		//DubbedMovie* pdmovie;
		//pmovie = &pdmovie;
		DubbedMovie* pdmovie = dynamic_cast<DubbedMovie*>(pmovie);
		int colIndexToStart = mostRightCol;
		int colIndexToStop = mostRightCol - numOfTickets;
		for (; colIndexToStart--; colIndexToStart >= colIndexToStop) {//to yaniv - don't know which theater to use and how
			if (ptheater->getElement(wantedRow, colIndexToStart) != FREE) {
				return 0;
			}
		}
		colIndexToStart = mostRightCol;
		for (; colIndexToStart--; colIndexToStart >= colIndexToStop) {
			ptheater->setElement(wantedRow, colIndexToStart, TAKEN);
		}
		m_ticketProfit = m_ticketProfit + ((pmovie->getTicketPrice) * numOfTickets);
		return ((pmovie->getTicketPrice) * numOfTickets);
	}
	else {
		int colIndexToStart = mostRightCol;
		int colIndexToStop = mostRightCol - numOfTickets;
		for (; colIndexToStart--; colIndexToStart >= colIndexToStop) {//to yaniv - don't know which theater to use and how
			if (ptheater->getElement(wantedRow, colIndexToStart) != FREE) {
				return 0;
			}
		}
		colIndexToStart = mostRightCol;
		for (; colIndexToStart--; colIndexToStart >= colIndexToStop) {
			ptheater->setElement(wantedRow, colIndexToStart, TAKEN);
		}
		m_ticketProfit = m_ticketProfit + ((pmovie->getTicketPrice) * numOfTickets);
		return ((pmovie->getTicketPrice) * numOfTickets);
	}
}