#include "../vectors/vector3D.h"

class matrix3D
{
private:
    float n[3][3];
public:
    matrix3D() = default;

    matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12, 
             float n20, float n21, float n22){

        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }

    matrix3D(const vector3D& vec_a, const vector3D& vec_b, const vector3D& vec_c)
    {
        n[0][0] = vec_a.x; n[0][1] = vec_a.y; n[0][2] = vec_a.z;
        n[1][0] = vec_b.x; n[1][1] = vec_b.y; n[1][2] = vec_b.z;
        n[2][0] = vec_c.x; n[2][1] = vec_c.y; n[2][2] = vec_c.z;
    }

    float& operator()(int i, int j)
    {
         if(i < 0 || i > 2 || j < 0 || j > 2){
            throw std::out_of_range("please, use a valid range, for matrix3D, it's only acceptable numbers between 0 and 2");
        }

        return n[j][i];
    }

    const float& operator()(int i, int j) const
    {
        if(i < 0 || i > 2 || j < 0 || j > 2){
            throw std::out_of_range("please, use a valid range, for matrix3D, it's only acceptable numbers between 0 and 2");
        }
        return n[j][i];
    }

    vector3D& operator[](int j)
    {
        if(j < 0 || j > 2){
            throw std::out_of_range("please, use a valid range, for matrix3D, it's only acceptable numbers between 0 and 2");
        }
        return (*reinterpret_cast<vector3D*>(n[j]));
    }

    const vector3D& operator[](int j) const 
    {
          if(j < 0 || j > 2){
            throw std::out_of_range("please, use a valid range, for matrix3D, it's only acceptable numbers between 0 and 2");
        }
        return (*reinterpret_cast<const vector3D*>(n[j]));
    }

    void print()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                std::cout << n[j][i] << " ";
            }
            std::cout << std::endl;
        }
    }
};