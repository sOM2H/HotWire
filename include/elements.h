#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "texture_manager.h"
//#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Element{
public:
    int  x;
    int  y;
	int id;
	virtual void draw() = 0;
	virtual std::string getType() = 0;

	struct ending{
		int other_element_id = -1;
		std::string lay = "none";
		sfg::Button::Ptr ending_button = sfg::Button::Create();

		ending(std::string lay = "none", int id = -1)
			: lay(lay)
			, other_element_id(id) {
				sfg::Image::Ptr sfg_image = sfg::Image::Create(texture_manager->sfml_image_map["loles"]);
				//ending_button->SetSpacing(0.f);
				ending_button->SetImage(sfg_image);
			}


	};
	
	std::vector<ending> vector_endings;

	sf::Image img;
	sfg::Image::Ptr image = sfg::Image::Create();
	virtual void setImage() = 0;
	virtual void init_endings() = 0;
};

class Wire{
public:
	Wire(){}
	~Wire();
	sf::VertexArray wire;
};

class Lamp : public Element{
public:
	Lamp(){}
	~Lamp();
    float resistance = 0;
    void draw();	
	void setImage();
	std::string getType();	
	void init_endings();
};

class Resistor : public Element{
public:
	Resistor(){}
	~Resistor();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};

class Battery : public Element{
public:
	Battery(){}
	~Battery();
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
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
	void init_endings();
};

class Voltmeter : public Element{
public:
	Voltmeter(){}
	~Voltmeter();
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};

class Bell : public Element{
public:
	Bell(){}
	~Bell();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};


class Coil : public Element{
public:
	Coil(){}
	~Coil();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};


class Transistor : public Element{
public:
	Transistor(){}
	~Transistor();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};

class Switch : public Element{
public:
	Switch(){}
	~Switch();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};

#endif
