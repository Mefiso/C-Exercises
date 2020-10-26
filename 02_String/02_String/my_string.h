#ifndef STRING_H
#define STRING_H

class String {
public:
	String(const char* s);
	String(const String& s);
	String(String&& s);

	~String();

	// Operators overload
	String& operator= (const String& s);
	String& operator= (String&& s) noexcept; // move assignment
	String operator+ (const String& s) const;
	bool operator== (const String& s) const;
	bool operator== (const char* s) const;

	// Methods
	int length() const;
	void clear();

	char* print();

private:
	char* str;

};

int string_length(const char* str);
void string_copy(const char* source, char* dest);

#endif