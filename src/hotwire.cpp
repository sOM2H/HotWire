#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>

Hotwire::Hotwire()
    : render_window(sf::VideoMode(0, 0), "HotWire", sf::Style::Fullscreen) {
}


void Hotwire::init(){

    render_window.resetGLStates();
	
    auto boxIN = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
    auto box = sfg::Box::Create();
    box->Pack(boxIN, false, false);

    box->SetSpacing( 5.f );

    sfgui_window->SetRequisition(sf::Vector2f(WS_W, WS_H));
    sfgui_window->SetStyle(sfg::Window::Style::BACKGROUND);


    sfgui_window_bar->SetRequisition(sf::Vector2f(WS_BAR_W, WS_BAR_H));
    sfgui_window_bar->SetStyle(sfg::Window::Style::BACKGROUND);

    bool & running_ref = running;
    std::string & buffer_ref = buffer;

    auto image_lamp = sfg::Image::Create();



	std::string images[] = {
		"lamp", "battery", "resistor"
	};
	for (const std::string & name : images) {
	    init_image(name);
	}
    

    image_map["lamp"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "lamp"; std::cout << "buffer: lamp\n";});
    image_map["battery"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "battery"; std::cout << "buffer: battery\n";});
    image_map["resistor"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "resistor"; std::cout << "buffer: resistor\n";});

    boxIN->Pack(image_map["lamp"]);
    boxIN->Pack(image_map["resistor"]);
    boxIN->Pack(image_map["battery"]);

    sfgui_window_bar->Add( box ); 
    running = true;
}

void Hotwire::handle_events(){
    sf::Event event;
    while (render_window.pollEvent(event)){
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            running = false;
	}
    }
    sfgui_window->HandleEvent( event );	
    sfgui_window_bar->HandleEvent( event );	
}

void Hotwire::render(){
    sfgui_window->Update(0.f);
    sfgui_window_bar->Update(0.f);
    render_window.clear();
    sfgui.Display( render_window );
    render_window.display();
}

void Hotwire::update(){

}

void Hotwire::clear(){
    render_window.close();
}

void Hotwire::init_image(const std::string & name){
    texture_manager->load("src/textures/" + name + ".png", name);
    std::cout<< "src/textures/" + name + ".png" << std::endl;
    image_map[name] = sfg::Image::Create();
    image_map[name]->SetImage( texture_manager->image_map[name]);
}
