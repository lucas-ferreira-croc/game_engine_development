#include "vectors/vector3D.h"

int main(){
    vector3D vec = vector3D(1.0f, 2.0f, 3.0f);
    vec.print();

    /*
        vec[0] = 6;
        vec[1] = 5;
        vec[2] = 7;
    */

    vec = vec * 2; 
    vec.Normalize();
    vec.print();
    std::cout << vec.Magnitude() << std::endl;
    vec /= 2;
    vec.print();
    std::cout << vec.Magnitude() << std::endl;
    vec = vec / 2;
    vec.print();
    std::cout << vec.Magnitude() << std::endl;
    vec = -vec;
    vec.print();
    std::cout << vec.Magnitude() << std::endl;

    vector3D vec_a = vector3D(1.0f, 2.0f, 3.0f);
    vector3D vec_b = vector3D(2.0f, 3.0f, 4.0f);

    vec_a += vec_b;
    vec_a.print();

    vec_a = vec_a + vec_b;
    vec_a.print();

    vec_a -= vec_b;
    vec_a.print();

    vec_a = vec_a - vec_b;
    vec_a.print();
}