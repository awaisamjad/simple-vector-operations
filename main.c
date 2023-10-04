#include <stdio.h>
#include <math.h>
#include <stdarg.h>


typedef struct {
	float x;
	float y;
	float z;
} VEC;

typedef struct {
	float x;
	float y;
	float z;
} COORDINATE;


VEC scalar_mul_vec(VEC a, float b) {
	VEC c;
	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
	return c;
}

VEC vec_mul_vec(VEC a, VEC b) {
	VEC c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return c;
}

float vec_mag(VEC a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

float dot_product(VEC a, VEC b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

VEC cross_product(VEC a, VEC b) {
    float i_comp = a.y * b.z - a.z * b.y;
    float j_comp = a.z * b.x - a.x * b.z; // Corrected calculation
    float k_comp = a.x * b.y - a.y * b.x;
	VEC cross_product = {i_comp, j_comp, k_comp};
	return cross_product;
}


COORDINATE vec_norm(VEC a){
	float mag = vec_mag(a);
	float norm_x = a.x / mag;
	float norm_y = a.y / mag;
	float norm_z = a.z / mag;
	COORDINATE norm = {norm_x, norm_y, norm_z};
	return norm;
}

VEC add_vecs(int numberOfVectors, ...) {
    va_list args;
    va_start(args, numberOfVectors);

    VEC result = {0.0, 0.0, 0.0};

    for (int i = 0; i < numberOfVectors; ++i) {
        VEC vec = va_arg(args, VEC);
        result.x += vec.x;
        result.y += vec.y;
		result.z += vec.z;
    }

    va_end(args);

    return result;
}

VEC sub_vecs(int numberOfVectors, ...){
	va_list args;
	va_start(args, numberOfVectors);
	VEC result = va_arg(args, VEC); // gets the first value of the arguments instead of it being 0,0,0 as this wont be the actual subtraction

	for (int i = 1; i < numberOfVectors; ++i) {
        VEC vec = va_arg(args, VEC);
        result.x -= vec.x;
        result.y -= vec.y;
        result.z -= vec.z;
    }

    va_end(args);

    return result;
}

int main() {
	VEC a = { 1, 2, 3 };
	VEC b = { 4, 5, 6 };
	VEC c = { 7, 8, 9 };
	VEC d = { 10, 11, 12 };
	VEC e = { 13, 14, 15 };
	VEC vector_sum = add_vecs(5, a, b, c, d, e);
	VEC vector_sub = sub_vecs(5, a, b, c, d, e);
	float mag_a = vec_mag(a);
	COORDINATE norm_a = vec_norm(a);
	VEC a_cross_b = cross_product(b, a);
	VEC test = {1,320, 0};
	float x = dot_product(a_cross_b, test);
	// printf("Result of cross product: %f, %f, %f \n", a_cross_b.x, a_cross_b.y, a_cross_b.z);
	printf("Sum of Vectors (x: %f, y: %f, z: %f) \n", vector_sum.x, vector_sum.y, vector_sum.z);
	printf("Subtraction of Vectors (x: %f, y: %f, z: %f) \n", vector_sub.x, vector_sub.y, vector_sub.z);
	return 0;
}