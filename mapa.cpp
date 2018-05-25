#include "mapa.h"

Mapa::Mapa(ALLEGRO_DISPLAY* display, std::string mapFilename, std::string collisionMapFilename)
{
    this->displayHeight = al_get_display_height(display);
    this->displayWidth = al_get_display_width(display);

    this->mapImage = al_load_bitmap(mapFilename.c_str());
    if(this->mapImage == NULL)
    {
        throw mapFilename;
    }

    this->collisionMapImage = al_load_bitmap(collisionMapFilename.c_str());
    if (this->collisionMapImage == NULL) {
        throw collisionMapFilename;
    }

    this->mapImageHeight = al_get_bitmap_height(this->mapImage);
    this->mapImageWidth = al_get_bitmap_width(this->mapImage);
}

ALLEGRO_BITMAP* Mapa::getCollisionMap()
{
    return this->collisionMapImage;
}

void Mapa::drawMap(float x, float y)
{
    al_identity_transform(&this->transform);
    al_translate_transform(&this->transform, -x, -y);
    al_scale_transform(&this->transform, 1.5, 1.5);
    al_translate_transform(&this->transform, this->displayWidth*0.5, this->displayHeight *0.5);
    al_use_transform(&this->transform);
    al_draw_bitmap(this->mapImage, 0, 0, 0);
}
