#ifndef VECTOR3_H
#define VECTOR3_H
#include <vector>

template <class T>
class Vec3 {
public:
	// Constructors
	Vec3();
	Vec3(T x, T y, T z);
	Vec3(const Vec3 &v);
	// Destructor
	~Vec3();

	// Operations
	void Normalize();
	double distance_to(const Vec3<T> &v) const;
	T dot_product(const Vec3<T> &v) const;
	Vec3<T> cross_product(const Vec3<T> &v) const;
	double angle_between(const Vec3<T> &v) const;
	inline double length() const;

	// Components getters and setters
	inline T x() const { return components[0]; }
	inline T y() const { return components[1]; }
	inline T z() const { return components[2]; }
	
	inline void set_x(const T x) { components.insert(components.begin(), x); }
	inline void set_y(const T y) { components.insert(components.begin() + 1, y); }
	inline void set_z(const T z) { components.insert(components.begin() + 2, z); }

	// Operator overload
	Vec3<T> operator+ (const Vec3<T>& v);

private:
	std::vector<T> components;
};

#endif