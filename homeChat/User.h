#pragma once
#include <string>
#include <ctime>
#pragma warning(disable : 4996) 

using namespace std;

class User
{
	const string login_;
	string password_; 
	string name_;	//имя пользователя
	string status_; //статус пользователя
	string tmOnline_; //время выхода пользователя

public:
	User(const string& login);

	User(const string& login, const string& password, string& name); 
	
	~User() = default;
	
	//получить логин
	string getLogin();

	//получить пароль
	string getPassword();
	
	//получить доп. информацию 0 - имя, 1 - статус, или 2 - все вместе
	string getInfo(int i);

	string getTmOnline();

	//изменить пароль (0 - успешно, 1 - нет)
	int setPassword(const string& oldPass, const string& newPass);

	//изменить имя 
	void setName(const string& name);

	//установка статуса
	void setStatus(const string& status);

	//установка времени последнего появления в сети
	void setTmOnline();
	 




};

