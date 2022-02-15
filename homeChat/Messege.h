#pragma once
#include"User.h"

class Messege
{
	const User from_;
	const User to_;
	const string text_;
public:

	Messege(const User& from, const User& to, const string& text);
	~Messege() = default;

};

