#include "../vectors/vector4D.h"

class matrix4D
{
private:
    float n[4][4];
public:
    matrix4D() = default;

    matrix4D(float n00, float n01, float n02, float n03,
             float n10, float n11, float n12, float n13,
             float n20, float n21, float n22, float n23,
             float n30, float n31, float n32, float n33){

        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
        n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
    }

    matrix4D(const vector4D& vec_a, const vector4D& vec_b, const vector4D& vec_c, const vector4D& vec_d)
    {
        n[0][0] = vec_a.x; n[0][1] = vec_a.y; n[0][2] = vec_a.z; n[0][3] = vec_a.w;
        n[1][0] = vec_b.x; n[1][1] = vec_b.y; n[1][2] = vec_b.z; n[1][3] = vec_b.w;
        n[2][0] = vec_c.x; n[2][1] = vec_c.y; n[2][2] = vec_c.z; n[2][3] = vec_c.w;
        n[3][0] = vec_d.x; n[3][1] = vec_d.y; n[3][2] = vec_d.z; n[3][3] = vec_d.w;
    }

    float& operator()(int i, int j)
    {
         if(i < 0 || i > 3 || j < 0 || j > 3){
            throw std::out_of_range("please, use a valid range, for matrix4D, it's only acceptable numbers between 0 and 3");
        }

        return n[j][i];
    }

    const float& operator()(int i, int j) const
    {
        if(i < 0 || i > 3 || j < 0 || j > 3){
            throw std::out_of_range("please, use a valid range, for matrix4D, it's only acceptable numbers between 0 and 3");
        }
        return n[j][i];
    }

    vector4D& operator[](int j)
    {
        if(j < 0 || j > 3){
            throw std::out_of_range("please, use a valid range, for matrix4D, it's only acceptable numbers between 0 and 3");
        }
        return (*reinterpret_cast<vector4D*>(n[j]));
    }

    const vector4D& operator[](int j) const 
    {
        if(j < 0 || j > 3){
            throw std::out_of_range("please, use a valid range, for matrix4D, it's only acceptable numbers between 0 and 3");
        }
        return (*reinterpret_cast<const vector4D*>(n[j]));
    }

    void print()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                std::cout << n[j][i] << " ";
            }
            std::cout << std::endl;
        }
    }
};