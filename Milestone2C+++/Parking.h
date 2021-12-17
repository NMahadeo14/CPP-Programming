#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"

namespace sdds
{
	class Parking 
	{

		char* m_filename;
		Menu* m_ParkingMenu;
		Menu* m_VehicleMenu;

		
		Parking& operator=(const Parking&) = delete;
		Parking(const Parking&) = delete;
		bool isEmpty() const;
		void ParkingStatus() const;
		void ParkVehicles() const;
		void ReturnVehicles() const;
		void ListparkedVehicles() const;
		bool CloseParking() const;
		bool ExitParkingApp() const;
		bool LoadDataFile() const;
		void SaveDataFile() const;
		void ParkingMenu() const;
		void setEmpty();

	public:

		int run();
		Parking();
		Parking(const char*);
		~Parking();
	};
}

#endif // !PARKING_H

