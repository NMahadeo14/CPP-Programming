#include <iostream>
#include <cstring>
#include <iomanip>
#include "Doctor.h"
#include "Employee.h"

using namespace std;

namespace sdds
{

	Doctor::Doctor()
	{
		m_type[0] = '\0';
		m_salary = 0.0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor(const char* type, double salary, int hours, bool special) : Doctor()
	{
		if ((salary > 0) && (hours > 0))
		{
			strcpy(m_type, type);
			m_whours = hours;
			m_specialist = special;
			setSalary(salary);
		}
	}

	void Doctor::setSalary(double sal)
	{
		if (m_specialist == true)
		{
			m_salary = sal + 2000;
		}
		else
		{
			m_salary = sal;
		}
	}

	bool Doctor::workHours()
	{
		if (m_whours >= MIN_W_HOURS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Doctor::bonus()
	{
		if (m_whours > MIN_W_HOURS)
		{
			m_salary = this->m_salary + (this->m_salary * 0.10);
		}
		else
		{
			m_salary = this->m_salary + (this->m_salary * 0.05);
		}
	}

	ostream& Doctor::display(ostream& os) const
	{
		if ((this->m_salary > 0) && (this->m_whours > 0))
		{
			os << "Doctor details\n";
			os << "Doctor Type: " << this->m_type << "\n";
			os << fixed;
			os << setprecision(2);
			os << "Salary: " << this->m_salary << "\n";
			os << "Working Hours: " << this->m_whours << "\n";
		}
		else
		{
			os << "Doctor is not initiated yet\n";
		}

		return os;
	}

}