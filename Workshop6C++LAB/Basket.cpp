#include <iostream>
#include <iomanip>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds
{
	Basket::Basket()
	{
		m_basketName = nullptr;
		m_quantityBasket = 0;
		m_basketPrice = 0.0;
	}

	Basket::Basket(const char* name, int numofFruits, double price)
	{
		if ((name != nullptr) && (numofFruits > 0) && (price > 0.0))
		{
			m_basketName = new char[strlen(name) + 1];
			strcpy(this->m_basketName, name);

			this->m_quantityBasket = numofFruits;
			this->m_basketPrice = price;
		}
		else
		{
			m_basketName = nullptr;
			m_quantityBasket = 0;
			m_basketPrice = 0.0;
		}
	}

	Basket::Basket(const Basket& origin)
	{
		m_basketPrice = origin.m_basketPrice;
		m_quantityBasket = origin.m_quantityBasket;

		if (origin.m_basketName != nullptr)
		{
			m_basketName = nullptr;
			m_basketName = new char[strlen(origin.m_basketName) + 1];

			int count = strlen(origin.m_basketName) + 1;

			for (int i = 0; i < count; i++)
			{
				this->m_basketName[i] = origin.m_basketName[i];
			}
		}
		else
		{
			m_basketName = nullptr;
		}
	}

	Basket& Basket::operator=(const Basket& origin)
	{
		if (this != &origin)
		{
			m_basketPrice = origin.m_basketPrice;
			m_quantityBasket = origin.m_quantityBasket;

			delete [] m_basketName;

			if (origin.m_basketName != nullptr)
			{
				m_basketName = nullptr;
				m_basketName = new char[strlen(origin.m_basketName) + 1];

				int count = strlen(origin.m_basketName) + 1;

				for (int i = 0; i < count; i++)
				{
					this->m_basketName[i] = origin.m_basketName[i];
				}
			}
		}
		else
		{
			m_basketName = nullptr;
		}

		return *this;
	}

	void Basket::setName(const char* theName)
	{
		if (theName != nullptr)
		{
			m_basketName = new char[strlen(theName) + 1];
		}
		else
		{
			m_basketName = nullptr;
		}
	}

	void Basket::setqty(int quantity)
	{
		if (quantity > 0)
		{
			m_quantityBasket = quantity;
		}
		else
		{
			m_quantityBasket = 0;
		}
	}

	void Basket::setPrice(double price)
	{
		if (price > 0.0)
		{
			m_basketPrice = price;
		}
		else
		{
			m_basketPrice = 0.0;
		}
	}

	bool Basket::isEmpty() const
	{
		bool emptyState = true;

		if (this->m_basketName == nullptr && this->m_basketPrice == 0.0  && this->m_quantityBasket == 0)
		{
			emptyState = true;
		}
		else
		{
			emptyState = false;
		}

		return emptyState;
	}

	bool Basket::addPrice(double addedPrice)
	{
		bool priceAdded;

		if (addedPrice > 0)
		{
			this->m_basketPrice = this->m_basketPrice + addedPrice;
			priceAdded = true;
		}
		else
		{
			priceAdded = false;
		}

		return priceAdded;
	}

	ostream& Basket::display(ostream& os) const
	{
		if (!isEmpty())
		{
			os << "Basket Details" << endl;
			os << "Name: " << this->m_basketName << endl;
			os << "Quantity: " << this->m_quantityBasket << endl;
			os << fixed << setprecision(2) << "Price: " << this->m_basketPrice << endl;
		}
		else
		{
			os << "The Basket has not yet been filled" << endl;
		}

		return os;
	}

	bool Basket::operator==(const Basket& other) const
	{
		if ((this->m_basketName == other.m_basketName) && (this->m_basketPrice == other.m_basketPrice) && (this->m_quantityBasket == other.m_quantityBasket))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool Basket::operator!=(const Basket& other) const
	{
		if ((this->m_basketName != other.m_basketName) && (this->m_basketPrice != other.m_basketPrice) && (this->m_quantityBasket != other.m_quantityBasket))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	ostream& operator<<(ostream& os, const Basket& bsk)
	{
		bsk.display(os);

		return os;
	}

	Basket::~Basket()
	{
		delete[] m_basketName;
		m_basketName = nullptr;
	}


}




