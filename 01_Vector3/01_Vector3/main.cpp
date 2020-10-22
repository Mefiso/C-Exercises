#include <iostream>
#include "vector3.h"

template<class T>
void print_vec(const Vec3<T>& v, std::string name);

int main(int argc, char* argv[])
{
	Vec3<int> a(1, 0, 1);

}

template<class T>
void print_vec(const Vec3<T>& v, std::string name)
{
	std::cout << name << ": (" << v.x() << "," << v.y() << "," << v.z() << ")" << std::endl;
}

