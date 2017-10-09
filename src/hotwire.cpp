#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>

Hotwire::Hotwire()
	/*: render_window(sf::VideoMode(800, 600), "HotWire", sf::Style::Titlebar | sf::Style::Close)*/
	: render_window(sf::VideoMode(0, 0), "HotWire", sf::Style::Fullscreen) {
}


void Hotwire::init(){

    render_window.resetGLStates();
	
    auto boxIN = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
    auto box = sfg::Box::Create();

    box->Pack(boxIN, false, false);
    box->SetSpacing( 5.f );

	sfgui_window_bar->SetRequisition(sf::Vector2f(0, SFGUI_WS_BAR_H));
	sfgui_window_bar->SetAllocation(sf::FloatRect(0, 0, 60, SFGUI_WS_BAR_H));
    sfgui_window_bar->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window_bar->SetPosition(sf::Vector2f(0.f, 0.f));


    bool & running_ref = running;
    std::string & buffer_ref = buffer;
 

    auto image_lamp = sfg::Image::Create();
 

    std::string images[] = {
	"lamp", "battery", "resistor", "ampermeter", "voltmeter", "bell"
    };

    for (const std::string & name : images) {
	init_image(name);
    }


    image_map["lamp"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "lamp"; std::cout << "buffer: lamp\n";});
    image_map["battery"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "battery"; std::cout << "buffer: battery\n";});
    image_map["resistor"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "resistor"; std::cout << "buffer: resistor\n";});
    image_map["ampermeter"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "ampermeter"; std::cout << "buffer: ampermeter\n";});
    image_map["voltmeter"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "voltmeter"; std::cout << "buffer: voltmeter\n";});
    image_map["bell"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "bell"; std::cout << "buffer: bell\n";});



    sfgui_window->GetSignal(sfg::Window::OnMouseLeftPress).Connect([&]{
		std::cout << "********************\n";
	    std::cout << "^ Click on window. ^\n";
		std::cout << "********************\n\n";
	    element_making(buffer_ref, sf::Vector2f(mouse.getPosition(render_window).x - SFGUI_WS_BAR_W - 40, mouse.getPosition(render_window).y - 40), amountOfBatteries, counter);
	});

    boxIN->Pack(image_map["lamp"]);
    boxIN->Pack(image_map["resistor"]);
    boxIN->Pack(image_map["battery"]);
    boxIN->Pack(image_map["bell"]);
    boxIN->Pack(image_map["ampermeter"]);
    boxIN->Pack(image_map["voltmeter"]);

	sfgui_window->Add( fixed );
    sfgui_window_bar->Add( box ); 

    running = true;
	
    sfgui_window->SetRequisition(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H));

	std::cout<< "WS_W: " << WS_W << "\n";
	std::cout<< "WS_H: " << WS_H << "\n\n";
	
	std::cout<< "SFGUI_WS_BAR_W: " << SFGUI_WS_BAR_W << "\n";
	std::cout<< "SFGUI_WS_BAR_H: " << SFGUI_WS_BAR_H << "\n\n";	

	std::cout<< "render_window.getSize().x: " << render_window.getSize().x << "\n\n";

	std::cout<< "sfgui_window_bar->GetAllocation().width: " << sfgui_window_bar->GetAllocation().width << "\n\n";

    sfgui_window->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window->SetPosition(sf::Vector2f(SFGUI_WS_BAR_W, 0));

	
    
	std::cout<< "Box GetAllocation().wight: " << box->GetAllocation().width << "\n";
	std::cout<< "BoxIN GetAllocation().wight: " << boxIN->GetAllocation().width << "\n\n";
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
    image_map[name]->SetImage( texture_manager->sfml_image_map[name]);
	std::cout<< "Image getRequisition.x: " << image_map[name]->GetRequisition().x << "\n";
	std::cout<< "Image getRequisition.y: " << image_map[name]->GetRequisition().y << "\n\n";
}



int Hotwire::element_making(std::string name, sf::Vector2f pos, int amountOfBatteries, int counter){
	Element * temp;
	if(name == "lamp"){		
		temp = new Lamp;
	}else if(name == "battery"){
		amountOfBatteries++;
		temp = new Battery;
	} else if(name == "resistor"){
		temp = new Resistor;
	} else if(name == "ampermeter"){
		temp = new Ampermeter;
	} else if(name == "voltmeter"){
		temp = new Voltmeter;
	} else if(name == "bell"){
		temp = new Bell;
	} else{
		return 0;		
	}
	

    temp->x = pos.x;
    temp->y = pos.y;
    element_map[counter] = temp;

	temp->setImage();

	counter++;
	std::cout<< "//////// INFO ////////\n";	
	std::cout<< "Creating new element: " << name <<".\n" << "	Position:\n" << "		x: " << pos.x << "\n" << "		y: " << pos.y << "\n";
	std::cout<< "////// End INFO //////\n\n"; 
	fixed->Put( temp->image, pos);
}
