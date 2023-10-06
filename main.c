#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846
//~ Vector Struct
//? Must be float type
typedef struct
{
	float x;
	float y;
	float z;
} VEC;

//~ VEC multiplied by scalar(float) and returned as VEC
VEC scalar_mul_vec(float b, VEC a)
{
	VEC c;
	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
	return c;
}

//~ VEC multiplied by VEC and returned as VEC
VEC vec_mul_vec(VEC a, VEC b)
{
	VEC c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return c;
}

//~ return Magnitude of VEC as type float
float vec_mag(VEC a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

//~ return Dot Product of VEC as type float
float dot_product(VEC a, VEC b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

//~ return Cross Product of VEC as type VEC
VEC cross_product(VEC a, VEC b)
{
	float i_comp = a.y * b.z - a.z * b.y;
	float j_comp = a.z * b.x - a.x * b.z; // Corrected calculation
	float k_comp = a.x * b.y - a.y * b.x;
	VEC cross_product = {i_comp, j_comp, k_comp};
	return cross_product;
}

//~ return Normalised VEC as type VEC
VEC vec_norm(VEC a)
{
	float norm_x = 0.0;
	float norm_y = 0.0;
	float norm_z = 0.0;
	float mag = vec_mag(a);

	if (mag == 0)
	{
		printf("Error: Cannot normalize a vector with magnitude 0\n");
		// Return a zero vector or another special value indicating an error
		return (VEC){0.0, 0.0, 0.0};
	}
	else
	{
		norm_x = a.x / mag;
		norm_y = a.y / mag;
		norm_z = a.z / mag;
	}

	VEC norm = {norm_x, norm_y, norm_z};
	return norm;
}

//~ sums n number of vectors and returns result as type VEC
VEC add_vecs(int numberOfVectors, ...)
{
	va_list args;
	va_start(args, numberOfVectors);

	VEC result = {0.0, 0.0, 0.0};

	for (int i = 0; i < numberOfVectors; ++i)
	{
		VEC vec = va_arg(args, VEC);
		result.x += vec.x;
		result.y += vec.y;
		result.z += vec.z;
	}

	va_end(args);

	return result;
}

//~ subtracts n number of vectors and returns result as type VEC
VEC sub_vecs(int numberOfVectors, ...)
{
	va_list args;
	va_start(args, numberOfVectors);
	VEC result = va_arg(args, VEC); //& gets the first value of the arguments instead of it being 0,0,0 as this wont be the actual subtraction

	for (int i = 1; i < numberOfVectors; ++i)
	{
		VEC vec = va_arg(args, VEC);
		result.x -= vec.x;
		result.y -= vec.y;
		result.z -= vec.z;
	}

	va_end(args);

	return result;
}

//~ returns angle between two vectors as type float
float angle_between_vecs(VEC a, VEC b, char unit[7])
{
	float dot = dot_product(a, b);
	float mag_a = vec_mag(a);
	float mag_b = vec_mag(b);
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

int main()
{
	VEC a = {10, 22, 20};
	VEC b = {4, 5, 6};
	VEC c = {7, 8, 9};
	VEC d = {10, 11, 12};
	VEC e = {13, 14, 15};
	VEC vector_sum = add_vecs(5, a, b, c, d, e);
	VEC vector_sub = sub_vecs(5, a, b, c, d, e);
	float mag_a = vec_mag(a);
	VEC norm_a = vec_norm(a);
	// COORDINATE norm_a = vec_norm(a);
	VEC a_cross_b = cross_product(b, a);
	VEC test = {1, 320, 0};
	float x = dot_product(a_cross_b, test);
	float angle = angle_between_vecs(a, b, "degrees");
	printf("Angle between a and b: %f\n", angle);
	// printf("Magnitude of a: {%f, %f, %f}\n", norm_a.x, norm_a.y, norm_a.z);

	return 0;
}
