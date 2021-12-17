#ifndef SDDS_NUMBERSBOX_H
#define SDDS_NUMBERSBOX_H
#include <iostream>
#include <cstring>


namespace sdds
{
	template<typename T>
	class NumbersBox
	{
		char m_name[15];
		int m_size;
		T* m_items;

	public:

		NumbersBox()
		{
			m_name[0] = '\0';
			m_size = 0;
			m_items = nullptr;
		}

		NumbersBox(int size, const char* name) : NumbersBox()
		{
			if ((size > 0) && (name[0] != '\0'))
			{
				m_size = size;
				strcpy(m_name, name);
				m_items = new T[m_size];
			}
		}

		~NumbersBox()
		{
			delete[] m_items;
		}


		T& operator[](int i)
		{
			return m_items[i];
		}

		NumbersBox<T>& operator*=(const NumbersBox<T>& other)
		{
			if (other.m_size == this->m_size)
			{
				for (int i = 0; i < m_size; i++)
				{
					this->m_items[i] *= other.m_items[i];
				}
			}

			return *this;
		}

		NumbersBox<T>& operator+=(T num)
		{
			//create a temp array
			T* tempItems;
			tempItems = nullptr;
			tempItems = new T[m_size];

			//copy old array into new array
			for (int i = 0; i < m_size; i++)
			{
				tempItems[i] = m_items[i];
			}

			//increase size by 1
			m_size++;

			//delete old array and resize to new size
			delete[] m_items;
			m_items = nullptr;
			m_items = new T[m_size];

			//copy temp array into new array and at last index add num variable
			for (int i = 0; i < m_size; i++)
			{
				if (i == (m_size - 1))
				{
					m_items[i] = num;
				}
				else
				{
					m_items[i] = tempItems[i];
				}
			}

			//delete temp array for memory leaks and return this 
			delete[] tempItems;
			tempItems = nullptr;
			return *this;
		}

		std::ostream& display(std::ostream& os) const
		{
			if (m_name[0] == '\0')
			{
				os << "Empty Box" << std::endl;
			}
			else
			{
				os << "Box name: " << m_name << std::endl;

				for (int i = 0; i < m_size; i++)
				{
					if (i == (m_size - 1))
					{
						os << m_items[i];
					}
					else
					{
						os << m_items[i] << ", ";
					}
					
				}
				 
				os << std::endl;
			}

			return os;
		}

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box)
	{
		box.display(os);
		return os;
	}
	
}

#endif

