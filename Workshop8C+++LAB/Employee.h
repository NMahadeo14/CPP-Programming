#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream>

namespace sdds
{
	class Employee
	{
	public:
		virtual ~Employee() = default;
		virtual void setSalary(double) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;

	};
}


#endif // !SDDS_EMPLOYEE_H
