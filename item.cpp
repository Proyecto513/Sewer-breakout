#include "item.h"

Item::Item(float x, float y, float width, float height, int type) : GameObject(x, y, width, height)
{
	this->collected = false;
    this->type = GameObject::item;
	this->loadSpriteSheet("Sprites/items.png");
	this->setSprites();
	this->currentPosition = &this->positions[type];
}

Item::~Item()
{
}

void Item::setSprites()
{
	this->positions.insert(std::pair<int, Sprite>(Item::SHOVEL, { 34, 34, 30, 30 }));
	this->positions.insert(std::pair<int, Sprite>(Item::GEM, { 133, 197, 22, 23 }));
	this->positions.insert(std::pair<int, Sprite>(Item::LAMP, { 6, 3, 19, 27 }));
    this->positions.insert(std::pair<int, Sprite>(Item::POTION, { 360, 5, 16, 26 }));
}

void Item::draw()
{
	al_draw_bitmap_region(this->spriteSheet, this->currentPosition->sx, this->currentPosition->sy, this->currentPosition->sw, this->currentPosition->sh,
		this->getX(), this->getY(), 0);
}

void Item::update()
{
}

void Item::collision(GameObject * cw)
{
    if (cw->getType() == GameObject::player)
	{
		this->collected = true;
	}
}

bool Item::toDestroy()
{
	return this->collected;
}
