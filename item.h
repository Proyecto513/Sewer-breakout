#pragma once
#include "gameobject.h"

class Item: public GameObject
{
public:
	Item(float x, float y, float width, float height, int type);
	~Item();
	bool collected;
	enum itemTypes {SHOVEL, POTION, GEM, LAMP};
	void setSprites();
	void draw();
	void update();
	void collision(GameObject * cw);
	bool toDestroy();

};
