#ifndef MAPA_H
#define MAPA_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <string>

class Mapa
{
private:
    ALLEGRO_BITMAP* mapImage;
    ALLEGRO_BITMAP* collisionMapImage;
    ALLEGRO_TRANSFORM transform;
    float moveX, moveY;
    int mapImageWidth, mapImageHeight,displayWidth, displayHeight;

public:
    Mapa(ALLEGRO_DISPLAY* display, std::string mapFilename, std::string collisionMapFilename);
    void drawMap(float x, float y);
    ALLEGRO_BITMAP* getCollisionMap();
};

#endif // MAPA_H
