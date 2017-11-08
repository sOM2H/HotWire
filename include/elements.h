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
	float amperage = 0;
	bool throughput = false;
	bool visited = false;
	virtual void draw() = 0;
	virtual std::string getType() = 0;

	struct ending{
		int other_element_id = -1;
		int other_element_ending_id = -1;
		int wire_id = -1;
		std::string lay = "none";
		sfg::Button::Ptr ending_button = sfg::Button::Create();

		ending(std::string lay = "none", int id = -1)
			: lay(lay)
			, other_element_id(id) {
				sfg::Image::Ptr sfg_image = sfg::Image::Create(texture_manager->sfml_image_map["loles"]);
				ending_button->SetImage(sfg_image);
			}


	};

	std::vector<ending> vector_endings;

	sf::Image img;
	sfg::Image::Ptr image = sfg::Image::Create();
	sfg::Window::Ptr option_window = sfg::Window::Create( sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND | sfg::Window::Style::CLOSE);

	sfg::Box::Ptr option_window_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	sfg::Button::Ptr option_window_ok = sfg::Button::Create();

	sfg::Box::Ptr option_window_ok_box = sfg::Box::Create();

	sfg::Box::Ptr resistance_box = sfg::Box::Create();
	sfg::Box::Ptr voltage_box = sfg::Box::Create();
	sfg::Box::Ptr indicator_box = sfg::Box::Create();
	sfg::Box::Ptr delete_box = sfg::Box::Create();
	sfg::Box::Ptr move_box = sfg::Box::Create();

	sfg::Entry::Ptr resistance_entry = sfg::Entry::Create();
	sfg::Label::Ptr resistance_label = sfg::Label::Create();
	
	sfg::Entry::Ptr voltage_entry = sfg::Entry::Create();
	sfg::Label::Ptr voltage_label = sfg::Label::Create();

	sfg::Label::Ptr indicator_label = sfg::Label::Create();

	sfg::Button::Ptr delete_button = sfg::Button::Create();
	sfg::Button::Ptr move_button = sfg::Button::Create();

	virtual void setImage() = 0;
	virtual void init_endings() = 0;;
};


class Wire{
public:
	Wire(){}
	~Wire();
	int id;
	int first_other_id = -1;
	int second_other_id = -1;
		
	int first_other_ending_id = -1;	
	int second_other_ending_id = -1;		
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
	float voltage = 0;
	void setImage();
	std::string getType();
	void init_endings();
};

class Knot : public Element{
public:
	Knot(){}
	~Knot();
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};

class Ampermeter : public Element{
public:
	Ampermeter(){}
	~Ampermeter();
    void draw();
	void setImage();
	std::string getType();
	float indicator = 0;
	void init_endings();
};

class Voltmeter : public Element{
public:
	Voltmeter(){}
	~Voltmeter();
    void draw();
	void setImage();
	std::string getType();
	float indicator = 0;
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
	bool state = true;
	void setImage();
	std::string getType();
	void init_endings();
};

class Reostat : public Element{
public:
	Reostat(){}
	~Reostat();
    float resistance = 0;
    void draw();
	void setImage();
	std::string getType();
	void init_endings();
};
#endif
