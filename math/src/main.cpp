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
}