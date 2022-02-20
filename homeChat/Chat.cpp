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
		
	getCin<std::string>(buf); //���� ������ ������������
	// cin >> buf;
	if (buf == "exit")
		return;

	for (int i = 0; i < users_.size(); ++i) //�������� ��������� ������ � ����
	{
		if (buf == users_.at(i).getLogin())
		{
			indexUser = i; //���������� ���������� ������
			buf.clear(); //������� �������� ����������
			break;
		}
	}
	
	if (indexUser != -1) //���� ����� ������������ � ���������� �������, �� ������ ������ ������
	{
		cout << "Please, enter your password or word 'exit' for turn of in Mein menu:" << endl;

		do
		{
			getCin<std::string>(buf); //���� ������ ������������ 
			//cin >> buf;
			
			if (users_.at(indexUser).getPassword() == buf) // �������� ������
			{
				checkPassw_ = true;
				buf.clear(); //������� �������� ����������
				return; 
			}
		} while (buf != "exit");	
	} 

	if (indexUser == -1) // ���� �� ����� ���������� �����, ���������� ������������ ����������������
		regMenu();
}

void Chat::regMenu()
{
	cout << "\vWelcome in menu registration.\nFor exit the menu enter word 'exit'.\nChoose login and enter it:" << endl;

	bool exitFlag = true; // ���� ��� ������ �� ������
	std::string buf; //�������� ���������� ��� �����!!!
	
	do
	{
		getCin<std::string>(buf);
		
		if (buf == "exit")
			return;

		for (int i = 0; i < users_.size(); ++i) //�������� ��������� ������ � ����
		{
			if (buf == users_.at(i).getLogin())
			{
				cout << "There is already a user with this login. Try again:" << endl;
				buf.clear(); //������� �������� ����������
				break;
			}
				
		}

	} while (exitFlag);
	
	User newUser(buf); //�������� ������������ !!!

	users_.push_back(newUser);

	cout << "Choose security password:" << endl;

	cout << "Congratulations, you have successfully registered " << endl;

}