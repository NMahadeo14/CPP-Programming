#include <iostream>
#include <cstring>
#include "Parking.h"
#include "Menu.h"

using namespace std;

namespace sdds
{

	Parking::Parking()
	{
		m_filename = nullptr;
		m_ParkingMenu = nullptr;
		m_VehicleMenu = nullptr;
	}

	void Parking::setEmpty()
	{
		m_filename = nullptr;
		m_ParkingMenu = nullptr;
		m_VehicleMenu = nullptr;
	}

	Parking::Parking(const char* filename)
	{
		if (filename != nullptr && strlen(filename) > 0)
		{
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
		}
		else
		{
			setEmpty();
		}

		if (LoadDataFile())
		{
			m_ParkingMenu = new Menu("Parking Menu, select an action:", 0);
			m_ParkingMenu->add("Park Vehicle");
			m_ParkingMenu->add("Return Vehicle");
			m_ParkingMenu->add("List Parked Vehicles");
			m_ParkingMenu->add("Close Parking (End of day)");
			m_ParkingMenu->add("Exit Program");

			m_VehicleMenu = new Menu("Select type of the vehicle:", 1);
			m_VehicleMenu->add("Car");
			m_VehicleMenu->add("Motorcycle");
			m_VehicleMenu->add("Cancel");
		}
		else
		{
			cout << "Error in data file\n";
			setEmpty();
		}

	}

	Parking::~Parking()
	{
		SaveDataFile();
		delete[] m_filename;
		m_filename = nullptr;

	}

	void Parking::ParkingMenu() const
	{
		ParkingStatus();
	}

	bool Parking::isEmpty() const
	{
		if (m_filename == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Parking::ParkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******\n";

		m_ParkingMenu->display();
	}

	void Parking::ParkVehicles() const
	{
		int option = 0;
		m_VehicleMenu->display();
		cin >> option;

		if (option == 1)
		{
			cout << "Parking Car" << endl;
		}

		if (option == 2)
		{
			cout << "Parking Motorcycle" << endl;
		}

		if (option == 3)
		{
			cout << "Cancelled parking" << endl;
		}

	}

	void Parking::ReturnVehicles() const
	{
		cout << "Returning Vehicle\n";
	}

	void Parking::ListparkedVehicles() const
	{
		cout << "Listing Parked Vehicles\n";
	}

	bool Parking::CloseParking() const
	{
		cout << "Closing Parking\n";

		return true;
	}

	bool Parking::ExitParkingApp() const
	{
		bool confirm = false;
		bool exitloop = false;
		char option[10];
		cout << "This will terminate the program!\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		cin.getline(option, 3);

		while (exitloop == false)
		{

			if ((option[0] == 'Y' || option[0] == 'y') && (option[1] == '\0'))
			{
				exitloop = true;
				confirm = true;
			}
			else if ((option[0] == 'N' || option[0] == 'n') && (option[1] == '\0'))
			{
				exitloop = true;
				confirm = false;
			}
			else
			{
				cin.clear();
				cin.ignore(9000,'\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> option;
			}

		}

		return confirm;
		
	}

	bool Parking::LoadDataFile() const
	{
		if (!isEmpty())
		{
			cout << "loading data from " << m_filename << "\n";
			return true;
		}
		else
		{
			return false;
		}
	}

	void Parking::SaveDataFile() const
	{
		if (!isEmpty())
		{
			cout << "Saving data into " << m_filename << "\n";
		}
	}

	int Parking::run()
	{
		int option;
		bool exitloop = false;

		if (!isEmpty())
		{
			while (exitloop == false)
			{
				this->ParkingMenu();

				cin >> option;

				if (option == 1)
				{
					this->ParkVehicles();
				}

				if (option == 2)
				{
					this->ReturnVehicles();
				}

				if (option == 3)
				{
					this->ListparkedVehicles();
				}

				if (option == 4)
				{
					CloseParking();
					break;
				}

				if (option == 5)
				{
					if (ExitParkingApp() == true)
					{
						cout << "Exiting program!" << endl;
						return 0;
					}
					
				}
			}

			return 0;
		}
		else
		{
			return 1;
		}

	}


}