#include "my_string.h"

String::String(const char* s)
{
	if (s == nullptr) {
		str = new char[1];
		str[0] = '\0';
	}
	else {
		str = new char[string_length(s) + 1];
		string_copy(s, str);
	}
}

String::String(const String& s)
{
	str = new char[string_length(s.str) + 1];
	string_copy(s.str, this->str);
}

String::String(String&& s)
{
	str = s.str;
	s.str = nullptr;
}

String::~String()
{
	delete this->str;
}

String& String::operator=(const String& s)
{
	delete str;
	str = new char[string_length(s.str) + 1];
	string_copy(s.str, this->str);
	return *this;
}

String& String::operator=(String&& s) noexcept
{
	delete str;
	str = new char[string_length(s.str) + 1];
	string_copy(s.str, this->str);
	s.str = nullptr;
	return *this;
}

String String::operator+(const String& s) const
{
	int length = string_length(this->str) + string_length(s.str);
	char* temp = new char[length + 1];

	string_copy(this->str, temp);
	string_copy(s.str, temp + string_length(this->str));

	String tmp(temp);

	delete[] temp;

	return tmp;
}

bool String::operator==(const String& s) const
{
	if (s.length() != this->length())
		return false;
	else {
		int l = string_length(str);
		for (int i = 0; i < l; ++i) {
			if (s.str[i] != this->str[i])
				return false;
		}
		return true;

	}
}

bool String::operator==(const char* s) const
{
	if (string_length(s) != string_length(str))
		return false;
	else {
		int l = string_length(str);
		for (int i = 0; i < l; ++i) {
			if (s[i] != str[i])
				return false;
		}
		return true;
	}
}

int String::length() const
{
	return string_length(str);
}

void String::clear()
{
	delete str;
	str = new char[1];
	str[0] = '\0';
}

char* String::print()
{
	return this->str;
}

int string_length(const char* str)
{
	int size = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		++size;
	return size;
}

void string_copy(const char* source, char* dest)
{
	int l = string_length(source);
	for (int i = 0; i <= l; ++i)
		dest[i] = source[i];
}