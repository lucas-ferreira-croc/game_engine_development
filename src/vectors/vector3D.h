#include <stdexcept>
#include <cmath>

class Vector3D
{
private:
    float x;
    float y;
    float z;

public:
    Vector3D() = default;

    Vector3D(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    float get_x() const { return x; }
    float get_y() const { return y; }
    float get_z() const { return z; }

    void set_x(float x) { this->x = x;}
    void set_y(float y) { this->y = y;}
    void set_z(float z) { this->z = z;}

    float& operator [](int i) 
    {
        if(i < 0 || i > 2)
           throw std::out_of_range("invalid index");
        
        return ((&x)[i]);
    }    
    
    const float& operator [](int i) const 
    {
        if(i < 0 || i > 2)
            throw std::out_of_range("invalid index");
        
        return ((&x)[i]);
    }    

    Vector3D& operator *= (float s)
    {
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    }

    Vector3D& operator /= (float s)
    {
        s = 1.0f / s;

        x *= s;
        y *= s;
        z *= s;

        return (*this);
    }

};

inline Vector3D operator*(const Vector3D& v, float s)
{
    return { v.get_x() * s, v.get_y() * s, v.get_z() * s };
}

inline Vector3D operator / (const Vector3D& v, float s)
{
    s = 1.0f / s;
    return Vector3D(v.get_x() * s, v.get_y() * s, v.get_z() * s);
}

inline Vector3D operator -(const Vector3D& v)
{
    return Vector3D(-v.get_x(), -v.get_y(), -v.get_z());
}

inline float Magnitude(const Vector3D& v)
{
    return (sqrt(v.get_x() * v.get_x() + v.get_y() * v.get_y() + v.get_z() * v.get_z()));
}

inline Vector3D Normalize(const Vector3D& v)
{
    return v / Magnitude(v);
}

inline Vector3D operator + (const Vector3D& a, const Vector3D& b)
{
    return {a.get_x() + b.get_x(), a.get_y() + b.get_y(), a.get_z() + b.get_z() };
}
        

inline Vector3D operator - (const Vector3D& a, const Vector3D& b)
{
    return {a.get_x() - b.get_x(), a.get_y() - b.get_y(), a.get_z() - b.get_z() };
}
