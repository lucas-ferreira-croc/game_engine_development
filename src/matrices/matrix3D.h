#include <stdexcept>
#include "../vectors/vector3D.h"

class Matrix3D
{
private:
    float n[3][3];

public:
    Matrix3D() = default;

    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22) {

        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }

    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
    {
        n[0][0] = a[0]; n[0][1] = a[1]; n[0][2] = a[2];
        n[1][0] = b[0]; n[1][1] = b[2]; n[1][2] = a[2];
        n[2][0] = c[0]; n[2][1] = c[1]; n[2][2] = c[2]; 
    }

    float& operator ()(int i, int j)
    {
        return (n[j][i]);
    }

    const float& operator ()(int i, int j) const
    {
        return (n[j][i]);
    }


    Vector3D& operator [] (int j)
    {
        return (*reinterpret_cast<Vector3D *>(n[j]));
    }

    const Vector3D& operator [] (int j) const
    {
        return (*reinterpret_cast<const Vector3D *>(n[j]));
    }

};


  Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
  {
      return (Matrix3D (A(0,0) * B(0,0) + A(0,1) * B (1,0) + A(0,2) * B(2,0),
                        A(0,0) * B(0,1) + A(0,1) * B (1,1) + A(0,2) * B(2,1),
                        A(0,0) * B(0,2) + A(0,1) * B (1,2) + A(0,2) * B(2,2),

                        A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
                        A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
                        A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2), 

                        A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
                        A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
                        A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)));
  }

  Vector3D operator * (const Matrix3D& A, const Vector3D& v)
  {
      return (Vector3D(A(0,0) * v.get_x() + A(0,1) * v.get_y() + A(0,2) * v.get_z(),
                       A(1,0) * v.get_x() + A(1,1) * v.get_y() + A(1,2) * v.get_z(),
                       A(2,0) * v.get_x() + A(2,1) * v.get_y() + A(2,2) * v.get_z()
                       ));
  }

