#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "texture_manager.h"
//#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Element{
public:
    float x;
    float y;
	virtual void draw() = 0;
	virtual std::string getType() = 0;
	sf::Image  img;
	sfg::Image::Ptr image = sfg::Image::Create();
	virtual void setImage() = 0;
};

class Lamp : public Element{
public:
	Lamp(){}
	~Lamp();
    float resistance = 0;
    void draw();	
	void setImage();
	std::string getType();
};

class Resistor : public Element{
public:
	Resistor(){}
	~Resistor();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
};

class Battery : public Element{
public:
	Battery(){}
	~Battery();
    void draw();
	void setImage();
	std::string getType();
};

class Knot : public Element{
public:
	Knot();
	~Knot();
    void draw();
	void setImage() = 0;
	std::string getType();
};

class Ampermeter : public Element{
public:
	Ampermeter(){}
	~Ampermeter();
    void draw();
	void setImage();
	std::string getType();
};

class Voltmeter : public Element{
public:
	Voltmeter(){}
	~Voltmeter();
    void draw();
	void setImage();
	std::string getType();
};

class Bell : public Element{
public:
	Bell(){}
	~Bell();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
};


#endif
