#include "enemymissile.h"

EnemyMissile::EnemyMissile(float x, float y, float width, float height, int speed, int direction): Missile(x,y,width, height, speed, direction)
{
    this->type = GameObject::enemy_missile;
    this->speed = speed;
    this->loadSpriteSheet("Sprites/flames.png");
    this->direction = direction;
    this->setSprites();
    this->currentPosition = &positions[Missile::FLYING];
    this->moving = true;
    this->crashed = false;
}

void EnemyMissile::setSprites()
{
    this->positions.insert(std::pair<int, Sprite>(Missile::FLYING, {4, 3, 24, 12}));
    this->positions.insert(std::pair<int, Sprite>(Missile::CRASHED, {4, 35, 27, 14}));
}

void EnemyMissile::draw()
{
    al_draw_bitmap_region(this->spriteSheet,
                          this->currentPosition->sx,
                          this->currentPosition->sy,
                          this->currentPosition->sw,
                          this->currentPosition->sh,
                          this->getX(),
                          this->getY(),
                          this->direction == GameObject::LEFT);
}

void EnemyMissile::collision(GameObject *cw)
{
        this->crashed = true;
}

void EnemyMissile::update()
{
    if (!crashed) {
        if (this->direction == GameObject::LEFT) {
            this->x -= this->speed;
        } else {
            this->x += this->speed;
        }
    } else {
        this->currentPosition = &positions[Missile::CRASHED];
    }
}


bool EnemyMissile::toDestroy()
{
    return crashed;
}
