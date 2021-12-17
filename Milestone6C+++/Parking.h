#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{

	const int MAX_NUMBER_PARKING_SPOTS = 100;

	class Parking 
	{

		char* m_filename;
		Menu* m_ParkingMenu;
		Menu* m_VehicleMenu;
		int m_numOfParkingSpots;
		int m_numOfParkedVehicles;
		int m_numOfAvailableSpots;
		Vehicle* m_ParkingSpot[MAX_NUMBER_PARKING_SPOTS];


		Parking& operator=(const Parking&) = delete;
		Parking(const Parking&) = delete;
		bool isEmpty() const;
		void ParkingStatus() const;
		void ParkVehicles();
		void ReturnVehicles();
		void ListparkedVehicles() const;
		bool CloseParking();
		bool ExitParkingApp() const;
		bool LoadDataFile();
		void SaveDataFile() const;
		void ParkingMenu() const;
		void setEmpty();

	public:

		int run();
		Parking();
		Parking(const char*, int);
		~Parking();
	};
}

#endif // !PARKING_H


