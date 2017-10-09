#include "elements.h"
//#include "texture_manager.h"

void Lamp::setImage(){
	if(img.loadFromFile( "src/textures/lamp.png" )){
		printf("init new image lamp\n");
	}
	image->SetImage(img);
}

void Battery::setImage(){
	if(img.loadFromFile( "src/textures/battery.png" )){
		printf("init new image battery\n");
	}
	image->SetImage(img);
}

void Resistor::setImage(){
	if(img.loadFromFile( "src/textures/resistor.png" )){
		printf("init new image resistor\n");
	}
	image->SetImage(img);
}


void Ampermeter::setImage(){
	if(img.loadFromFile( "src/textures/ampermeter.png" )){
		printf("init new image ampermeter\n");
	}
	image->SetImage(img);
}

void Voltmeter::setImage(){
	if(img.loadFromFile( "src/textures/voltmeter.png" )){
		printf("init new image voltmeter\n");
	}
	image->SetImage(img);
}

void Bell::setImage(){
	if(img.loadFromFile( "src/textures/bell.png" )){
		printf("init new image bell\n");
	}
	image->SetImage(img);
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

