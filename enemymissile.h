#ifndef ENEMYMISSILE_H
#define ENEMYMISSILE_H
#include "missile.h"

class EnemyMissile : public Missile
{
public:
    EnemyMissile(float x, float y, float width, float height, int speed, int direction);
    void draw();
    void update();
    void collision(GameObject *cw);
    void setSprites();
    bool toDestroy();
};

#endif // ENEMYMISSILE_H
