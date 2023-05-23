//#include "vectors/vector3D.h"
#include "matrices/matrix3D.h"
#include "matrices/matrix4D.h"

int main(){

    /*
    vec.print();
        vec[0] = 6;
        vec[1] = 5;
        vec[2] = 7;
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
        vec_a += vec_b;
        vec_a.print();

        vec_a = vec_a + vec_b;
        vec_a.print();

        vec_a -= vec_b;
        vec_a.print();

        vec_a = vec_a - vec_b;
        vec_a.print();
    */

   
    vector3D vec_a = vector3D(1.0f, 2.0f, 3.0f);
    vector3D vec_b = vector3D(4.0f, 5.0f, 6.0f);
    vector3D vec_c = vector3D(7.0f, 8.0f, 9.0f);

    matrix3D m = matrix3D(vec_a, vec_b, vec_c);
    matrix3D m2 = matrix3D(vec_c, vec_b, vec_a);
    m.print();
    m2.print();

    m *= m2;
    m2.print();

    vector3D vec_am = m * vec_a;
    vec_am.print();

    /*
        std::cout << std::endl;
        vector4D vec_x = vector4D(1.0f, 2.0f, 3.0f, 4.0f);
        vector4D vec_y = vector4D(5.0f, 6.0f, 7.0f, 8.0f);
        vector4D vec_z = vector4D(9.0f, 10.0f, 11.0f, 12.0f);
        vector4D vec_w = vector4D(13.0f, 14.0f, 15.0f, 16.0f);
        matrix4D m2 = matrix4D(vec_x, vec_y, vec_z, vec_w);
        m2.print();
        std::cout << std::endl;

        vec_x.print();
        std::cout << m2[0].w;
        std::cout << m2(3, 0);
    */

   float dot_a_a = vec_a * vec_a;
   float dot_a_b = vec_a * vec_b;
   std::cout << "dot_a_a: " << dot_a_a << std::endl;
   std::cout << "dot_a_b: " << dot_a_b << std::endl;
}