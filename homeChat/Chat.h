#pragma once
#include "Message.h"
#include "Logger.h"
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
	bool work_ = false; // ��� ��������
	bool checkPassw_ = false; // ������ ������������ ��������
	size_t indexUser = 0; //������������ � ����
	vector <User> users_ ;
	vector <Message> messages_;

	void mainMenu(); //����� �������� ����

	void enterMenu(); //������������� ������������

	void regMenu(); //���� �����������



	void sendMessage();

	void readMessage();

	void settings();

	public:
		Chat(bool work);
		~Chat() = default;

	void userMenu(); // ���� ������������	
		
		
};

