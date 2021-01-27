



#include "vec2.h"


vec2 vec2_new(float x, float y)
{
    vec2 v;
    v.x = x;
    v.y = y;
    return v;
}

vec2 vec3_sub(vec2 *v1, vec2 *v2)
{
    vec2 r;
    r.x = v1->x - v2->x;
    r.y = v1->y - v2->y;
    return r;
}

vec2 vec2_norm(vec2 *v)
{
    vec2 n;
    float magn = vec2_magn(v);
    n.x = v->x / magn;
    n.y = v->y / magn;
    return n;
}

float vec2_magn(vec2 *v)
{
    return sqrtf(v->x * v->x + v->y * v->y);
}

float vec2_dot(vec2 *v1, vec2 *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

vec2 vec2_mul_scal(vec2 *v1, float value)
{
    vec2 r;
    r.x = v1->x * value;
    r.y = v1->y * value;
    return r;
}

vec2 vec2_sum(vec2 *v1, vec2 *v2)
{
    vec2 r;
    r.x = v1->x + v2->x;
    r.y = v1->y + v2->y;
    return r;
}
