#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include <iostream>
#include "Employee.h"

namespace sdds
{

	const int MIN_W_HOURS = 6;
	const char MAX_CHAR = 20;

	class Doctor : public Employee
	{
		char m_type[MAX_CHAR + 1];
		double m_salary;
		int m_whours;
		bool m_specialist = false;

	public:

		Doctor();
		Doctor(const char*, double, int, bool special = false);
		void setSalary(double);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}

#endif // !SDDS_DOCTOR_H

