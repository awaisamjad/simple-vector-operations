#ifndef VEC3_H
#define VEC3_H
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846
//~ Vector Struct 3D
//? Must be float type
typedef struct
{
    float x;
    float y;
    float z;
} VEC3;

//~ VEC3 multiplied by scalar(float) and returned as VEC3
VEC3 scalar_mul_vec_3(float b, VEC3 a);

//~ VEC3 multiplied by VEC3 and returned as VEC3
VEC3 vec_mul_vec_3(VEC3 a, VEC3 b);

//~ return Magnitude of VEC3 as type float
float vec_mag_3(VEC3 a);

//~ return Normalised VEC3 as type VEC3
VEC3 vec_norm_3(VEC3 a);

//~ return Dot Product of VEC3 as type float
float dot_product_3(VEC3 a, VEC3 b);

//~ return Cross Product of VEC3 as type VEC3
VEC3 cross_product_3(VEC3 a, VEC3 b);

//~ sums n number of vectors and returns result as type VEC3
VEC3 add_vecs_3(int numberOfVectors, ...);

//~ subtracts n number of vectors and returns result as type VEC3
VEC3 sub_vecs_3(int numberOfVectors, ...);

//~ returns angle between two vectors as type float
float angle_between_vecs_3(VEC3 a, VEC3 b, char unit[7]);

//~ returns scalar triple product as type float
float scalar_triple_product_3(VEC3 a, VEC3 b, VEC3 c);

//~ returns vector triple product as type VEC3
VEC3 vector_triple_product_3(VEC3 a, VEC3 b, VEC3 c);

// //~ returns area of paralleogram formed by two vectors as type float
float area_of_parallelogram_formed_by_two_vecs_3(VEC3 a, VEC3 b);

// //~ returns area of triangle formed by two vectors as type float
float area_of_triangle_formed_by_two_vecs_3(VEC3 a, VEC3 b);

#endif // VEC3_H