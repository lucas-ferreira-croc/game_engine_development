#include <iostream>
#include <cmath>
#include <stdexcept>

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
        if(i < 0 || i > 2){
            throw std::out_of_range("please, use a valid range, for vector3D, it's only acceptable numbers between 0 and 2");
        }

        return ((&x)[i]);
    }

    const float& operator [] (int i) const
    {
        if(i < 0 || i > 2){
            throw std::out_of_range("please, use a valid range, for vector3D, it's only acceptable numbers between 0 and 2");
        }
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

    vector3D& operator += (const vector3D& vec_b)
    {
        this->x += vec_b.x;
        this->y += vec_b.y;
        this->z += vec_b.z;
        return *this;
    }


    vector3D& operator + (const vector3D& vec_b)
    {
        this->x += vec_b.x;
        this->y += vec_b.y;
        this->z += vec_b.z;
        return *this;
    }

    vector3D& operator -= (const vector3D& vec_b)
    {
        this->x -= vec_b.x;
        this->y -= vec_b.y;
        this->z -= vec_b.z;
        return *this;
    }

    vector3D& operator - (const vector3D& vec_b)
    {
        this->x -= vec_b.x;
        this->y -= vec_b.y;
        this->z -= vec_b.z;
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

    float operator * (const vector3D& vec_b)
    {
        return (this->x * vec_b.x + this->y * vec_b.y + this->z * vec_b.z);
    }

    vector3D Cross(const vector3D& vec_b)
    {
        return vector3D(this->y * vec_b.z - this->z * vec_b.y,
                        this->z * vec_b.x - this->x * vec_b.z,
                        this->x - vec_b.y - this->y * vec_b.x
                    );
    }
    void print()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
};