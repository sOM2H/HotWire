#ifndef TM 
#define TM
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<SFML/Graphics.hpp>
#include<string>

class TextureManager {
    public:
        TextureManager(){}
        ~TextureManager();
        std::map<std::string, sf::Texture> texture_map;
	std::map<std::string, sf::Image> image_map;
        void load(std::string filename, std::string texture_name);
};

extern TextureManager* texture_manager;

#endif
