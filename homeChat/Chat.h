#pragma once
#include "Messege.h"
#include <iostream>
#include <vector>

template <typename t1> t1 getCin(t1 x) {

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
			cin.ignore(32767, '\n');
			return x;
		}
	}
}

class Chat
{
	bool work_ = false; // чат работает
	bool checkPassw_ = false; // пароль пользователя проверен
	int indexUser = -1; //пользователь в сети
	vector <User> users_;
	vector <Messege> messeges_;


	public:
		Chat(bool work);
		~Chat() = default;

		//template <typename t> t getCin(t x);

		void mainMenu(); //вызов главного меню

		void enterMenu(); //идентификация пользователя

		void regMenu(); //меню регистрации

		
};

