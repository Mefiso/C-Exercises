#include <iostream>
#include "vector3.h"
#include "vector3.cpp"

template<class T>
void print_vec(const Vec3<T>& v, std::string name);

int main(int argc, char* argv[])
{
	Vec3<int> a;

	a.set_x(1);
	a.set_y(3);
	a.set_z(1);
	print_vec(a, "a");
	std::cout << a.length() << std::endl;

	Vec3<int> b(1, 0, 1);
	print_vec(b, "b");
	std::cout << b.length() << std::endl;

	std::cout << "a·b = " << a.dot_product(b) << std::endl;

	print_vec(a.cross_product(b), "a x b");
	print_vec(b.cross_product(a), "b x a");

	std::cout << "Angle between a and b: " << a.angle_between(b) << std::endl;

	Vec3<float> c(1.0f, 2.0f, 3.0f);
	Vec3<float> d(c);
	
	print_vec(c, "c");
	print_vec(d, "d");

	std::cout << d.length() << std::endl;
	d.Normalize();
	std::cout << "\nNormalized" << std::endl;
	print_vec(d, "d normalized");
	std::cout << d.length() << std::endl;

	Vec3<int> e = a + b;
	print_vec(e, "e");


}

template<class T>
void print_vec(const Vec3<T>& v, std::string name)
{
	std::cout << name << ": (" << v.x() << "," << v.y() << "," << v.z() << ")" << std::endl;
}

