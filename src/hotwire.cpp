#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>
#include <algorithm>

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
	"lamp", "battery", "resistor", "ampermeter", "voltmeter", "bell", "coil", "transistor", "switch", "loles", "reostat"
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
	image_map["reostat"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "reostat"; std::cout << "buffer: reostat\n";});
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
	boxIN->Pack(image_map["reostat"]);
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
					//sfgui_window_bar->SetPosition(sf::Vector2f(pos_bar.x, pos_bar.y));
					pos_bar.x = sfgui_window_bar->GetAllocation().left;
					pos_bar.y = sfgui_window_bar->GetAllocation().top;
					desktop.BringToFront(sfgui_window_bar);
				
			}
			if(event.key.code == sf::Keyboard::Tab){
					sfgui_window_bar->SetPosition(sf::Vector2f(0 ,0));
					desktop.BringToFront(sfgui_window_bar);
			}
		}

		//sfgui_window->HandleEvent( event );	
		//sfgui_window_bar->HandleEvent( event );
		desktop.HandleEvent(event);
	}
}
void Hotwire::render(){

    //sfgui_window->Update(0.f);
    //sfgui_window_bar->Update(0.f);
	desktop.Update(0.f);
    render_window.clear();
	canvas->Bind();
	canvas->Clear(sf::Color(70, 70, 70));
	for(auto p : map_draw_wire) {
		canvas->Draw(*p.second);
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

		temp->resistance_label->SetText("Resistance");
		temp->resistance_label->SetRequisition(sf::Vector2f(100, 20));

		temp->resistance_entry->SetRequisition(sf::Vector2f(200, 20));	

		temp->resistance_box->Pack(temp->resistance_label);
		temp->resistance_box->Pack(temp->resistance_entry);

		temp->option_window_box->Pack(temp->resistance_box, false, false);

		temp->option_window->SetTitle("Option window: Lamp");

		temp->option_window_ok->SetLabel("Apply");
	
		temp->option_window_ok->SetRequisition(sf::Vector2f(300, 30));

		auto & resistance_entry_ref = temp->resistance_entry;

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
				resistance_entry_ref->SetText(regex_string(resistance_entry_ref->GetText()));	
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);

		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		
		temp->option_window->Add(temp->option_window_box);

	}else if(name == "battery"){

		amountOfBatteries++;
		temp = new Battery;

		temp->voltage_label->SetText("Voltage");

		temp->voltage_label->SetRequisition(sf::Vector2f(100, 20));

		temp->voltage_entry->SetRequisition(sf::Vector2f(200, 20));	

		temp->voltage_box->Pack(temp->voltage_label);
		temp->voltage_box->Pack(temp->voltage_entry);

		temp->option_window_box->Pack(temp->voltage_box, false, false);
		
		temp->option_window->SetTitle("Option window: Battery");

		temp->option_window_ok->SetLabel("Apply");

		temp->option_window_ok->SetRequisition(sf::Vector2f(300, 30));

		auto & voltage_entry_ref = temp->voltage_entry;

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
				voltage_entry_ref->SetText(regex_string(voltage_entry_ref->GetText()));	
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);


	} else if(name == "resistor"){
		temp = new Resistor;

		temp->resistance_label->SetText("Resistance");

		temp->resistance_label->SetRequisition(sf::Vector2f(100, 20));

		temp->resistance_entry->SetRequisition(sf::Vector2f(200, 20));	

		temp->resistance_box->Pack(temp->resistance_label);
		temp->resistance_box->Pack(temp->resistance_entry);

		temp->option_window_box->Pack(temp->resistance_box, false, false);

		temp->option_window->SetTitle("Option window: Resistor");

		temp->option_window_ok->SetLabel("Apply");

		temp->option_window_ok->SetRequisition(sf::Vector2f(300, 30));

		auto & resistance_entry_ref = temp->resistance_entry;

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
				resistance_entry_ref->SetText(regex_string(resistance_entry_ref->GetText()));	
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);



	} else if(name == "ampermeter"){

		temp = new Ampermeter;
		temp->option_window->SetTitle("Option window: Ampeter");

		temp->indicator_label->SetText("Indicator: ");

		temp->indicator_box->Pack(temp->indicator_label);

		temp->option_window_box->Pack(temp->indicator_box, false, false);

		//std::vector<sf::CircleShape *> vector_draw_circleshape;
		temp->option_window_ok->SetLabel("Okay");

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick).Connect([&]{
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
				});

		temp->option_window_box->SetSpacing(5.f);

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);


	} else if(name == "voltmeter"){

		temp = new Voltmeter;
		temp->option_window->SetTitle("Option window: Voltmeter");

		temp->indicator_label->SetText("Indicator: ");
		//std::vector<sf::CircleShape *> vector_draw_circleshape;

		temp->indicator_box->Pack(temp->indicator_label);

		temp->option_window_box->Pack(temp->indicator_box, false, false);

		temp->option_window_ok->SetLabel("Okay");

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick).Connect([&]{
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
				});

		temp->option_window_box->SetSpacing(5.f);

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);


	} else if(name == "bell"){

		temp = new Bell;
		temp->resistance_label->SetText("Resistance");

		temp->resistance_label->SetRequisition(sf::Vector2f(100, 20));

		temp->resistance_entry->SetRequisition(sf::Vector2f(200, 20));	

		temp->resistance_box->Pack(temp->resistance_label);
		temp->resistance_box->Pack(temp->resistance_entry);

		temp->option_window_box->Pack(temp->resistance_box, false, false);

		temp->option_window->SetTitle("Option window: Bell");

		temp->option_window_ok->SetLabel("Apply");

		temp->option_window_ok->SetRequisition(sf::Vector2f(300, 30));

		auto & resistance_entry_ref = temp->resistance_entry;

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
				resistance_entry_ref->SetText(regex_string(resistance_entry_ref->GetText()));
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);


	} else if(name == "coil"){

		temp = new Coil;
		temp->resistance_label->SetText("Resistance");

		temp->resistance_label->SetRequisition(sf::Vector2f(100, 20));

		temp->resistance_entry->SetRequisition(sf::Vector2f(200, 20));	

		temp->resistance_box->Pack(temp->resistance_label);
		temp->resistance_box->Pack(temp->resistance_entry);

		temp->option_window_box->Pack(temp->resistance_box, false, false);

		temp->option_window->SetTitle("Option window: Coil");

		temp->option_window_ok->SetLabel("Apply");

		temp->option_window_ok->SetRequisition(sf::Vector2f(300, 30));

		auto & resistance_entry_ref = temp->resistance_entry;

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
				resistance_entry_ref->SetText(regex_string(resistance_entry_ref->GetText()));	
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);

	}else if(name == "transistor"){

		temp = new Transistor;
		temp->option_window->SetTitle("Option window: Transistor");

	} else if(name == "switch"){

		temp = new Switch;
		temp->option_window->SetTitle("Option window: Switch");

	
		temp->option_window->Add(temp->option_window_box);

	} else if(name == "reostat"){
		temp = new Reostat;
		temp->option_window->SetTitle("Option window: Reostat");

	}else{
		return 0;		
	}

	
		temp->delete_button->SetLabel("Delete");

		temp->delete_button->SetRequisition(sf::Vector2f(300, 30));

		temp->delete_button->GetSignal(sfg::Widget::OnLeftClick ).Connect([&, tempid = id]{
				element_delete(tempid);
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->delete_box->Pack(temp->delete_button);
		temp->option_window_box->Pack(temp->delete_box, false, false);

	//std::cout<< "Count element in set: "  <<elements_position_set.count( std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 )) << "\n\n";

    temp->x = ((pos.x/60))*60;
    temp->y = ((pos.y/60))*60;

	elements_position_set.insert(std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 ));

	temp->id = element_id;
    element_map[id] = temp;

	temp->setImage();
	temp->init_endings();

	temp->option_window->SetRequisition(sf::Vector2f(300, 200));
	temp->option_window->SetPosition(sf::Vector2f(temp->x + 30, temp->y + 30));


	desktop.Add(element_map[id]->option_window);
	temp->image->GetSignal(sfg::Image::OnMouseRightPress).Connect([&, id]{
				desktop.BringToFront(element_map[id]->option_window);
				element_map[id]->option_window->SetPosition(sf::Vector2f(element_map[id]->x + 30, element_map[id]->y + 30));

		});

//	desktop.Add(temp->option_window);
//	desktop.BringToFront(temp->option_window);

	int & bufferFirstElement_ref = 	bufferFirstElement;
	int & bufferSecondElement_ref = bufferSecondElement;

	int & index_F_E_B_ref = index_F_E_B;
	int & index_S_E_B_ref = index_S_E_B;
	
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		temp->vector_endings[i].ending_button->GetSignal(sfg::Widget::OnLeftClick).Connect([&, tempid = temp->id, i, this]{
			if(bufferFirstElement_ref == -1){
				bufferFirstElement_ref = tempid;
				index_F_E_B_ref = i;
	
			}else if(tempid != bufferFirstElement_ref){
				bufferSecondElement_ref = tempid;
				index_S_E_B_ref = i;
			}
			if(bufferFirstElement_ref != -1 && bufferSecondElement_ref != -1){
				wire_making(bufferFirstElement_ref, bufferSecondElement_ref, index_F_E_B_ref, index_S_E_B_ref);
			}
		});

	}


	std::cout<< "//////// INFO ////////\n";	
	std::cout<< "Creating new element: " << name <<".\n" << "	id: "<< temp->id << "\n" << "	Position:\n" << "		x: " << temp->x << "\n" << "		y: " << temp->y << "\n";
	std::cout<< "////// End INFO //////\n\n";
	
	buffer = "empty";
	std::cout<< "buffer: "<< buffer << "\n\n";
	sfg::Widget::Ptr canvas = fixed->GetChildren().back();
	//fixed->Remove(canvas);
	fixed->Put( canvas, sf::Vector2f(0, 0));
	fixed->Put( temp->image, sf::Vector2f(temp->x, temp->y));
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		if(temp->vector_endings[i].lay == "left")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "right")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 60 - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "down")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 30 - 3 - 5, temp->y + 60 - 3 - 5));
	}	
	desktop.BringToFront(sfgui_window_bar);
}

