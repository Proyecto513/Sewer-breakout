#include "missile.h"

Missile::Missile(float x, float y, float width, float height, int speed, int direction): GameObject(x, y, width, height)
{
    this->type = GameObject::missile;
    this->speed = speed;
    this->loadSpriteSheet("Sprites/moco.png");
    this->direction = direction;
    this->setSprites();
    this->currentPosition = &positions[Missile::FLYING];
    this->moving = true;
    this->crashed = false;
}

void Missile::setSprites()
{
    this->positions.insert(std::pair<int, Sprite>(Missile::FLYING, {2, 4, 26, 22}));
    this->positions.insert(std::pair<int, Sprite>(Missile::CRASHED, {38, 7, 21, 25}));
}

void Missile::draw()
{
    al_draw_bitmap_region(this->spriteSheet,
                          this->currentPosition->sx,
                          this->currentPosition->sy,
                          this->currentPosition->sw,
                          this->currentPosition->sh,
                          this->getX(),
                          this->getY(),
                          this->direction == GameObject::LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
}

void Missile::collision(GameObject *cw)
{
    if (cw->getType() != GameObject::item) {
        this->crashed = true;
    }
}

void Missile::update()
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


bool Missile::toDestroy()
{
    return crashed;
}
