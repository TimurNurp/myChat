#include "Chat.h"

Chat::Chat(bool work) : work_(work)
{
	User first("all");

	users_.push_back(first);
	
	mainMenu();

}

void Chat::mainMenu()
{		int choose = 0;

	do
	{
		cout << "Hello, friend! Choose an action to continue:" << endl;
		cout << "1 - login \n2 - registration \n3 - exit" << endl;


		cin >> choose;
		cin.ignore(32767, '\n');

		switch (choose)
		{
		case 1:
		enterMenu();
		break;

		case 2:
		regMenu();

		default:
			break;
		}

		if (checkPassw_)
			userMenu();

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}

	} while (work_);

}

void Chat::enterMenu()
{
	cout << "\tWelcome in Login menu.\nPlease, enter your login or word 'exit' for turn of in Mein menu:" << endl;
	
	std::string buf;
		
	getline(cin, buf); //ввод логина пользователя

	if (buf == "exit")
		return;

	for (size_t i = 1; i < users_.size(); ++i) //проверка введеного логина в базе
	{
		if (buf == users_.at(i).getLogin())
		{
			indexUser = i;  //запоминает подходящий индекс!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			buf.clear(); //очищаем буферную переменную
			break;
		}
	}
	
	if (indexUser != 0) //если нашли пользователя с подходящим логином, то просим ввести пароль
	{
		cout << "Please, enter your password or word 'exit' for turn of in Mein menu:" << endl;

		do
		{
			getline(cin, buf); //ввод пароля пользователя 
			
			if (users_.at(indexUser).getPassword() == buf) // проверка пароля
			{
				checkPassw_ = true;
				buf.clear(); //очищаем буферную переменную

				return; 

			}
		} while (buf != "exit");	
	} 

	if (indexUser == 0) // если не нашли подходящий логин, отправляем пользователя регестрироваться
		regMenu();
}

void Chat::regMenu()
{
	cout << "\tWelcome in menu registration.\nFor exit the menu enter word 'exit'.\nChoose login and enter it:" << endl;

	bool exitFlag = true; // флаг для выхода из циклов
	std::string buf; //буферная переменная для ввода!!!
	
	do
	{
		getline(cin, buf);
		
		if (buf == "exit")
			return;
		else if (users_.size() == 0)
		{
			break;
		}
		else
		{
			for (size_t i = 0; i < users_.size(); ++i) //проверка введеного логина в базе
			{
				if (buf == users_.at(i).getLogin())
				{
					cout << "There is already a user with this login. Try again:" << endl;
					buf.clear(); //очищаем буферную переменную
					exitFlag = true;
					break;
				}
				else
				{
					exitFlag = false;
				}
			}
		}


	} while (exitFlag);

	User newUser(buf); //буферный пользователь !!!
	
	cout << "Okey. Your login: " << newUser.getLogin() << endl;
	cout << "Choose security password:" << endl;

	getline(cin, buf);

	newUser.setPassword("", buf);

	cout << "Good password!\nEnter your name:" << endl;

	getline(cin, buf);

	newUser.setName(buf);

	users_.push_back(newUser); // добавили нового пользователя в базу

	cout << "Congratulations, you have successfully registered " << endl;

	indexUser = users_.size() - 1; // пользователь в сети 
	checkPassw_ = true; //пароль проверен
	
}

void Chat::userMenu()
{
	int choose = 0;

	string buf;

	do
	{
		cout << '\t' << users_.at(indexUser).getLogin() << endl;
		cout << "This is your user menu, " << users_.at(indexUser).getInfo(0) << endl;
		cout << "Your current status: " << users_.at(indexUser).getInfo(1) << endl;
		cout << "Please, enter your login or word 'exit' for turn of in Mein menu : " << endl;
		cout << "\tChoose an action to continue:\n1 - write Message;\n2 - read Message;\n3 - change status;\n4 - settings;\n5 - logout;\n6 - exit." << endl;

		cin >> choose;
		cin.ignore(32767, '\n');

		switch (choose)
		{
		case 1:
			sendMessage();
			break;

		case 2:
			readMessage();
			break;

		case 3:
			cout << "Your current status: " << users_.at(indexUser).getInfo(1) << endl;
			cout << "Enter new status:" << endl;

			getline(cin, buf);

			users_.at(indexUser).setStatus(buf);

			break;
		case 4:
			settings();
			break;

		case 5:
			indexUser = 0;

			checkPassw_ = false;

			return;
		default:

			work_ = false;
			return;

		}

	} while (true);
}

void Chat::sendMessage()
{	
	cout << "Choose why write message:" << endl;

	for (size_t i = 0; i < users_.size(); ++i)
		cout << i << ".\t" << users_.at(i).getLogin() << endl;
	
	size_t choose;
	 
	cin >> choose;
	cin.ignore(32767, '\n');
	
	cout << "You write a message to:" << users_.at(choose).getLogin() << endl;
	cout << "Eneter text:" << endl;

	std::string buf;

	getline(cin, buf);

	Message newMessage(users_.at(indexUser).getLogin(), users_.at(choose).getLogin(), buf);

	messages_.push_back(newMessage);

	cout << "Message sent" << endl;

	Logger logFile("logs.txt");

	logFile.write(newMessage);

}

void Chat::readMessage()
{

	cout << "Your incoming messages:" << endl;
	
	for (size_t i = 0; i < messages_.size(); ++i)
		if (messages_.at(i).getTo() == users_.at(indexUser).getLogin() || messages_.at(i).getTo() == users_.at(0).getLogin())
			cout << messages_.at(i).getFrom() << ":\n" << messages_.at(i).getText() << endl;

	cout << "Messages are over" << endl;
}

void Chat::settings()
{
	int choose = 0;
	string buf1;
	string buf2;
	do
	{
		cout << "\t Settings menu\nChoose an action:\n1 - Change name;\n2 - Change password;\n3 - Exit." << endl;
		cin >> choose;
		cin.ignore(32767, '\n');

		switch (choose)
		{
		case 1:
			cout << "Enter new name:" << endl;

			getline(cin, buf1);

			users_.at(indexUser).setName(buf1);

			cout << "Your new name:" << users_.at(indexUser).getInfo(0) << endl;

			break;

		case 2:
			cout << "Enter old password:" << endl;

			getline(cin, buf1);

			cout << "Enter new password:" << endl;

			getline(cin, buf2);

			if (users_.at(indexUser).setPassword(buf1, buf2))
			{
				cout << "password not changed." << endl;
			}
			else
			{
				cout << "password changed." << endl;
			}

			break;

		default:
			return;
		}

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		
	} while (true);
}