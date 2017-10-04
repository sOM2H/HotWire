#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "texture_manager.h"

class Elements {
    public:
	int x;
	int y;
	virtual void draw();
}

class Lamp : public Elements{
    float resistance = 0;
    void draw();
}

class Resistor : public Elements{
    float resistance = 0;
    void draw();
}

#endif
