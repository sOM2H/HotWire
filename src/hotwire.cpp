#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>

Hotwire::Hotwire()
	/*: render_window(sf::VideoMode(800, 600), "HotWire", 5)*/
	: render_window(sf::VideoMode(0, 0), "HotWire", sf::Style::Fullscreen) {
	render_window.setKeyRepeatEnabled(false);
}


void Hotwire::init(){

    render_window.resetGLStates();


    box->Pack(boxIN, false, false);
	
	sfgui_window_bar->SetRequisition(sf::Vector2f(0, 270));
	sfgui_window_bar->SetAllocation(sf::FloatRect(0, 0, 60, 270));
	sfgui_window_bar->SetPosition(sf::Vector2f(0.f, 0.f));
	sfgui_window_bar->SetTitle("Bar");
 		
	sfgui_window_bar->SetPosition(sf::Vector2f(0, 0));


	scrolledwindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER |  sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
	scrolledwindow->SetRequisition(sf::Vector2f(60, 270));



    bool & running_ref = running;
    std::string & buffer_ref = buffer;
 
    auto image_lamp = sfg::Image::Create();

    std::string images[] = {
	"lamp", "battery", "resistor", "ampermeter", "voltmeter", "bell", "coil", "transistor", "switch", "loles"
    };

    for (const std::string & name : images) {
		init_image(name);
    }


    image_map["lamp"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "lamp"; std::cout << "buffer: lamp\n";});
    image_map["battery"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "battery"; std::cout << "buffer: battery\n";});
    image_map["resistor"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "resistor"; std::cout << "buffer: resistor\n";});
    image_map["ampermeter"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "ampermeter"; std::cout << "buffer: ampermeter\n";});
	image_map["transistor"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "transistor"; std::cout << "buffer: transistor\n";});
    image_map["voltmeter"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "voltmeter"; std::cout << "buffer: voltmeter\n";});
	image_map["switch"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "switch"; std::cout << "buffer: switch\n";});
    image_map["bell"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "bell"; std::cout << "buffer: bell\n";});
	image_map["coil"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "coil"; std::cout << "buffer: coil\n";});

    sfgui_window->GetSignal(sfg::Window::OnMouseLeftPress).Connect([&]{
		std::cout << "********************\n";
	    std::cout << "^ Click on window. ^\n";
		std::cout << "********************\n\n";
	    element_making(buffer_ref, sf::Vector2i(mouse.getPosition(render_window).x, mouse.getPosition(render_window).y), amountOfBatteries, element_id);
	});

    boxIN->Pack(image_map["lamp"]);
    boxIN->Pack(image_map["resistor"]);
    boxIN->Pack(image_map["battery"]);
    boxIN->Pack(image_map["bell"]);
	boxIN->Pack(image_map["transistor"]);
	boxIN->Pack(image_map["switch"]);
	boxIN->Pack(image_map["coil"]);
    boxIN->Pack(image_map["ampermeter"]);
    boxIN->Pack(image_map["voltmeter"]);


    canvas->SetRequisition(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H));
	fixed->Put(canvas, sf::Vector2f(0, 0));
	sfgui_window->Add(fixed);
	sfgui_window_bar->Add(scrolledwindow);

	scrolledwindow->AddWithViewport(box);
	desktop.Add( sfgui_window );
	desktop.Add( sfgui_window_bar);
	desktop.BringToFront( sfgui_window);

    running = true;
	
    sfgui_window->SetRequisition(sf::Vector2f(SFGUI_WS_W + 22, SFGUI_WS_H + 22));

	std::cout<< "WS_W: " << WS_W << "\n";
	std::cout<< "WS_H: " << WS_H << "\n\n";
	
	std::cout<< "SFGUI_WS_BAR_W: " << SFGUI_WS_BAR_W << "\n";
	std::cout<< "SFGUI_WS_BAR_H: " << SFGUI_WS_BAR_H << "\n\n";	

	std::cout<< "render_window.getSize().x: " << render_window.getSize().x << "\n\n";

	std::cout<< "sfgui_window_bar->GetAllocation().width: " << sfgui_window_bar->GetAllocation().width << "\n\n";

    sfgui_window->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window->SetPosition(sf::Vector2f(-11, -11));

	
    
	std::cout<< "Box GetAllocation().wight: " << box->GetAllocation().width << "\n";
	std::cout<< "BoxIN GetAllocation().wight: " << boxIN->GetAllocation().width << "\n\n";

}

