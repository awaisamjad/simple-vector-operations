#ifndef VEC2_H
#define VEC2_H

#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846
typedef struct
{
    float x;
    float y;
} VEC2;
//~ VEC2 multiplied by scalar(float) and returned as VEC2
VEC2 scalar_mul_vec_2(float b, VEC2 a);

//~ VEC2 multiplied by VEC2 and returned as VEC2
VEC2 vec_mul_vec_2(VEC2 a, VEC2 b);

//~ return Magnitude of VEC2 as type float
float vec_mag_2(VEC2 a);

//~ return Normalised VEC2 as type VEC2
VEC2 vec_norm_2(VEC2 a);

//~ return Dot Product of VEC2 as type float
float dot_product_2(VEC2 a, VEC2 b);

//~ return Cross Product of VEC2 as type VEC2
float cross_product_2(VEC2 a, VEC2 b);
//~ sums n number of vectors and returns result as type VEC2
VEC2 add_vecs_2(int numberOfVectors, ...);

//~ subtracts n number of vectors and returns result as type VEC2
VEC2 sub_vecs_2(int numberOfVectors, ...);

//~ returns angle between two vectors as type float
float angle_between_vecs_2(VEC2 a, VEC2 b, char unit[7]);

// //~ returns scalar triple product as type float
// float scalar_triple_product_2(VEC2 a, VEC2 b, VEC2 c);

// //~ returns vector triple product as type VEC2
// VEC2 vector_triple_product_2(VEC2 a, VEC2 b, VEC2 c);

//~ returns area of paralleogram formed by two vectors as type float
float area_of_parallelogram_formed_by_two_vecs_2(VEC2 a, VEC2 b);

//~ returns area of triangle formed by two vectors as type float
float area_of_triangle_formed_by_two_vecs_2(VEC2 a, VEC2 b);

#endif // !VEC2_H