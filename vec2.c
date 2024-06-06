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
VEC2 scalar_mul_vec_2(float b, VEC2 a)
{
	VEC2 c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}

//~ VEC2 multiplied by VEC2 and returned as VEC2
VEC2 vec_mul_vec_2(VEC2 a, VEC2 b)
{
	VEC2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

//~ return Magnitude of VEC2 as type float
float vec_mag_2(VEC2 a)
{
	return sqrt((a.x * a.x) + (a.y * a.y));
}

//~ return Normalised VEC2 as type VEC2
VEC2 vec_norm_2(VEC2 a)
{
	float norm_x = 0.0;
	float norm_y = 0.0;
	float mag = vec_mag_2(a);

	if (mag == 0)
	{
		printf("Error: Cannot normalize a vector with magnitude 0\n");
		// Return a zero vector or another special value indicating an error
		return (VEC2){0.0, 0.0};
	}
	else
	{
		norm_x = a.x / mag;
		norm_y = a.y / mag;
	}

	VEC2 norm = {norm_x, norm_y};
	return norm;
}

//~ return Dot Product of VEC2 as type float
float dot_product_2(VEC2 a, VEC2 b)
{
	return a.x * b.x + a.y * b.y;
}

//~ return Cross Product of VEC2 as type VEC2
float cross_product_2(VEC2 a, VEC2 b)
{   float cross_product = a.x*b.y - a.y*b.x;
	return cross_product;
}

//~ sums n number of vectors and returns result as type VEC2
VEC2 add_vecs_2(int numberOfVectors, ...)
{
	va_list args;
	va_start(args, numberOfVectors);

	VEC2 result = {0.0, 0.0};

	for (int i = 0; i < numberOfVectors; ++i)
	{
		VEC2 vec = va_arg(args, VEC2);
		result.x += vec.x;
		result.y += vec.y;
	}

	va_end(args);

	return result;
}

//~ subtracts n number of vectors and returns result as type VEC2
VEC2 sub_vecs_2(int numberOfVectors, ...)
{
	va_list args;
	va_start(args, numberOfVectors);
	VEC2 result = va_arg(args, VEC2); //& gets the first value of the arguments instead of it being 0,0,0 as this wont be the actual subtraction

	for (int i = 1; i < numberOfVectors; ++i)
	{
		VEC2 vec = va_arg(args, VEC2);
		result.x -= vec.x;
		result.y -= vec.y;
	}

	va_end(args);

	return result;
}

//~ returns angle between two vectors as type float
float angle_between_vecs_2(VEC2 a, VEC2 b, char unit[7])
{
	float dot = dot_product_2(a, b);
	float mag_a = vec_mag_2(a);
	float mag_b = vec_mag_2(b);
	float angle;

	if (mag_a == 0 || mag_b == 0)
	{
		printf("Error: One or both vectors have zero magnitude.\n");
		return 0.0; // Return zero angle in case of an error
	}

	angle = acos(dot / (mag_a * mag_b));

	if (strcmp(unit, "radians") == 0)
	{
		// Angle is already in radians
		return angle;
	}
	else if (strcmp(unit, "degrees") == 0)
	{
		// Convert angle to degrees
		return angle * (180.0 / PI);
	}
	else
	{
		// Invalid unit specified
		printf("Error: Invalid unit specified. Please use 'radians' or 'degrees'.\n");
		return 0.0; // Return zero angle in case of an error
	}
}

// //~ returns scalar triple product as type float
// float scalar_triple_product_2(VEC2 a, VEC2 b, VEC2 c)
// {
// 	float determinant = a.x * (b.y * c.z - b.z * c.y) - a.y * (b.x * c.z - b.z * c.x) + a.z * (b.x * c.y - b.y * c.x);
// 	return determinant;
// }

// //~ returns vector triple product as type VEC2
// VEC2 vector_triple_product_2(VEC2 a, VEC2 b, VEC2 c)
// {
// 	VEC2 result = cross_product_2(a, b);
// 	result = cross_product_2(result, c);
// 	return result;
// }

//~ returns area of paralleogram formed by two vectors as type float
float area_of_parallelogram_formed_by_two_vecs_2(VEC2 a, VEC2 b)
{
	float area = a.x*b.y - a.y*b.x;
    return area;
}

//~ returns area of triangle formed by two vectors as type float
float area_of_triangle_formed_by_two_vecs_2(VEC2 a, VEC2 b)
{
	return area_of_parallelogram_formed_by_two_vecs_2(a, b) / 2.0;
}
