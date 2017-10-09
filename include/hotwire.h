#ifndef TM_H
#define TM_H
#define WS_W render_window.getSize().x
#define WS_H render_window.getSize().y
#define SFGUI_WS_W (render_window.getSize().x - sfgui_window_bar->GetAllocation().width) 
#define SFGUI_WS_H render_window.getSize().y 
#define SFGUI_WS_BAR_W sfgui_window_bar->GetAllocation().width
#define SFGUI_WS_BAR_H render_window.getSize().y

//#include "texture_manager.h"
#include "elements.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <memory>

class Hotwire{
    public: 
        Hotwire();
        ~Hotwire();

        sf::RenderWindow render_window;
		sfg::SFGUI sfgui;

		sf::Mouse mouse;

		sfg::Window::Ptr sfgui_window = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_menu = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_pause = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_bar = sfg::Window::Create();
		
		std::map<std::string, sfg::Image::Ptr> image_map;

		//Element element;
		sfg::Fixed::Ptr fixed = sfg::Fixed::Create();
		void init_image(const std::string & name);

		std::map<int , Element* > element_map;	
		
		std::string buffer = "empty";
        bool running = false;

		int amountOfBatteries = 0;
		int counter = 0;

		int  element_making(std::string name, sf::Vector2f, int amountOfBatteries, int counter);

        void init();
        void handle_events();
        void render();
        void update();
        void clear();
};
#endif
