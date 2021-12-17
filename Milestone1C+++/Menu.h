#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		char* m_menuItem;

		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		void display();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		friend class Menu;
	};

	class Menu
	{
		char* m_title;
		MenuItem* m_items[MAX_NO_OF_ITEMS];
		int m_indentation;
		int m_index;

	public:

		Menu();
		Menu(const char*, int indentation = 0);
		Menu(const Menu&);
		~Menu();
		Menu& operator=(const Menu&);
		bool isEmpty() const;
		void display() const;
		void add(const char*);
		Menu& operator<<(const char* newMenuItem);
		int run() const;
		operator int() const;
		operator bool() const;


	};
}


#endif // !SDDS_MENU_H

