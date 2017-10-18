#include "elements.h"
//#include "texture_manager.h"

void Lamp::setImage(){
	if(img.loadFromFile( "src/textures/lamp.png" )){
		printf("Init new image: lamp.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); second_ending.setPosition(sf::Vector2f(-1, -1));


}

void Battery::setImage(){
	if(img.loadFromFile( "src/textures/battery.png" )){
		printf("Init new image: battery.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); second_ending.setPosition(sf::Vector2f(-1, -1));
}

void Resistor::setImage(){
	if(img.loadFromFile( "src/textures/resistor.png" )){
		printf("Init new image: resistor.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); second_ending.setPosition(sf::Vector2f(-1, -1));
}


void Ampermeter::setImage(){
	if(img.loadFromFile( "src/textures/ampermeter.png" )){
		printf("Init new image: ampermeter.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); second_ending.setPosition(sf::Vector2f(-1, -1));
}

void Voltmeter::setImage(){
	if(img.loadFromFile( "src/textures/voltmeter.png" )){
		printf("Init new image: voltmeter.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); second_ending.setPosition(sf::Vector2f(-1, -1));
}

void Bell::setImage(){
	if(img.loadFromFile( "src/textures/bell.png" )){
		printf("Init new image: bell.png\n\n");
	}
	image->SetImage(img);

	first_ending.setRadius(5.f);
	first_ending.setFillColor(sf::Color::White);

	second_ending.setRadius(5.f);
	second_ending.setFillColor(sf::Color::White);

	first_ending.setPosition(sf::Vector2f(-1, -1)); 
	second_ending.setPosition(sf::Vector2f(-1, -1));
}


void Lamp::draw(){
}

std::string Lamp::getType(){
	return "lamp";
}

void Battery::draw(){
}

std::string Battery::getType(){
	return "battery";
}

void Resistor::draw(){
}

std::string Resistor::getType(){
	return "resistor";
}

void Knot::draw(){
}

std::string Knot::getType(){
	return "knot";
}


void Voltmeter::draw(){
}

std::string Voltmeter::getType(){
	return "voltmeter";
}

void Ampermeter::draw(){
}

std::string Ampermeter::getType(){
	return "ampermeter";
}


void Bell::draw(){
}

std::string Bell::getType(){
	return "bell";
}

