#include "Employee.H"


//*****************************************************************************************************
//* function name: Employee
//* Description: Employee constructor
//* Parameters: workerName - string
//*				workerSalary - int
//*				workHours - string*
//* Return Value:None
//*****************************************************************************************************
Employee::Employee(string workerName, int workerSalary, string* workHours) : m_salary(workerSalary)
{
	strcpy(m_name, workerName);
	m_workHours = workHours;
};

//*****************************************************************************************************
//* function name: getName
//* Description: Return the name of the employee
//* Parameters: None
//* Return Value: m_name - string
//*****************************************************************************************************

string Employee::getName() const
{
	return m_name;
}


//*****************************************************************************************************
//* function name: getSalary
//* Description: Return the salary by hour of the employee
//* Parameters: None
//* Return Value: m_salary - int
//*****************************************************************************************************

int Employee::getSalary() const
{
	return m_salary;
}

//*****************************************************************************************************
//* function name: calcWeeklySalary
//* Description: Return employee total salary of the week
//* Parameters: None
//* Return Value: Salary - int
//*****************************************************************************************************

int Employee::calcWeeklySalary() const
{	
	using namespace std;
	string StartHour;
	string EndHour;
	int StartHourAsInt;
	int EndHourAsInt;
	int Salary=0;
	int i;
	for (i = 0; i < 7;i++) {
		StartHour = strtok(m_workHours[i], "-");
		EndHour = strtok(NULL, "-");
		StartHourAsInt = atoi(StartHour);
		EndHourAsInt = atoi(EndHour);
		Salary = Salary + ((EndHourAsInt - StartHourAsInt) * m_salary);
	}
	return Salary;
}