int Hotwire::wire_making(int b1, int b2, int I_F_E_B, int I_S_E_B){

	if(element_map[b1]->vector_endings[I_F_E_B].other_element_id == -1 && element_map[b2]->vector_endings[I_S_E_B].other_element_id == -1){

		Wire * temp_wire = new Wire;

		wire_id++;

		wires_map[wire_id] = temp_wire;

		if(std::abs((element_map[b1]->x - element_map[b2]->x)) >= std::abs((element_map[b1]->y - element_map[b2]->y))){

			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Red));
			
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5
						- (element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5 - 
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5)/2,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Red));

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(	
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5
						- (element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5 - 
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5)/2,

						element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Red));


			temp_wire->wire.append(sf::Vertex(
						sf::Vector2f(
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
					sf::Color::Red));
		
		}else{
			
			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

		std::string other_element_lay = "none";
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Red));
			
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 - 
						(element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 -
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5 
							)/2),
				sf::Color::Red));

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(	
						element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 - 
						(element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 -
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5 
							)/2),
				sf::Color::Red));


			temp_wire->wire.append(sf::Vertex(
						sf::Vector2f(
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
					sf::Color::Magenta));
		

		}
		
			vector_wires.push_back(std::make_pair(b1, b2));
			vector_wires.push_back(std::make_pair(b2, b1));

			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

			element_map[b1]->vector_endings[I_F_E_B].wire_id_ = wire_id;
			element_map[b2]->vector_endings[I_S_E_B].wire_id_ = wire_id;

			temp_wire->first_other_id = b1;
			temp_wire->second_other_id = b2;


			temp_wire->wire.setPrimitiveType ( sf::LinesStrip ) ;
			map_draw_wire[wire_id] = &temp_wire->wire;

			std::cout<< "New wire: "<< b1 << ", " << b2 << "\n\n";
			std::cout<< "Amount wire: " << wire_id <<"\n\n";


			bufferFirstElement = -1;
			bufferSecondElement = -1;
	}
}


