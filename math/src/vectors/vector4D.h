#include <iostream>
#include <cmath>

class vector4D
{
public:
    float x;
    float y;
    float z;
    float w;

    vector4D() = default;

    vector4D(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    float& operator [](int i)
    {
         if(i < 0 || i > 3){
            throw std::out_of_range("please, use a valid range, for vector3D, it's only acceptable numbers between 0 and 3");
        }
        return ((&x)[i]);
    }

    const float& operator [] (int i) const
    {
        if(i < 0 || i > 3){
            throw std::out_of_range("please, use a valid range, for vector3D, it's only acceptable numbers between 0 and 3");
        }
        return ((&x)[i]);
    }

    vector4D& operator *= (float s)
    {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;

        return *this;
    }

    vector4D& operator * (float s)
    {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;

        return *this;
    }

    vector4D& operator /= (float s)
    {
        s = 1.0f / s;
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *- s;

        return *this;
    }    

    vector4D& operator / (float s)
    {
        s = 1.0f / s;
        this->x *= s;
        this->y *= s;
        this->z *= s;

        return *this;
    }

    vector4D& operator -()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        this->w = -this->w;

        return *this;
    }

    vector4D& operator += (const vector4D& vec_b)
    {
        this->x += vec_b.x;
        this->y += vec_b.y;
        this->z += vec_b.z;
        this->w += vec_b.w;

        return *this;
    }


    vector4D& operator + (const vector4D& vec_b)
    {
        this->x += vec_b.x;
        this->y += vec_b.y;
        this->z += vec_b.z;
        this->w += vec_b.w;

        return *this;
    }

    vector4D& operator -= (const vector4D& vec_b)
    {
        this->x -= vec_b.x;
        this->y -= vec_b.y;
        this->z -= vec_b.z;
        this->w -= vec_b.w;

        return *this;
    }

    vector4D& operator - (const vector4D& vec_b)
    {
        this->x -= vec_b.x;
        this->y -= vec_b.y;
        this->z -= vec_b.z;
        this->w -= vec_b.w;

        return *this;
    }


    float Magnitude()
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    vector4D& Normalize()
    {
        return (*this / Magnitude());
    }

    float operator * (const vector4D& vec_b)
    {
        return (this->x * vec_b.x + this->y * vec_b.y + this->z * vec_b.z + this->w * vec_b.z);
    }
    void print()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
        std::cout << "w = " << w << std::endl;
    }
};