void Hotwire::handle_events(){
    sf::Event event;
    while (render_window.pollEvent(event)){
        if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            running = false;
		}

		if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Space){		
				if(!render_bar){
					sfgui_window_bar->SetPosition(sf::Vector2f(pos_bar.x, pos_bar.y));
					desktop.BringToFront(sfgui_window_bar);
					render_bar = true;
				}else{
					pos_bar.x = sfgui_window_bar->GetAllocation().left;
					pos_bar.y = sfgui_window_bar->GetAllocation().top;
					sfgui_window_bar->SetPosition(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H));
					desktop.BringToFront(sfgui_window);		
					render_bar = false;
				}
			}
			if(event.key.code == sf::Keyboard::Tab){
					sfgui_window_bar->SetPosition(sf::Vector2f(0 ,0));
					desktop.BringToFront(sfgui_window_bar);
					render_bar = true;
			}
		}

		sfgui_window->HandleEvent( event );	
		sfgui_window_bar->HandleEvent( event );	
	}
}
void Hotwire::render(){

    //sfgui_window->Update(0.f);
    //sfgui_window_bar->Update(0.f);
	desktop.Update(0.f);
    render_window.clear();
	canvas->Bind();
	for(int i = 0; i < vector_draw_wire.size(); ++i){
		canvas->Draw(*vector_draw_wire[i]);
	}
	canvas->Display();
	canvas->Unbind();
	canvas->Unbind();
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

std::ostream & operator<<(std::ostream & os, sf::Vector2f vec) {
	os << "(" << vec.x << ", " << vec.y << ")";
}

std::ostream & operator<<(std::ostream & os, sf::FloatRect vec) {
	os << "(" << vec.left << ", " << vec.top << ", " << vec.width << "x" << vec.height << ")";
}


int Hotwire::element_making(std::string name, sf::Vector2i pos, int amountOfBatteries, int &id){
	if(elements_position_set.count( std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 )) > 0){
			return 0;
	}

	
	id++;
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
	} else if(name == "coil"){
		temp = new Coil;
	}else if(name == "transistor"){
		temp = new Transistor;
	} else if(name == "switch"){
		temp = new Switch;
	}else{
		return 0;		
	}
	

	//std::cout<< "Count element in set: "  <<elements_position_set.count( std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 )) << "\n\n";

    temp->x = ((pos.x/60))*60;
    temp->y = ((pos.y/60))*60;

	elements_position_set.insert(std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 ));

	temp->id = element_id;
    element_map[id] = temp;

	temp->setImage();
	temp->init_endings();


	int & bufferFirstElement_ref = 	bufferFirstElement;
	int & bufferSecondElement_ref = bufferSecondElement;

	int & index_F_E_B_ref = index_F_E_B;
	int & index_S_E_B_ref = index_S_E_B;
	
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		temp->vector_endings[i].ending_button->GetSignal(sfg::Widget::OnLeftClick).Connect([&, tempid = temp->id, i, this]{
					render_bar = false;
			if(bufferFirstElement_ref == -1){
				bufferFirstElement_ref = tempid;
				index_F_E_B_ref = i;
	
			}else{
				bufferSecondElement_ref = tempid;
				index_S_E_B_ref = i;
			}
			if(bufferFirstElement_ref != -1 && bufferSecondElement_ref != -1){
				wire_making(bufferFirstElement_ref, bufferSecondElement_ref, index_F_E_B_ref, index_S_E_B_ref);
			}
		});

	}

	/*
    temp->image->GetSignal(sfg::Image::OnMouseRightPress).Connect([&, tempid = temp->id, this]{
			render_bar = false;
			if(bufferFirstElement_ref == -1){
				bufferFirstElement_ref = tempid;
			}else{
				bufferSecondElement_ref = tempid;
			}
			if(bufferFirstElement_ref != -1 && bufferSecondElement_ref != -1){
				wire_making(bufferFirstElement_ref, bufferSecondElement_ref);
			}
	});
*/
	
	

	std::cout<< "//////// INFO ////////\n";	
	std::cout<< "Creating new element: " << name <<".\n" << "	id: "<< temp->id << "\n" << "	Position:\n" << "		x: " << temp->x << "\n" << "		y: " << temp->y << "\n";
	std::cout<< "////// End INFO //////\n\n";
	
	buffer = "empty";
	std::cout<< "buffer: "<< buffer << "\n\n";
	sfg::Widget::Ptr canvas = fixed->GetChildren().back();
	fixed->Remove(canvas);
	fixed->Put( temp->image, sf::Vector2f(temp->x, temp->y));
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		if(temp->vector_endings[i].lay == "left")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "right")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 60 - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "down")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 30 - 3 - 5, temp->y + 60 - 3 - 5));
	}	
	fixed->Put( canvas, sf::Vector2f(0, 0));
	//std::cout<< fixed->GetAllocation() << "\n\n";
}

int Hotwire::wire_making(int b1, int b2, int I_F_E_B, int I_S_E_B){

	std::cout<<"loles\n\n";

	Wire * temp_wire = new Wire;

	wire_id++;

	element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
	element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

	temp_wire->wire.append(sf::Vertex(
			sf::Vector2f(
				element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,
				element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
		sf::Color::Red));


	temp_wire->wire.append(sf::Vertex(
				sf::Vector2f(
					element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,
					element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
			sf::Color::Magenta));
	

		vector_wires.push_back(std::make_pair(b1, b2));
		vector_wires.push_back(std::make_pair(b2, b1));

		temp_wire->wire.setPrimitiveType ( sf::LinesStrip ) ;
		vector_draw_wire.push_back(&temp_wire->wire);

		std::cout<< "New wire: "<< b1 << ", " << b2 << "\n\n";
		std::cout<< "Amount wire: " << wire_id <<"\n\n";


	bufferFirstElement = -1;
	bufferSecondElement = -1;
}


sf::Vector2i Hotwire::couting_amountImage(int ws_w, int ws_h, int img_s){
	int w = ws_w/img_s;
	int h = ws_h/img_s;
	return sf::Vector2i(w, h);
}
