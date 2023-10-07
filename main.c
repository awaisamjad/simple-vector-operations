#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "vec3.h"
int main()
{
	VEC3 a = {1, 2, 3};
	VEC3 b = {4, 5, 6};
	VEC3 c = {7, 8, 9};
	VEC3 d = {10, 11, 12};
	VEC3 e = {13, 14, 15};
	VEC3 a_cross_b = cross_product_3(a, b);
	printf("a_cross_b: %f, %f, %f\n", a_cross_b.x, a_cross_b.y, a_cross_b.z);
	float area_of_parallelogram_a_b = area_of_parallelogram_formed_by_two_vecs_3(a, b);
	printf("area_of_parallelogram_a_b: %f\n", area_of_parallelogram_a_b);
	VEC3 sum = add_vecs_3(5, a, b, c, d, e);
	printf("sum: %f, %f, %f\n", sum.x, sum.y, sum.z);
	return 0;
}