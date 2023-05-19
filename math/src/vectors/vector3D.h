#include <iostream>
#include <cmath>

class vector3D
{
public:
    float x;
    float y;
    float z;

    vector3D() = default;

    vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [] (int i) const
    {
        return ((&x)[i]);
    }

    vector3D& operator *= (float s)
    {
        this->x *= s;
        this->y *= s;
        this->z *= s;

        return *this;
    }

    vector3D& operator * (float s)
    {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    vector3D& operator /= (float s)
    {
        s = 1.0f / s;
        this->x *= s;
        this->y *= s;
        this->z *= s;

        return *this;
    }    

    vector3D& operator / (float s)
    {
        s = 1.0f / s;
        this->x *= s;
        this->y *= s;
        this->z *= s;

        return *this;
    }

    vector3D& operator -()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        return *this;
    }

    float Magnitude()
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    vector3D& Normalize()
    {
        return (*this / Magnitude());
    }

    void print()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
};