#ifndef MANAGER_H
#define MANAGER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <vector>
#include <string>
#include "boss.h"

class Hero;
class GameObject;
class Mapa;

class Manager
{
private:
    std::vector<GameObject*> gameObjectList; // Vector de objetos de juego
    std::vector<Mapa*> mapList; // Vector de mapas
    static Manager* instance; // Instancia unica del administrador
    int currentMap, currentLevel;
    ALLEGRO_TRANSFORM transform;
    ALLEGRO_FONT* statsFont;
    Boss *bossref;
    bool bossSaved;
	int enemies;
    Manager(); // Constructor

public:
    bool GameOver; // Bandera que indica el fin de juego
    static Manager* Instance(); // Metodo que crea o regresa la instancia unica del administrador del juego
    ~Manager(); // Destructor
    Hero *mainHeroe; // Objeto del heroe principar
    void UpdateGameObjects(); // Metodo sin retorno que actualiza los objetos del juego
    void initStatsFont();
    void DrawGameObjects(); // Metodo sin retorno que establece los parametros para el dibujo de los objetos de juego
    void DrawStats(); // Metodo sin retorno que dibuja en pantalla las estadisticas del jugador

    void AddGameObject(GameObject* newObject); // Metodo sin retorno para añadir el objeto `newObject` a la lista de objetos de juego
    void AddMap(Mapa* newMap); // Metodo sin retorno para añadir el objeto `newMap` a la lista de mapas
	void clearGameObjectList();
	void informLevel(int i);
	int getEnemiesCount();

    void setHero();
    void setCurrentMap(int index); // Metodo sin retorno para establecer como actual el mapa con indice `index` en las coordenadas `x` y `y`
    Mapa* getCurrentMap();
    void CheckCollissions(); // Metodo sin retorno para detectar collisiones
    void boundingBox(GameObject* receiver, GameObject* collisioner);
};

#endif // MANAGER_H
