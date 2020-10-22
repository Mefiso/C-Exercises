#include <math.h>
#include<tuple>
#include "vector3.h"

template <class T>
Vec3<T>::Vec3() : components(3) {}

template<class T>
Vec3<T>::Vec3(T x, T y, T z)
{
	components.push_back(x);
	components.push_back(y);
	components.push_back(z);
}

template<class T>
Vec3<T>::Vec3(const Vec3& v) 
{
	components.push_back(v.x());
	components.push_back(v.y());
	components.push_back(v.z());
}

template<class T>
Vec3<T>::~Vec3()
{
	components.clear();
}

template<class T>
void Vec3<T>::Normalize()
{
	double l = this->length();
	for (auto it = this->components.begin(); it != this->components.end(); ++it)
		(*it) = (*it) / l;
}

template<class T>
double Vec3<T>::distance_to(const Vec3<T>& v) const
{
	T diff[3] = { v.x(), v.y(), v.z()};
	double sum = 0.;
	int i = 0;
	
	for (auto [it, i] = std::tuple{ this->components.begin(), 0 }; it != this->components.end(); ++it, ++i) {
		diff[i] -= (*it);
		sum += diff[i] * diff[i];
	}

	return sqrt(sum);
}

template<class T>
T Vec3<T>::dot_product(const Vec3<T>& v) const
{
	T diff[3] = { v.x(), v.y(), v.z() };
	T result = 0;
	int i = 0;
	for (auto [it, i] = std::tuple{ this->components.begin(), 0 }; it != this->components.end(); ++it, ++i)
		result += (*it) * diff[i];
	
	return result;
}

template<class T>
Vec3<T> Vec3<T>::cross_product(const Vec3<T>& v) const
{
	return Vec3<T>(this->y() * v.z() - this->z() * v.y(),
					this->z() * v.x() - this->x() * v.z(),
					this->x() * v.y() - this->y() * v.x());
}

template<class T>
double Vec3<T>::angle_between(const Vec3<T>& v) const
{
	const T dot_p = this->dot_product(v);
	const double cosinus = dot_p / (this->length() * v.length());
	
	return (180*acos(cosinus)/ 3.1416);
}

template<class T>
inline double Vec3<T>::length() const
{
	return sqrt((double) this->dot_product(*this));
}

template<class T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& v)
{
	T sum[3] = { v.x(), v.y(), v.z() };
	for (auto [it, i] = std::tuple{ this->components.begin(), 0 }; it != this->components.end(); ++it, ++i)
		sum[i] += (*it);

	return Vec3<T>(sum[0], sum[1], sum[2]);
}
