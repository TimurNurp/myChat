#pragma once
#include "Messege.h"
#include <iostream>
#include <vector>
#include <typeinfo>	

/*template <typename t1> t1 getCin(t1 x) {

	while (true)
	{
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect enter. Please try again" << endl;
		}
		else
		{
			if (typeid(x).name() != "string")
				cin.ignore(32767, '\n');
			return x;
		}
	}
}*/

class Chat
{
	bool work_ = false; // чат работает
	bool checkPassw_ = false; // пароль пользователя проверен
	size_t indexUser = 0; //пользователь в сети
	vector <User> users_;
	vector <Messege> messeges_;


	public:
		Chat(bool work);
		~Chat() = default;
		
		void mainMenu(); //вызов главного меню

		void enterMenu(); //идентификация пользователя

		void regMenu(); //меню регистрации

		void userMenu(); // меню пользователя

		
};

