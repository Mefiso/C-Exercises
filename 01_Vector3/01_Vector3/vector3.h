#ifndef VECTOR3_H
#define VECTOR3_H
#include <math.h>

template <class T>
class Vec3 {
public:
	// Constructors
	Vec3() : x(0), y(0), z(0) {}
	Vec3(T cx, T cy, T cz) : x(cx), y(cy), z(cz) {}
	Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}

	// Operations
	void Normalize()
	{
		float l = this->length();
		x = x / l;
		y = y / l;
		z = z / l;
	}

	float distance_to(const Vec3<T>& v) const 
	{
		Vec3<T> diff = this - v;
		return diff.length(); 
	}
	
	T dot_product(const Vec3<T>& v) const { return (x * v.x + y * v.y + z * v.z); }
	Vec3<T> cross_product(const Vec3<T> &v) const 
	{
		return Vec3<T>(this->y * v.z - this->z * v.y,
			this->z * v.x - this->x * v.z,
			this->x * v.y - this->y * v.x);
	}
	float angle_between(const Vec3<T> &v) const
	{
		const float cosinus = this->dot_product(v) / (this->length() * v.length());

		return (float) acos(cosinus);
	}
	float length() const { return (float)sqrt((double)this->dot_product(*this)); }

	// Component member
	T x;
	T y;
	T z;

	// Operator overload
	Vec3<T> operator+ (const Vec3<T>& v) const { return Vec3<T>(this->x + v.x, this->y + v.y, this->z + v.z); }
	Vec3<T> operator- (const Vec3<T>& v) const { return Vec3<T>(this->x - v.x, this->y - v.y, this->z - v.z); }

};

#endif