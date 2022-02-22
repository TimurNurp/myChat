#pragma once
#include"User.h"

class Message
{
	User from_;
	User to_;
	const string text_;
public:

	Message(const User& from, const User& to, const string& text);
	~Message() = default;

	string getTo();

	string getFrom();

	string getText();
};

