#ifndef VEC3_H
#define VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} vec3;

vec3 vec3_new(float x, float y, float z);
vec3 vec3_sub(vec3* v1, vec3* v2);
vec3 vec3_norm(vec3* v);
float vec3_magn(vec3* v);
float vec3_dot(vec3* v1, vec3* v2);
vec3 vec3_sum(vec3* v1, vec3* v2);
vec3 vec3_mul_scal(vec3* v1, float value);   
#endif