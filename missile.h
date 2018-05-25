#ifndef MISSILE_H
#define MISSILE_H
#include "gameobject.h"

class Missile: public GameObject
{
protected:
    int speed, direction;
    bool crashed;
public:
    Missile(float x, float y, float width, float height, int speed, int direction);

    enum positionNames {FLYING, CRASHED};
    void draw();
    void update();
    void collision(GameObject *cw);
    void setSprites();
    bool toDestroy();
};

#endif // MISSILE_H
