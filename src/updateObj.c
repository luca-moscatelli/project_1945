// #include "global_variables.h"
// #include "bulletMng.h"
// #include "playerMng.h"
// #include <stdlib.h>
// #include "enemyMng.h"
// #include "powerUp_Mng.h"
#include "updateObj.h"
#include "bulletMng.h"



float offset_background;


float bgVelocity = 100;

int _updateIsland()
{
    for (size_t i = 0; i < 3; i++)
    {

        if (island[i]->target_rect->y >= SCREEN_HEIGHT)
        {
            island[i]->target_rect->y = RangedRandDemo(-600, -100);
            island[i]->target_rect->x = RangedRandDemo(10, SCREEN_WIDTH - 40);
        }

        island[i]->target_rect->y += bgVelocity * STANDARD_VELOCITY;
    }

    return 0;
}

int _updateSea()
{
    if (offset_background >= global_unitSize.y - 70)
    {
        offset_background = -70;
    }

    water->target_rect->y = offset_background;

    offset_background += bgVelocity * STANDARD_VELOCITY;

    return 0;
}

void update()
{
    _updateIsland();

    enemyUpdate();

    updateBullet();

    _updateSea();

    UpdatePlayer();

    PowerUp_update();

}