sf::Vector2i Hotwire::couting_amountImage(int ws_w, int ws_h, int img_s){
	int w = ws_w/img_s;
	int h = ws_h/img_s;
	return sf::Vector2i(w, h);
}

std::string Hotwire::regex_string(std::string string){
	bool dot = false;
	std::string new_string;
	for(int i = 0; i < string.length(); ++i){
		if(string[i] >= '0' && string[i] <= '9'){
			new_string += string[i];
		}else{
			if(((string[i] == '.') && (dot == false))){
				if(i == 0){
					new_string += '0';
				}
				new_string += '.';
				dot = true;
			}
		}
	}
	return new_string;
}

int Hotwire::element_delete(int id){
	int temp_id = -1;
	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		temp_id = element_map[id]->vector_endings[i].other_element_id;
		if(temp_id != -1){
			std::cout<< "temp_id" <<temp_id << "\n";
			for(int j = 0; j < element_map[temp_id]->vector_endings.size(); ++j){
				if(element_map[temp_id]->vector_endings[j].other_element_id == id){
					element_map[temp_id]->vector_endings[j].other_element_id = -1;
					element_map[id]->vector_endings[i].other_element_id	= -1;
	//				vector_wires.pop_back(std::make_pair(element_map[id]->vector_endings[i].other_element_id, element_map[temp_id]->vector_endings[j].other_element_id));	
					map_draw_wire.erase(element_map[id]->vector_endings[i].wire_id_);
					std::cout<< "element_map[id]->vector_endings[i].wire_id_ = " << element_map[id]->vector_endings[i].wire_id_ << "\n";
					std::cout<<"map_draw_wire.size(): "<< map_draw_wire.size() << "\n";
				}
			}
			temp_id = -1;
		}

	}	

	elements_position_set.erase(std::make_pair(element_map[id]->x, element_map[id]->y));

	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		fixed->Remove(element_map[id]->vector_endings[i].ending_button);
	}

	fixed->Remove(element_map[id]->image);
	element_map.erase(id);
}
