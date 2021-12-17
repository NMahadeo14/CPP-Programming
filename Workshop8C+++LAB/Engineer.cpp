#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"
#include "Engineer.h"

using namespace std;

namespace sdds
{
	Engineer::Engineer()
	{
		m_esalary = 0.0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer(double salary, int hours, int level) : Engineer()
	{
		if ((salary > 0) && (hours > 0))
		{
			m_level = level;
			m_ewhours = hours;
			setSalary(salary);
		}
	}

	void Engineer::setSalary(double sal)
	{
		if (m_level == MAX_LEVEL)
		{
			m_esalary = sal + 3000;
		}
		else
		{
			m_esalary = sal;
		}
	}

	bool Engineer::workHours()
	{
		if (m_ewhours >= MIN_HOURS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Engineer::bonus()
	{
		if ((m_ewhours >= MIN_HOURS) && (m_level == MAX_LEVEL))
		{
			m_esalary = this->m_esalary + (this->m_esalary * 0.10);
		}
		else
		{
			m_esalary = this->m_esalary + (this->m_esalary * 0.05);
		}
	}

	ostream& Engineer::display(ostream& os) const
	{
		if ((this->m_esalary > 0) && (this->m_ewhours > 0))
		{
			os << "Engineer details\n";
			os << "level: " << this->m_level << "\n";
			os << setprecision(2);
			os << "Salary: " << this->m_esalary << "\n";
			os << "Working hours: " << this->m_ewhours << "\n";
		}
		else
		{
			os << "Engineer is not initiated yet\n";
		}

		return os;
	}
}