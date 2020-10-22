#ifndef STRING_H
#define STRING_H

class String {
public:
	String(const char* str);
	String(const String& s);

	~String();

	// Operators overload
	String operator+ (const String& s);
	String operator== (const String& s);

	// Methods
	int length();
	void clear();

	char* print();

private:
	char* str;

};

#endif