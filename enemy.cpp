#include "enemy.h"

Enemy::Enemy(float x, float y, float width, float height, float hits, int speed, int distance, int direction, int axis, bool moving)
    : GameObject(x, y, width, height)
{
    this->hits = hits;
    this->hitCount = 0;
    this->direction = direction;
    this->speed = speed;
    this->acceleration = speed;
    this->moving = moving;
    this->axis = axis;
    this->distance = distance;
    this->type = GameObject::enemy;
    this->originX = getX();
    this->originY = getY();
    this->verticalChange = true;
    this->loadSpriteSheet("Sprites/cucahabla.png");
    setSprites();
	this->currentPosition = &positions[Enemy::EASY];
}

void Enemy::setSprites()
{
    this->positions.insert(std::pair<int, Sprite>(Enemy::EASY, { 0, 31, 29, 35 }));
    this->positions.insert(std::pair<int, Sprite>(Enemy::ATTACK, { 36, 32, 27, 35 }));
    this->positions.insert(std::pair<int, Sprite>(Enemy::FURIOUS, { 70, 31, 26, 37 }));
}

void Enemy::update()
{
    if (this->moving) {

        if (this->currentPosition == &positions[Enemy::FURIOUS]) {
            if ((this->getX() >= this->originX + this->speed || this->getX() <= this->originX + this->speed) && (this->getY () >= this->originY + this->speed || this->getY() <= this->originY + this->speed)) {
                if(this->axis == Enemy::X){
                    this->axis = Enemy::Y;
                } else {
                    this->axis = Enemy::X;
                }
            }
        }

        switch (this->axis) {
        case Enemy::X:
            if (this->direction == GameObject::RIGHT) {
                if (this->getX() >= this->originX + this->distance) {
                    this->direction = GameObject::LEFT;
                } else {
                    this->x += speed;
                }
            } else {
                if (this->getX() <= this->originX - this->distance) {
                    this->direction = GameObject::RIGHT;
                } else {
                    this->x -= speed;
                }
            }
            break;
        case Enemy::Y:
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
        default:
            break;
        }

    }

    if (hitCount > ((int)hits / 4)*3) {
        this->currentPosition = &positions[Enemy::FURIOUS];
        this->speed = this->acceleration * 2;
    } else if(hitCount > ((int)hits / 2)) {
        this->currentPosition = &positions[Enemy::ATTACK];
        this->speed = static_cast<int>(this->acceleration * 1.5);
    } else {
        this->currentPosition = &positions[Enemy::EASY];
    }
}

void Enemy::draw()
{
    al_draw_bitmap_region(this->spriteSheet,
                          this->currentPosition->sx,
                          this->currentPosition->sy,
                          this->currentPosition->sw,
                          this->currentPosition->sh,
                          this->x,
                          this->y,
                          this->direction == GameObject::LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
}

void Enemy::collision(GameObject *cw)
{
    if (cw->getType() == GameObject::missile) {
        this->hitCount++;
    }
}

bool Enemy::toDestroy()
{
    return (this->hitCount >= this->hits);
}
