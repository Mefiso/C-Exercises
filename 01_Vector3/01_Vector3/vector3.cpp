#include <math.h>
#include<tuple>
#include "vector3.h"


Vec3<int>::Vec3() : components(3) {}
Vec3<float>::Vec3() : components(3) {}

Vec3<int>::Vec3(int x, int y, int z)
{
	components.push_back(x);
	components.push_back(y);
	components.push_back(z);
}
Vec3<float>::Vec3(float x, float y, float z)
{
	components.push_back(x);
	components.push_back(y);
	components.push_back(z);
}

Vec3<int>::Vec3(const Vec3& v) 
{
	components.push_back(v.x());
	components.push_back(v.y());
	components.push_back(v.z());
}
Vec3<float>::Vec3(const Vec3& v)
{
	components.push_back(v.x());
	components.push_back(v.y());
	components.push_back(v.z());
}


Vec3<int>::~Vec3()
{
	components.clear();
}
Vec3<float>::~Vec3()
{
	components.clear();
}

void Vec3<int>::Normalize()
{
	double l = this->length();
	for (auto it = this->components.begin(); it != this->components.end(); ++it)
		(*it) = (*it) / l;
}
void Vec3<float>::Normalize()
{
	double l = this->length();
	for (auto it = this->components.begin(); it != this->components.end(); ++it)
		(*it) = (*it) / l;
}


double Vec3<int>::distance_to(const Vec3<int>& v) const
{
	int diff[3] = { v.x(), v.y(), v.z()};
	double sum = 0.;
	int i = 0;
	
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		diff[i] = diff[i] - (*it);
		sum += diff[i] * diff[i];
		++i;
	}

	return sqrt(sum);
}
double Vec3<float>::distance_to(const Vec3<float>& v) const
{
	float diff[3] = { v.x(), v.y(), v.z() };
	double sum = 0.;
	int i = 0;

	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		diff[i] = diff[i] - (*it);
		sum += diff[i] * diff[i];
		++i;
	}

	return sqrt(sum);
}

int Vec3<int>::dot_product(const Vec3<int>& v) const
{
	int diff[3] = { v.x(), v.y(), v.z() };
	int result = 0;
	int i = 0;
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		result += (*it) * diff[i];
		++i;
	}
	
	return result;
}
float Vec3<float>::dot_product(const Vec3<float>& v) const
{
	float diff[3] = { v.x(), v.y(), v.z() };
	float result = 0;
	int i = 0;
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		result += (*it) * diff[i];
		++i;
	}

	return result;
}

Vec3<int> Vec3<int>::cross_product(const Vec3<int>& v) const
{
	return Vec3<int>(this->y() * v.z() - this->z() * v.y(),
					this->z() * v.x() - this->x() * v.z(),
					this->x() * v.y() - this->y() * v.x());
}
Vec3<float> Vec3<float>::cross_product(const Vec3<float>& v) const
{
	return Vec3<float>(this->y() * v.z() - this->z() * v.y(),
		this->z() * v.x() - this->x() * v.z(),
		this->x() * v.y() - this->y() * v.x());
}

double Vec3<float>::angle_between(const Vec3<float>& v) const
{
	const float dot_p = this->dot_product(v);
	const double cosinus = dot_p / (this->length() * v.length());
	
	return (180*acos(cosinus)/ 3.1416);
}
double Vec3<int>::angle_between(const Vec3<int>& v) const
{
	const int dot_p = this->dot_product(v);
	const double cosinus = dot_p / (this->length() * v.length());

	return (180 * acos(cosinus) / 3.1416);
}

Vec3<int> Vec3<int>::operator+(const Vec3<int>& v)
{
	int sum[3] = { v.x(), v.y(), v.z() };
	for (auto [it, i] = std::tuple{ this->components.begin(), 0 }; it != this->components.end(); ++it, ++i)
		sum[i] += (*it);

	return Vec3<int>(sum[0], sum[1], sum[2]);
}
Vec3<float> Vec3<float>::operator+(const Vec3<float>& v)
{
	float sum[3] = { v.x(), v.y(), v.z() };
	for (auto [it, i] = std::tuple{ this->components.begin(), 0 }; it != this->components.end(); ++it, ++i)
		sum[i] += (*it);

	return Vec3<float>(sum[0], sum[1], sum[2]);
}
