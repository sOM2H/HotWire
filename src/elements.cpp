#include "elements.h"
//#include "texture_manager.h"

void Lamp::setImage(){
	if(img.loadFromFile( "src/textures/lamp.png" )){
		printf("Init new image: lamp.png\n\n");
	}
	image->SetImage(img);
}

void Lamp::init_endings(){
	
	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));

}



void Battery::setImage(){
	if(img.loadFromFile( "src/textures/battery.png" )){
		printf("Init new image: battery.png\n\n");
	}
	image->SetImage(img);
}

void Battery::init_endings(){
	
	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));

}

void Reostat::setImage(){
	if(img.loadFromFile( "src/textures/reostat.png" )){
		printf("Init new image: reostat.png\n\n");
	}
	image->SetImage(img);
}

void Reostat::init_endings(){
	
	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));

}
void Resistor::setImage(){
	if(img.loadFromFile( "src/textures/resistor.png" )){
		printf("Init new image: resistor.png\n\n");
	}
	image->SetImage(img);
}

void Resistor::init_endings(){

	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));

}


void Ampermeter::setImage(){
	if(img.loadFromFile( "src/textures/ampermeter.png" )){
		printf("Init new image: ampermeter.png\n\n");
	}
	image->SetImage(img);
}

void Ampermeter::init_endings(){

	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
}

void Voltmeter::setImage(){
	if(img.loadFromFile( "src/textures/voltmeter.png" )){
		printf("Init new image: voltmeter.png\n\n");
	}
	image->SetImage(img);
}

void Voltmeter::init_endings(){

	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
}

void Bell::setImage(){
	if(img.loadFromFile( "src/textures/bell.png" )){
		printf("Init new image: bell.png\n\n");
	}
	image->SetImage(img);
}

void Bell::init_endings()
{
	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
}

void Coil::setImage(){
	if(img.loadFromFile( "src/textures/coil.png" )){
		printf("Init new image: coil.png\n\n");
	}
	image->SetImage(img);
}

void Coil::init_endings(){ 

	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
}



void Transistor::setImage(){
	if(img.loadFromFile( "src/textures/transistor.png" )){
		printf("Init new image: transistor.png\n\n");
	}
	image->SetImage(img);
}

void Transistor::init_endings(){
	
	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
	vector_endings.push_back(ending("down"));

}

void Switch::setImage(){
	if(img.loadFromFile( "src/textures/switch.png" )){
		printf("Init new image: switch.png\n\n");
	}
	image->SetImage(img);
}

void Switch::init_endings(){

	vector_endings.push_back(ending("left"));
	vector_endings.push_back(ending("right"));
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


void Coil::draw(){
}

std::string Coil::getType(){
	return "coil";
}

void Transistor::draw(){
}

std::string Transistor::getType(){
	return "transistor";
}

void Switch::draw(){
}

std::string Switch::getType(){
	return "switch";
}


void Reostat::draw(){
}

std::string Reostat::getType(){
	return "reostat";
}
