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

    matrix3D operator *= (const matrix3D& b)
    {
                        // AB[0][0]
        return  matrix3D(
                        (*this)(0,0) * b(0,0) + (*this)(0,1) * b(1,0) + (*this)(0,2) * b(2,0),
                        // AB[0][1]
                        (*this)(0,0) * b(0,1) + (*this)(0,1) * b(1,1) + (*this)(0,2) * b(2,1),
                        //AB[0][2]
                        (*this)(0,0) * b(0,2) + (*this)(0,1) * b(1,2) + (*this)(0,2) * b(2,2),
                        //AB[1][0]
                        (*this)(1,0) * b(0,0) + (*this)(1,1) * b(1,0) + (*this)(1,2) * b(2,0),
                        //AB[1][1]
                        (*this)(1,0) * b(0,1) + (*this)(1,1) * b(1,1) + (*this)(1,2) * b(2,1),
                        //AB[1][2]
                        (*this)(1,0) * b(0,2) + (*this)(1,1) * b(1,2) + (*this)(1,2) * b(2,2),
                        //AB[2][0]
                        (*this)(2,0) * b(0,0) + (*this)(2,1) * b(1,0) + (*this)(2,2) * b(2,0),
                        //AB[2][1]
                        (*this)(2,0) * b(0,1) + (*this)(2,1) * b(1,1) + (*this)(2,2) * b(2,1),
                        //AB[2][2]
                        (*this)(2,0) * b(0,2) + (*this)(2,1) * b(1,2) + (*this)(2,2) * b(2,2)
        );
    }


    matrix3D operator * (const matrix3D& b)
    {
                        // AB[0][0]
        return  matrix3D(
                        (*this)(0,0) * b(0,0) + (*this)(0,1) * b(1,0) + (*this)(0,2) * b(2,0),
                        // AB[0][1]
                        (*this)(0,0) * b(0,1) + (*this)(0,1) * b(1,1) + (*this)(0,2) * b(2,1),
                        //AB[0][2]
                        (*this)(0,0) * b(0,2) + (*this)(0,1) * b(1,2) + (*this)(0,2) * b(2,2),
                        //AB[1][0]
                        (*this)(1,0) * b(0,0) + (*this)(1,1) * b(1,0) + (*this)(1,2) * b(2,0),
                        //AB[1][1]
                        (*this)(1,0) * b(0,1) + (*this)(1,1) * b(1,1) + (*this)(1,2) * b(2,1),
                        //AB[1][2]
                        (*this)(1,0) * b(0,2) + (*this)(1,1) * b(1,2) + (*this)(1,2) * b(2,2),
                        //AB[2][0]
                        (*this)(2,0) * b(0,0) + (*this)(2,1) * b(1,0) + (*this)(2,2) * b(2,0),
                        //AB[2][1]
                        (*this)(2,0) * b(0,1) + (*this)(2,1) * b(1,1) + (*this)(2,2) * b(2,1),
                        //AB[2][2]
                        (*this)(2,0) * b(0,2) + (*this)(2,1) * b(1,2) + (*this)(2,2) * b(2,2)
        );
    }

    vector3D operator * (const vector3D& v)
    {
        return vector3D(
            (*this)(0, 0) * v.x + (*this)(0,1) * v.y + (*this)(0, 2) * v.z,
            (*this)(1, 0) * v.x + (*this)(1,1) * v.y + (*this)(1, 2) * v.z,
            (*this)(2, 0) * v.x + (*this)(2,1) * v.y + (*this)(2, 2) * v.z
        );
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