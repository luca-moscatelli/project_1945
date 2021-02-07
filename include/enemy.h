//class enemy


#ifndef ENEMY
#define ENEMY


#define ENEMY_CONST_EXPLOSION_TIME 0.75f
#define ENEMY_N 6



struct game_object;

enum
{
    move,
    attack,
    dead
};
typedef unsigned char enemy_state;



typedef struct
{
    float hp;
    game_object *go;
    enemy_state state;
    float finishPointY;
    float ExplosionTime;
    float shootCount;
    int column;

} type_enemy;













#endif