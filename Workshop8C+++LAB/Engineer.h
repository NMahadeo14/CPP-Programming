#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include <iostream>
#include "Employee.h"

using namespace std;

namespace sdds
{
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;

	class Engineer : public Employee
	{
		double m_esalary;
		int m_ewhours;
		int m_level;

	public:

		Engineer();
		Engineer(double, int, int);
		void setSalary(double);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}

#endif // !SDDS_ENGINEER_H

