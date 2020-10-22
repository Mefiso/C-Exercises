#include "my_string.h"

String::String(const char* str)
{
	while ((*str) != '\0') {
		*(this->str) = (*str);
		++str;
	}
}

String::~String()
{

}

char* String::print()
{
	return this->str;
}
