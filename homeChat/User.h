#pragma once
#include <string>
#include <ctime>
#pragma warning(disable : 4996) 

using namespace std;

class User
{
	const string login_;
	string password_;
	string name_;
	string status_;
	string tmOnline_;

public:
	
	User(const string& login, const string& password, string& name); 
	
	~User() = default;
	
	//�������� �����
	string getLogin();

	//�������� ������
	string getPassword();
	
	//�������� ���. ���������� 0 - ���, 1 - ������, ��� 2 - ��� ������
	string getInfo(int i);

	string getTmOnline();

	//�������� ������ (0 - �������, 1 - ���)
	int setPassword(const string& oldPass, const string& newPass);

	//�������� ��� 
	void setName(const string& name);

	//��������� �������
	void setStatus(const string& status);

	//��������� ������� ���������� ��������� � ����
	void setTmOnline();
	 




};

