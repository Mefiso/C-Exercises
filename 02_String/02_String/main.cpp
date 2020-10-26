#include <iostream>
#include "my_string.h"

String GetMeAString() { 
	String tmp("another string");
	return tmp; 
}

int main(int argc, char* argv[])
{
	String a("hello");
	String b("gg");
	String c(b);
	
	std::cout << a.print() << std::endl;
	std::cout << a.length() << " " << b.length() << std::endl;
	std::cout << c.print() << std::endl;
	
	String d = a + c;
	std::cout << d.print() << std::endl;
	if (d == "hellogg") {
		std::cout << d.length() << std::endl;
		d.clear();
		std::cout << d.print() << " " << d.length() << std::endl;
	}
	if (a == b) {
		std::cout << "gg";
	}
	else if (b == c) {
		std::cout << "wp\n";
	}

	String e = GetMeAString();
	std::cout << e.print();

}