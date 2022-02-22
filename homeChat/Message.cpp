#include "Message.h"

Message::Message(const User& from, const User& to, const string& text) : from_(from), to_(to), text_(text)
{
}

string Message::getTo()
{
	return to_.getLogin();
}

string Message::getFrom()
{
	return from_.getLogin();
}

string Message::getText()
{
	return text_;
}
