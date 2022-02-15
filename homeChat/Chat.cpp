#include "Chat.h"



Chat::Chat(bool work) : work_(work)
{
}

template <typename t1> t1 getCin(t1 x) {

	while (true)
	{
		cin >> x;
		if (cin.fault()) {
			cin.clear();
			cin.(32767, '\n');
			cout << "Incorrect command. Please try again"
		}
		else
		{
			cin.(32767, '\n');
			return x;
		}
	}

 }

void Chat::entrance()
{
	cout << "Please enter your login" << endl;
	std::string log;
		
	getCin<std::string>(log);
		
	for (int i = 0; i < ; i++)
		{
		if (log == [i])
			{
				запоминает подходящий индекс
					break;
			}
		}
	cout << "enter your password" << endl;

	getCin<std::string>(log);
}

void Chat::menu()
{
	cout << "Hello, friend! Choose an action to continue:" << endl;
	cout << "1 - login \n 2 - registration \n 3 - exit" << endl;
	
	int choose = 0;

	getCin<int>(choose);


}
