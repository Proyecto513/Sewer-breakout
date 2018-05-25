TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lallegro -lallegro_dialog -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec

SOURCES += \
    main.cpp \
    engine.cpp \
    manager.cpp \
    hero.cpp \
    gameobject.cpp \
    mapa.cpp \
    missile.cpp \
    enemy.cpp \
    boss.cpp \
    enemymissile.cpp \
    item.cpp

HEADERS += \
    engine.h \
    manager.h \
    hero.h \
    gameobject.h \
    mapa.h \
    missile.h \
    enemy.h \
    boss.h \
    enemymissile.h \
    item.h

