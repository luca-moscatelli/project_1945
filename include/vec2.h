#ifndef VEC2_H
#define VEC2_H

#include <math.h>


typedef struct {
    float x;
    float y;
} vec2;


vec2 vec2_new(float x, float y);
vec2 vec2_sub(vec2* v1, vec2* v2);
vec2 vec2_norm(vec2* v);
float vec2_magn(vec2* v);
float vec2_dot(vec2* v1, vec2* v2);
vec2 vec2_sum(vec2* v1, vec2* v2);
vec2 vec2_mul_scal(vec2* v1, float value);
#endif