#include "User.h"

User::User(const string& login, const string& password, string& name) : login_(login), password_(password), name_(name)
{
}

 string User::getLogin()
{
	return 	login_;
}
