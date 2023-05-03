#include <iostream>

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

    void print()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
};