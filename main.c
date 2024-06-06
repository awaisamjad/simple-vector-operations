#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "vec3.h"
#include "vec2.h"
int main()
{
	VEC3 a = {1, 2, 3};
	VEC3 b = {4, 5, 6};
	VEC3 c = {7, 8, 9};
	VEC3 d = {10, 11, 12};
	VEC3 e = {13, 14, 15};
	VEC2 f = {1, 2};
	VEC2 g = {3, 4};
	float anfle_f_g = angle_between_vecs_2(f, g, "degrees");
	printf("Angle between f and g is %f degrees\n", anfle_f_g);
	float angle_a_b = angle_between_vecs_3(a, b, "degrees");
    printf("Angle between a and b is %f degrees\n", angle_a_b);
	return 0;
}