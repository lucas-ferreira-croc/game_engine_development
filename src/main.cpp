#include <iostream>
#include "vectors/vector3D.h"

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

  v = Normalize(v);
  x = Normalize(x);

  std::cout << Magnitude(v) << std::endl;
  std::cout << Magnitude(x) << std::endl;
}
