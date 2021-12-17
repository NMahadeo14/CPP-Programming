#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include "Vehicle.h"
#include "ReadWritable.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool m_sideCar;
		char* m_mlicensePlate;
		char* m_makeModel;

	public:

		Motorcycle();
		Motorcycle(const char*, const char*);
		~Motorcycle();
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};
}
#endif // !SDDS_MOTORCYCLE_H
