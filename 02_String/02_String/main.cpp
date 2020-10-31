#ifdef _DEBUG
#define MYDEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new MYDEBUG_NEW
#endif

void DumpLeaks(void)
{
	_CrtDumpMemoryLeaks(); // show leaks with file and line where allocation was made
}


#include <iostream>
#include "my_string.h"
#include "Utility.h"

int main(int argc, char* argv[])
{
	atexit(DumpLeaks);
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