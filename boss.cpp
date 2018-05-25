#include "boss.h"

Boss::Boss(float x, float y, float width, float height, float hits, int speed, int distance, int direction, ALLEGRO_SAMPLE *roarSample)
    : GameObject(x, y, width, height)
{
    this->hits = hits;
    this->hitCount = 0;
    this->direction = direction;
    this->speed = speed;
    this->acceleration = speed;
    this->distance = distance;
    this->type = GameObject::boss;
    this->originX = getX();
    this->originY = getY();
    this->verticalChange = true;
    this->loadSpriteSheet("Sprites/Heckran_Sprites.png");
    setSprites();
    this->ticks = 30;
    this->currentPosition = &this->positions[Boss::START];
    this->roarSample = roarSample;
    this->positionFlag = false;
}

void Boss::setSprites()
{
    this->positions.insert(std::pair<int, Sprite>(Boss::START, { 68, 236, 47, 53 }));
    this->positions.insert(std::pair<int, Sprite>(Boss::PROTECT, { 371, 0, 42, 49 }));
    this->positions.insert(std::pair<int, Sprite>(Boss::ROAR, { 70, 62, 40, 45 }));
    this->positions.insert(std::pair<int, Sprite>(Boss::ATTACK, { 68, 119, 46, 52 }));
}

void Boss::update()
{
    if (verticalChange) {
        if (this->getY() >= this->originY + this->distance) {
            verticalChange = false;
        } else {
            this->y += speed;
        }
    } else {
        if (this->getY() <= this->originY - this->distance) {
            verticalChange = true;
        } else {
            this->y -= speed;
        }
    }

    if (ticks == 0) {
        switch(rand() % 10){
        case 2:
            this->attack();
            break;
        case 5:
            this->defend();
            break;
        case 8:
            this->roar();
            break;
        default:
            this->currentPosition = &positions[Boss::START];
            break;
        }
        positionFlag = true;
        this->ticks = 30;
    } else {
        this->ticks--;
    }
}

void Boss::attack()
{
    this->currentPosition = &this->positions[Boss::ATTACK];
}

void Boss::defend()
{
    this->currentPosition = &this->positions[Boss::PROTECT];
}

void Boss::roar()
{
    this->currentPosition = &this->positions[Boss::ROAR];
    al_play_sample(this->roarSample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Boss::draw()
{
    al_draw_bitmap_region(this->spriteSheet,
        this->currentPosition->sx,
        this->currentPosition->sy,
        this->currentPosition->sw,
        this->currentPosition->sh,
        this->x,
        this->y,
        0);
}

void Boss::collision(GameObject* cw)
{
    if (cw->getType() == GameObject::missile) {
        this->hitCount++;
    }
}

bool Boss::positionChanged(){
    if (positionFlag) {
        positionFlag = false;
        return true;
    } else {
        return positionFlag;
    }

}

bool Boss::toDestroy()
{
    return (this->hitCount >= this->hits);
}
