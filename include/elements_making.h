#ifndef EM
#define EM
#include "elements.h"

void Hotwire::element_making(std::string name, sf::Vector2f, int amountOfBatteries, int counter){
	if(name == "lamp"){		
		Element *temp = new Battery;
    	temp->x = sf::Vector2f().x;
    	temp->y = sf::Vector2f().y;
    	element_map[counter] = temp;
    }else if(name == "battery"){
    	amountOfBatteries++;
    	Element *temp = new Lamp;
    	temp->x = sf::Vector2f().x;
    	temp->y = sf::Vector2f().y;
    	element_map[counter] = temp;
	} else if(name == "resistor"){
    	Element *temp = new Resistor;
    	temp->x = sf::Vector2f().x;
    	temp->y = sf::Vector2f().y;
    	element_map[counter] = temp;
	/*
	}else if(name == "switcher"){
    Element *temp = new Switcher;
    temp.x = x;
    temp.y = y;
    element_map[amountOfElements] = temp;
    }
	*/
	counter++;
}

#endif
