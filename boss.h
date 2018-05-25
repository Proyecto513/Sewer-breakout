#ifndef BOSS_H
#define BOSS_H
#include "gameobject.h"
#include <allegro5/allegro_audio.h>
#include <random>

class Boss: public GameObject
{
private:
    int hits, speed, distance, direction, hitCount, axis, originX, originY, acceleration, ticks;
    bool verticalChange, defense, positionFlag;
    ALLEGRO_SAMPLE *roarSample;

public:
    Boss(float x, float y, float width, float height, float hits, int speed, int distance, int direction, ALLEGRO_SAMPLE *roarSample);

    enum positionNames {START, ROAR, ATTACK, PROTECT};
    void draw();
    void update();
    void collision(GameObject *cw);
    void setSprites();
    bool positionChanged();
    bool toDestroy();

    void attack();
    void defend();
    void roar();
};

#endif // BOSS_H
