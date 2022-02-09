#pragma once
#include <string>
using namespace std;

class User
{
	const string login_;
	const string password_;
	string name_;
	string status_;

public:
	
	User(const string& login, const string& password, string& name); 
	string getLogin();

};

