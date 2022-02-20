#include "Chat.h"

Chat::Chat(bool work) : work_(work)
{
	mainMenu();
}




void Chat::mainMenu()
{
	cout << "Hello, friend! Choose an action to continue:" << endl;
	cout << "1 - login \n2 - registration \n3 - exit" << endl;
	
	int choose = 0;

	switch (getCin<int>(choose))
	{ 
	case 1:
		enterMenu();
		break;

	case 2:
		regMenu();
		break;
	default:
		break;
	}
		 
}

void Chat::enterMenu()
{
	cout << "\vWelcome in Login menu.\nPlease, enter your login or word 'exit' for turn of in Mein menu:" << endl;
	std::string buf;
		
	getCin<std::string>(buf); //ввод логина пользователя
	// cin >> buf;
	if (buf == "exit")
		return;

	for (int i = 0; i < users_.size(); ++i) //проверка введеного логина в базе
	{
		if (buf == users_.at(i).getLogin())
		{
			indexUser = i; //запоминает подходящий индекс
			buf.clear(); //очищаем буферную переменную
			break;
		}
	}
	
	if (indexUser != -1) //если нашли пользователя с подходящим логином, то просим ввести пароль
	{
		cout << "Please, enter your password or word 'exit' for turn of in Mein menu:" << endl;

		do
		{
			getCin<std::string>(buf); //ввод пароля пользователя 
			//cin >> buf;
			
			if (users_.at(indexUser).getPassword() == buf) // проверка пароля
			{
				checkPassw_ = true;
				buf.clear(); //очищаем буферную переменную
				return; 
			}
		} while (buf != "exit");	
	} 

	if (indexUser == -1) // если не нашли подходящий логин, отправляем пользователя регестрироваться
		regMenu();
}

void Chat::regMenu()
{
	cout << "\vWelcome in menu registration.\nFor exit the menu enter word 'exit'.\nChoose login and enter it:" << endl;

	bool exitFlag = true; // флаг для выхода из циклов
	std::string buf; //буферная переменная для ввода!!!
	
	do
	{
		getCin<std::string>(buf);
		
		if (buf == "exit")
			return;

		for (int i = 0; i < users_.size(); ++i) //проверка введеного логина в базе
		{
			if (buf == users_.at(i).getLogin())
			{
				cout << "There is already a user with this login. Try again:" << endl;
				buf.clear(); //очищаем буферную переменную
				break;
			}
				
		}

	} while (exitFlag);
	
	User newUser(buf); //буферный пользователь !!!

	users_.push_back(newUser);

	cout << "Choose security password:" << endl;

	cout << "Congratulations, you have successfully registered " << endl;

}