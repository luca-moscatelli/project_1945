//class enemy


#ifndef ENEMY
#define ENEMY


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

} type_enemy;













#endif