#include "my_string.h"

String::String(const char* s) : size(string_length(s))
{
	if (s != nullptr) {
		str = new char[string_length(s) + 1];
		string_copy(s, str);
	}
}

String::String(const String& s) : size(s.size)
{
	str = new char[s.size + 1];
	string_copy(s.str, this->str);
}

String::String(String&& s)
{
	size = s.size;
	str = s.str;
	s.str = nullptr;
}

String::~String()
{
	delete[] str;
}

String& String::operator=(const String& s)
{
	delete[] str;
	str = nullptr;
	
	if (s.str != nullptr) {
		str = new char[s.size + 1];
		string_copy(s.str, this->str);
		size = s.size;
	}

	return *this;
}

String& String::operator=(String&& s)
{
	size = s.size;
	str = s.str;
	s.str = nullptr;
	
	return *this;
}

String String::operator+(const String& s) const
{
	int length = this->size + s.size;
	char* temp = new char[length + 1];

	string_copy(this->str, temp);
	string_copy(s.str, temp + this->size);

	String tmp(temp);

	delete[] temp;

	return tmp;
}

bool String::operator==(const String& s) const
{
	if (s.size != this->size)
		return false;
	else {
		for (int i = 0; i < size; ++i) {
			if (s.str[i] != this->str[i])
				return false;
		}
		return true;

	}
}

bool String::operator==(const char* s) const
{
	return (*this == String(s));
}

int String::length() const
{
	return size;
}

void String::clear()
{
	delete[] str;
	str = nullptr;
	size = 0;
}

char* String::print()
{
	return const_cast<char*> (str != nullptr ? str : "");
}

int string_length(const char* str)
{
	int size = 0;
	if (str != nullptr) {
		for (int i = 0; str[i] != '\0'; ++i)
			++size;
	}
	return size;
}

void string_copy(const char* source, char* dest)
{
	int l = string_length(source);
	for (int i = 0; i < l; ++i)
		dest[i] = source[i];
	dest[l] = '\0';
}