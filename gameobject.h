#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <string>
#include <map>

class GameObject
{
protected:
    float x, y, height, width;
    ALLEGRO_BITMAP* spriteSheet;
    struct Sprite {
        float sx, sy, sw, sh;
    };
    int id, type;
    std::map<int, Sprite> positions;
    Sprite* currentPosition;
    bool moving;

public:
    GameObject(float x, float y, float width, float height);
    int getType();
    int getId();
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    bool isMoving();
    enum types {player, enemy, missile, enemy_missile, item, boss};
    enum directions {LEFT, RIGHT};
    void loadSpriteSheet(std::string fileName);
    void getBounds(float *x, float *y, float *finalX, float *finalY);
    void setPosition(float x, float y);

    virtual void setSprites() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void collision(GameObject* cw) = 0;
    virtual bool toDestroy() = 0;
    virtual ~GameObject() {}

};

#endif // GAMEOBJECT_H
