#ifndef TM_H
#define TM_H
#define WS_W render_window.getSize().x
#define WS_H render_window.getSize().y
#define WS_BAR_W (render_window.getSize().x)*0.06
#define WS_BAR_H render_window.getSize().y
#include "texture_manager.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>


class Hotwire{
    public: 
        Hotwire();
        ~Hotwire();

        sf::RenderWindow render_window;
	sfg::Desktop desktop;
	sfg::Canvas::Ptr canvas = sfg::Canvas::Create();
	sfg::SFGUI sfgui;

	sfg::Window::Ptr sfgui_window = sfg::Window::Create();
	sfg::Window::Ptr sfgui_window_menu = sfg::Window::Create();
	sfg::Window::Ptr sfgui_window_pause = sfg::Window::Create();
	sfg::Window::Ptr sfgui_window_bar = sfg::Window::Create();

	std::map<std::string, sfg::Image::Ptr> image_map;
	void init_image(const std::string & name);
	
	std::string buffer = "empty";
        bool running = false;
        void init();
        void handle_events();
        void render();
        void update();
        void clear();
};
#endif
