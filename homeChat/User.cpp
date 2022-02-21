#include "User.h"

User::User(const string& login) : login_(login)
{
	
}

User::User(const string& login, const string& password, string& name) : login_(login), password_(password), name_(name)
{
}

 string User::getLogin()
{
	return 	login_;
}

 string User::getPassword()
 {
	 return password_;
 }

 string User::getInfo(int i)
 {
	 if (i == 0)
	 {
		 return name_;
	 }
	 else if (i == 1)
	 {
		 return status_;
	 }
	 else 
	 {
		 return name_ + "\n" + status_;
	 }
 }

 string User::getTmOnline()
 {
	 return tmOnline_;
 }

 int User::setPassword(const string& oldPass, const string& newPass)
 {
	 if (oldPass == password_)
	 {
		password_ = newPass;
		return 0;
	 }
	 else
	 {
		return 1;
	 }
	 
 }

 void User::setName(const string& name)
 {
	 if (name_ == name)
	 {
		 return;
	 }
	 else
	 {
		 name_ = name;
	 }
 }

 void User::setStatus(const string& status)
 {
	 if (status_ == status)
	 {
		 return;
	 }
	 else
	 {
		 status_ = status;
	 }
 }

 void User::setTmOnline()
 {
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 tmOnline_ = string(dt);
	//delete dt;
 }
