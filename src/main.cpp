#include <iostream>
//#include "vectors/vector3D.h"
#include "vectors/vector4D.h"
#include "matrices/matrix3D.h"

int main(){
  Vector3D v(3.7f, 5.3f, 7.5f);
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

  std::cout << "Multiplicating the vector by 2.0f" << std::endl;
  Vector3D x(1.0f, 2.0f, 3.0f);
  v = v * 2.0f;

  std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

  v *= 3.0f;
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

  x /= 2.0f;

  v = v / 3.0f;

  std::cout << "Magnitude of v " << Magnitude(v) << std::endl;
  std::cout << "Magnitude of x " << Magnitude(x) << std::endl;

  x = x + v;
  v = v - x;

  std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

  //v = Normalize(v);
  //x = Normalize(x);

  std::cout << Magnitude(v) << std::endl;
  std::cout << Magnitude(x) << std::endl;

  Matrix3D m_one(1.0f, 2.0f, 3.0f,
                 4.0f, 5.0f, 6.0f,
                 7.0f, 8.0f, 9.0f);

  Vector3D c(8.0f, 9.0f, 10.0f);
  Matrix3D m_two(v, x, c);

  Vector4D(1.0f, 2.0f, 3.0f, 4.0f);

  Vector3D test = m_one[0];
  std::cout << test[0] << " " << test[1] << " " << test[2] << std::endl;

 m_one = m_one * m_two;

 Vector3D matrix_multiplication_vector = m_one * test;

  std::cout << matrix_multiplication_vector[0] << " " << matrix_multiplication_vector[1] << " " << matrix_multiplication_vector[2] << std::endl; 
}
