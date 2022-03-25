#include <stdexcept>
#include <cmath>

class Vector4D
{
private:
    float x;
    float y;
    float z;
    float w;

public:
    Vector4D() = default;

    Vector4D(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    {
    }

    float get_x() const { return x; }
    float get_y() const { return y; }
    float get_z() const { return z; }
    float get_w() const { return w; }

    float& operator [](int i) 
    {
        if(i < 0 || i > 3)
           throw std::out_of_range("invalid index");
        
        return ((&x)[i]);
    }    
    
    const float& operator [](int i) const 
    {
        if(i < 0 || i > 3)
            throw std::out_of_range("invalid index");
        
        return ((&x)[i]);
    }    

    Vector4D& operator *= (float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;

        return (*this);
    }

    Vector4D& operator /= (float s)
    {
        s = 1.0f / s;

        x *= s;
        y *= s;
        z *= s;
        w *= s;

        return (*this);
    }

};

inline Vector4D operator*(const Vector4D& v, float s)
{
    return Vector4D(v.get_x() * s, v.get_y() * s, v.get_z() * s, v.get_w() * s);
}

inline Vector4D operator / (const Vector4D& v, float s)
{
    s = 1.0f / s;
    return Vector4D(v.get_x() * s, v.get_y() * s, v.get_z() * s, v.get_w() * s );
}

inline Vector4D operator -(const Vector4D& v)
{
    return Vector4D(-v.get_x(), -v.get_y(), -v.get_z(), -v.get_w());
}

inline float Magnitude(const Vector4D& v)
{
    return (sqrt(v.get_x() * v.get_x() + v.get_y() * v.get_y() + v.get_z() * v.get_z() + v.get_w() * v.get_w()));
}

inline Vector4D Normalize(const Vector4D& v)
{
    return v / Magnitude(v);
}

inline Vector4D operator + (const Vector4D& a, const Vector4D& b)
{
    return Vector4D(a.get_x() + b.get_x(), a.get_y() + b.get_y(), a.get_z() + b.get_z(), a.get_w() + a.get_w());
}
        

inline Vector4D operator - (const Vector4D& a, const Vector4D& b)
{
    return Vector4D(a.get_x() - b.get_x(), a.get_y() - b.get_y(), a.get_z() - b.get_z(), a.get_w() - b.get_w());
}
