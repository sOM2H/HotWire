#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <hotwire.h>

Hotwire::Hotwire()
	/*: render_window(sf::VideoMode(800, 600), "HotWire", 5)*/
	: render_window(sf::VideoMode(0, 0), "HotWire", sf::Style::Fullscreen) {
	render_window.setKeyRepeatEnabled(false);
}


void Hotwire::init(){

    render_window.resetGLStates();
    state = "start";
///////

	std::string images[] = {
	"lamp", "battery", "resistor",
   	"ampermeter", "voltmeter", "bell",
   	"coil", "transistor", "switch",
   	"loles", "reostat", "dot",
   	"start", "exit", "tests",
   	"easy", "medium", "hard",
	"about", "hotwire"
    };

    for (const std::string & name : images) {
		init_image(name);
    }
	
	backToMenu->SetImage(image_map["exit"]);
	backToMenu->SetRequisition();
	fixed->Put(backToMenu, sf::Vector2f(SFGUI_WS_W - backToMenu->GetAllocation().width, SFGUI_WS_H - backToMenu->GetAllocation().height));
	std::cout<<SFGUI_WS_W - backToMenu->GetAllocation().width << " " << SFGUI_WS_H - backToMenu->GetAllocation().height << "\n";

	backToMenu->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			desktop.BringToFront(sfgui_window_menu);	
			state = "menu";
	});


    sfgui_window_menu->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window_tests->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window_about->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_window_start->SetStyle(sfg::Window::Style::BACKGROUND);

	sfgui_window_about->SetRequisition(sf::Vector2f(SFGUI_WS_W + 22, SFGUI_WS_H + 22));
	sfgui_window_about->SetPosition(sf::Vector2f(-11, -11));

	sfgui_window_menu->SetRequisition(sf::Vector2f(SFGUI_WS_W + 22, SFGUI_WS_H + 22));
	sfgui_window_menu->SetPosition(sf::Vector2f(-11, -11));

	sfgui_window_tests->SetRequisition(sf::Vector2f(SFGUI_WS_W + 22, SFGUI_WS_H + 22));
	sfgui_window_tests->SetPosition(sf::Vector2f(-11, -11));

	sfgui_window_start->SetRequisition(sf::Vector2f(SFGUI_WS_W + 22, SFGUI_WS_H + 22));
	sfgui_window_start->SetPosition(sf::Vector2f(-11, -11));

	sf::Image image;
	image.loadFromFile("src/textures/about_image.jpg");
	About_image->SetImage(image);

	About_image->SetPosition(sf::Vector2f());


	sf::Texture texture_back1;
	texture_back1.loadFromFile("src/textures/start_back.png");
	sf::RectangleShape rect_text1;
	rect_text1.setSize(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H) );
	rect_text1.setTexture(&texture_back1, true);

	sf::Image mg;
	mg.loadFromFile("src/textures/hotwire.png");
	hotwire_start->SetImage(mg);

	hotwire_start->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&]{
			state = "menu";
			desktop.BringToFront(sfgui_window_menu);
	});

	sfgui_window_start->Add(fixed_start);
                                                                                                                               	


	canvas_background_start->SetRequisition(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H));
	canvas_background_start->Bind();
	canvas_background_start->Clear();
	canvas_background_start->Draw(rect_text1);
	canvas_background_start->Unbind();

	fixed_start->Put(canvas_background_start, sf::Vector2f());	
	fixed_start->Put(hotwire_start, sf::Vector2f(SFGUI_WS_W/2 - hotwire_start->GetAllocation().width/2 + 30, SFGUI_WS_H/2 - hotwire_start->GetAllocation().height/2 + 30));	
	
	sf::Texture texture_back;
	texture_back.loadFromFile("src/textures/background.png");
	sf::RectangleShape rect_text;
	rect_text.setSize(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H) );
	rect_text.setTexture(&texture_back, true);


	sf::Texture hotwire_back;
	hotwire_back.loadFromFile("src/textures/hotwire.png");
	sf::RectangleShape hot_text;
	hot_text.setSize(sf::Vector2f(400, 100) );
	hot_text.setTexture(&hotwire_back, true);
	hot_text.setPosition(sf::Vector2f(SFGUI_WS_W/6, SFGUI_WS_H/5));


	canvas_background->SetRequisition(sf::Vector2f(SFGUI_WS_W, SFGUI_WS_H));
	canvas_background->Bind();
	canvas_background->Clear();
	canvas_background->Draw(rect_text);
	canvas_background->Draw(hot_text);
	canvas_background->Unbind();
	
	fixed_menu->Put(canvas_background, sf::Vector2f());

	test3->SetImage(image_map["hard"]);
	test3->SetRequisition(sf::Vector2f());
	fixed_tests->Put(test3, sf::Vector2f(100, 100));

	test3->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
		#ifdef __windows
		system("start https://docs.google.com/forms/d/e/1FAIpQLSdHLbhNACd_BLx5kzW5miylS2i2VIrAbTLFx7IMT2ykSXTPmQ/viewform");
		#endif
		#ifdef __linux
		system("xdg-open https://docs.google.com/forms/d/e/1FAIpQLSdHLbhNACd_BLx5kzW5miylS2i2VIrAbTLFx7IMT2ykSXTPmQ/viewform");
		#endif
	});

	

	test2->SetImage(image_map["medium"]);
	test2->SetRequisition(sf::Vector2f());
	fixed_tests->Put(test2, sf::Vector2f(100, 200));


	test2->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			
		#ifdef __windows
		system("start https://docs.google.com/forms/d/e/1FAIpQLSdckzc8XYnGRex6ZrLZpIcWOeV0n5LVs9aRGyv6GGXuF_o8bg/viewform");
		#endif
		#ifdef __linux
		system("xdg-open https://docs.google.com/forms/d/e/1FAIpQLSdckzc8XYnGRex6ZrLZpIcWOeV0n5LVs9aRGyv6GGXuF_o8bg/viewform");
		#endif
	});

	test1->SetImage(image_map["easy"]);	
	test1->SetRequisition(sf::Vector2f());
	fixed_tests->Put(test1, sf::Vector2f(100, 300));

	test1->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			
		#if defined(__windows)
		system("start https://docs.google.com/forms/d/1VO2b0hD3EgKVc0vJ7L0sn9SWkGqAGFIBHREkaVivhiY/edit?fbzx=-1838048315125321500");
		#elif defined(__linux)
		system("xdg-open https://docs.google.com/forms/d/1VO2b0hD3EgKVc0vJ7L0sn9SWkGqAGFIBHREkaVivhiY/edit?fbzx=-1838048315125321500");
		#endif
	});

	Start->SetImage(image_map["start"]);
	Start->SetRequisition(sf::Vector2f());
	fixed_menu->Put(Start, sf::Vector2f(SFGUI_WS_W/2 - 75 + SFGUI_WS_W/6, SFGUI_WS_H/6 - 25));

	Start->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			desktop.BringToFront(sfgui_window);	
			desktop.BringToFront(sfgui_window_bar);
			state = "programm";
	});

	Tests->SetImage(image_map["tests"]);
	Tests->SetRequisition(sf::Vector2f());
	fixed_menu->Put(Tests, sf::Vector2f(SFGUI_WS_W/2 - 75 + SFGUI_WS_W/6, SFGUI_WS_H/6 - 25 + SFGUI_WS_H/6));

	Tests->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			desktop.BringToFront(sfgui_window_tests);
			state = "tests";
			});

	About->SetImage(image_map["about"]);
	About->SetRequisition(sf::Vector2f());
	fixed_menu->Put(About, sf::Vector2f(SFGUI_WS_W/2 - 75 + SFGUI_WS_W/6, SFGUI_WS_H/6 - 25 + SFGUI_WS_H/6*2));

	About->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			desktop.BringToFront(sfgui_window_about);
			state = "about";
	});

	Exit->SetImage(image_map["exit"]);
	Exit->SetRequisition(sf::Vector2f());
	fixed_menu->Put(Exit, sf::Vector2f(SFGUI_WS_W/2 - 75 + SFGUI_WS_W/6, SFGUI_WS_H/6 - 25 + SFGUI_WS_H/6*3));

	Exit->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
			running = false;
	});


	sfgui_window_tests->Add(fixed_tests);
	sfgui_window_about->Add(About_image);
	sfgui_window_menu->Add(fixed_menu);
	desktop.Add(sfgui_window_start);
	desktop.Add(sfgui_window_about);
	desktop.Add(sfgui_window_tests);
	desktop.Add(sfgui_window_menu);

/////////
    box->Pack(boxIN, false, false);
	sfgui_window_bar->SetRequisition(sf::Vector2f(0, 300));
	sfgui_window_bar->SetAllocation(sf::FloatRect(0, 0, 60, 300));
	sfgui_window_bar->SetPosition(sf::Vector2f(0.f, 0.f));
	sfgui_window_bar->SetTitle("Bar");
 		
	sfgui_window_bar->SetPosition(sf::Vector2f(0, 0));
		


	clear_button->SetLabel("Clear Map");

	clear_button->SetRequisition(sf::Vector2f(60, 20));

	clear_button->GetSignal(sfg::Widget::OnLeftClick ).Connect([&]{
		for (auto & p : element_map) {
			element_delete(p.first);
		}	

		desktop.BringToFront(sfgui_window);	
		desktop.BringToFront(sfgui_window_bar);
		element_id = 0;
	});

	

	scrolledwindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER |  sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
	scrolledwindow->SetRequisition(sf::Vector2f(60, 300));



    bool & running_ref = running;
    std::string & buffer_ref = buffer;
 
    auto image_lamp = sfg::Image::Create();

    image_map["dot"]->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&buffer_ref]{buffer_ref = "dot"; std::cout << "buffer: dot\n";});
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
	    element_making(buffer_ref, sf::Vector2i(mouse.getPosition(render_window).x, mouse.getPosition(render_window).y));
		desktop.BringToFront(sfgui_window_bar);
	});

    sfgui_window->GetSignal(sfg::Window::OnMouseRightPress).Connect([&]{
		if(!moving){
			desktop.BringToFront(sfgui_window_bar);
		}else{
			move(moving);
		}
	});


	boxIN->Pack(clear_button);
	boxIN->Pack(image_map["dot"]);
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
	desktop.BringToFront(sfgui_window_bar);
	desktop.BringToFront( sfgui_window_start);

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
			if(state == "start"){
				running = false;
			}else if(state == "menu"){
				desktop.BringToFront(sfgui_window_start);
            	state = "start";
			}else if(state == "tests"){
				desktop.BringToFront(sfgui_window_menu);
				state = "menu";
			}else if(state == "programm"){	
				desktop.BringToFront(sfgui_window_menu);
				state = "menu";
			}else if(state == "about"){
				desktop.BringToFront(sfgui_window_menu);
				state = "menu";
			}
		}

		if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Space){		
					if(state == "programm"){
						pos_bar.x = sfgui_window_bar->GetAllocation().left;
						pos_bar.y = sfgui_window_bar->GetAllocation().top;
						desktop.BringToFront(sfgui_window_bar);
					}
				
			}
			if(event.key.code == sf::Keyboard::Tab){
					if(state == "programm"){
						sfgui_window_bar->SetPosition(sf::Vector2f(0 ,0));
						desktop.BringToFront(sfgui_window_bar);
					}
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
    sfgui.Display( render_window );
    render_window.display();
}

void Hotwire::update(){
	vertex_amount = 0;
	for (auto & p : wires_map) {
		for(int j = 0; j < 4; ++j){
					wires_map[ p.first ]->wire[j].color = sf::Color::Yellow;
		}
	}
	for (auto & p : element_map) {
		int temp_i  = 0;
		element_map[p.first]->throughput = false;
		if(p.second->getType() == "knot"){
			vertex_amount++;
			for(int i = 0; i < 4; ++i){
				if(!p.second->vector_endings[i].visited){
					temp_i++;
				}
			}
			if(temp_i > 0){
				search_circuit(p.first);
			}
		}
	}
	for(auto p : element_map) {
		for(int i = 0; i  < p.second->vector_endings.size(); ++i){
			p.second->vector_endings[i].visited = false;
		}
	}
	search_contour();
	vector_edge.clear();
	edge_id = 0;
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


int Hotwire::element_making(std::string name, sf::Vector2i pos){
	if(elements_position_set.count( std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 )) > 0){
			return 0;
	}

	
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
		

	}else if(name == "battery"){

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

		temp->option_window_ok->GetSignal(sfg::Widget::OnLeftClick ).Connect([&, tempid = element_id]{
				voltage_entry_ref->SetText(regex_string(voltage_entry_ref->GetText()));
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);


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


		temp->option_window_ok_box->Pack(temp->option_window_ok);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);


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

		temp->option_window_ok_box->Pack(temp->option_window_ok, false, false);
		temp->option_window_box->Pack(temp->option_window_ok_box, false, false);
		temp->option_window->Add(temp->option_window_box);

	}else if(name == "transistor"){

		temp = new Transistor;
		temp->option_window->SetTitle("Option window: Transistor");

	} else if(name == "switch"){

		temp = new Switch;
		temp->option_window->SetTitle("Option window: Switch");	
		temp->option_window->Add(temp->option_window_box);

	} else if(name == "dot"){

		temp = new Knot;
		temp->option_window->SetTitle("Option window: Knot");	
		temp->option_window->Add(temp->option_window_box);

	} else if(name == "reostat"){
		temp = new Reostat;
		temp->option_window->SetTitle("Option window: Reostat");

	}else{
		return 0;		
	}

		element_id++;

		temp->delete_button->SetLabel("Delete");

		temp->delete_button->SetRequisition(sf::Vector2f(300, 30));

		temp->delete_button->GetSignal(sfg::Widget::OnLeftClick ).Connect([&, tempid = element_id]{
				element_delete(tempid);
				desktop.BringToFront(sfgui_window);
				desktop.BringToFront(sfgui_window_bar);
		});

		temp->delete_box->Pack(temp->delete_button);
		temp->option_window_box->Pack(temp->delete_box, false, false);
		
		temp->option_window->Add(temp->option_window_box);

	//std::cout<< "Count element in set: "  <<elements_position_set.count( std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 )) << "\n\n";

    temp->x = ((pos.x/60))*60;
    temp->y = ((pos.y/60))*60;

	temp->option_window_box->SetSpacing(5.f);

	elements_position_set.insert(std::make_pair( ((pos.x/60))*60, ((pos.y/60))*60 ));

	temp->id = element_id;
    element_map[temp->id] = temp;

	temp->setImage();
	temp->init_endings();

	temp->option_window->SetRequisition(sf::Vector2f(300, 200));
	temp->option_window->SetPosition(sf::Vector2f(temp->x + 30, temp->y + 30));


	desktop.Add(element_map[element_id]->option_window);
	temp->image->GetSignal(sfg::Image::OnMouseRightPress).Connect([&, element_id_ref = element_id]{
				desktop.BringToFront(element_map[element_id_ref]->option_window);
				element_map[element_id_ref]->option_window->SetPosition(sf::Vector2f(element_map[element_id_ref]->x + 30, element_map[element_id_ref]->y + 30));

		});
	
	temp->image->GetSignal(sfg::Image::OnMouseLeftPress).Connect([&, element_id_ref = element_id]{
			std::cout<< " move_id\n";
			moving = element_id_ref;
		});

//	desktop.Add(temp->option_window);
//	desktop.BringToFront(temp->option_window);

	int & bufferFirstElement_ref = 	bufferFirstElement;
	int & bufferSecondElement_ref = bufferSecondElement;

	int & index_F_E_B_ref = index_F_E_B;
	int & index_S_E_B_ref = index_S_E_B;
	
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		temp->vector_endings[i].ending_button->GetSignal(sfg::Widget::OnLeftClick).Connect([&, tempid = temp->id, i, temp_ref = temp, this]{
		if(temp_ref->vector_endings[i].wire_id != -1){
				wire_delete(temp_ref->vector_endings[i].wire_id);
			}else{
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
			}});

	}


	std::cout<< "//////// INFO ////////\n";	
	std::cout<< "Creating new element: " << name <<".\n" << "	id: "<< temp->id << "\n" << "	Position:\n" << "		x: " << temp->x << "\n" << "		y: " << temp->y << "\n";
	std::cout<< "////// End INFO //////\n\n";
	
	buffer = "empty";
	std::cout<< "buffer: "<< buffer << "\n\n";
	sfg::Widget::Ptr canvas = fixed->GetChildren().back();
	//fixed->Remove(canvas);
	//fixed->Put( canvas, sf::Vector2f(0, 0));
	fixed->Put( temp->image, sf::Vector2f(temp->x, temp->y));
	for(int i = 0; i < temp->vector_endings.size(); ++i){
		if(temp->vector_endings[i].lay == "left")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "right")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 60 - 3 - 5, temp->y + 30 - 3 - 5));
		if(temp->vector_endings[i].lay == "down")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 30 - 3 - 5, temp->y + 60 - 3 - 5));
		if(temp->vector_endings[i].lay == "up")
			fixed->Put( temp->vector_endings[i].ending_button, sf::Vector2f(temp->x + 30 - 3 - 5, temp->y  - 3 - 5));
	}	
	desktop.BringToFront(sfgui_window_bar);
}

int Hotwire::wire_making(int b1, int b2, int I_F_E_B, int I_S_E_B){

	if(element_map[b1]->vector_endings[I_F_E_B].other_element_id == -1 && element_map[b2]->vector_endings[I_S_E_B].other_element_id == -1){

		Wire * temp_wire = new Wire;

		wire_id++;

		wires_map[wire_id] = temp_wire;

		if(std::abs((element_map[b1]->x - element_map[b2]->x)) == std::abs((element_map[b1]->y - element_map[b2]->y))){

			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Yellow));
			
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5
						- ((element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5) - 
							(element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5))/2,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Yellow));

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(	
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5
						- ((element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5) - 
							(element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5))/2,

						element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Yellow));


			temp_wire->wire.append(sf::Vertex(
						sf::Vector2f(
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
					sf::Color::Yellow));
		
		}else{
			
			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

		std::string other_element_lay = "none";
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5),
				sf::Color::Yellow));
			
			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(
						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().left + 5,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 - 
						((element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5) -
							(element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5))/2),
				sf::Color::Yellow));

			temp_wire->wire.append(sf::Vertex(
					sf::Vector2f(	
						element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,

						element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5 - 
						((element_map[b1]->vector_endings[I_F_E_B].ending_button->GetAllocation().top + 5) -
							(element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5))/2),
				sf::Color::Yellow));


			temp_wire->wire.append(sf::Vertex(
						sf::Vector2f(
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().left + 5,
							element_map[b2]->vector_endings[I_S_E_B].ending_button->GetAllocation().top + 5),
					sf::Color::Yellow));
		

		}
		
			vector_wires.push_back(std::make_pair(b1, b2));
			vector_wires.push_back(std::make_pair(b2, b1));

			element_map[b1]->vector_endings[I_F_E_B].other_element_id = b2;
			element_map[b2]->vector_endings[I_S_E_B].other_element_id = b1;

			element_map[b1]->vector_endings[I_F_E_B].wire_id = wire_id;
			element_map[b2]->vector_endings[I_S_E_B].wire_id = wire_id;

			temp_wire->first_other_id = b1;
			temp_wire->second_other_id = b2;


			element_map[b1]->vector_endings[I_F_E_B].other_element_ending_id = I_S_E_B;
			element_map[b2]->vector_endings[I_S_E_B].other_element_ending_id = I_F_E_B;

			temp_wire->first_other_ending_id = I_F_E_B;
			temp_wire->second_other_ending_id = I_S_E_B;


			temp_wire->wire.setPrimitiveType ( sf::LinesStrip ) ;
			map_draw_wire[wire_id] = &temp_wire->wire;

			std::cout<< "New wire: "<< b1 << ", " << b2 << "\n\n";
			std::cout<< "Amount wire: " << wire_id <<"\n\n";


			bufferFirstElement = -1;
			bufferSecondElement = -1;
	}
	return wire_id;
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
	if(new_string[new_string.length() - 1] == '.'){
		new_string += '0';
	}
	return new_string;
}

int Hotwire::element_delete(int id){
	int temp_id = -1;

	int wire_id;

	int first_id;
	int second_id;

	int first_ending_id;
	int second_ending_id;


	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		temp_id = element_map[id]->vector_endings[i].other_element_id;
		if(temp_id != -1){
			wire_id = element_map[id]->vector_endings[i].wire_id;

			first_id = wires_map[wire_id]->first_other_id;
			second_id = wires_map[wire_id]->second_other_id;

			first_ending_id = wires_map[wire_id]->first_other_ending_id;
			second_ending_id = wires_map[wire_id]->second_other_ending_id;

			wire_delete(wire_id);
		
			std::cout<< "element_map[id]->vector_endings[i].wire_id_ = " << element_map[id]->vector_endings[i].wire_id << "\n";
			std::cout<<"map_draw_wire.size(): "<< map_draw_wire.size() << "\n";

			temp_id = -1;
		}


	}	

	elements_position_set.erase(std::make_pair(element_map[id]->x, element_map[id]->y));

	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		fixed->Remove(element_map[id]->vector_endings[i].ending_button);
	}

	fixed->Remove(element_map[id]->image);
	element_map.erase(id);


	bufferFirstElement = -1;
	bufferSecondElement = -1;
}

int Hotwire::wire_delete(int id){

	element_map[ wires_map[id]->first_other_id ]->vector_endings[ wires_map[id]->first_other_ending_id ].other_element_id = -1;
	element_map[ wires_map[id]->second_other_id ]->vector_endings[ wires_map[id]->second_other_ending_id ].other_element_id = -1;

	element_map[ wires_map[id]->first_other_id ]->vector_endings[ wires_map[id]->first_other_ending_id ].wire_id = -1;
	element_map[ wires_map[id]->second_other_id ]->vector_endings[ wires_map[id]->second_other_ending_id ].wire_id = -1;

	element_map[ wires_map[id]->first_other_id ]->vector_endings[ wires_map[id]->first_other_ending_id ].other_element_ending_id = -1;
	element_map[ wires_map[id]->second_other_id ]->vector_endings[ wires_map[id]->second_other_ending_id ].other_element_ending_id = -1;

	map_draw_wire.erase(id);

	bufferFirstElement = -1;
	bufferSecondElement = -1;
}

int Hotwire::search_circuit(int id){
	std::cout<< "id: "<< id  <<"\n\n";
	edge new_edge;
	std::vector<edge> temp_edge;
	float temp_res = 0;
	float temp_vol = 0;
	int temp_i = 0;

	temp_edge = dfs(id, 0, 0);
	for(int i = 0; i < temp_edge.size(); ++i){
		if(element_map[ temp_edge[i].end_id ]->getType() == "knot"){
				edge_id++;
				temp_edge[i].id = edge_id;
				temp_edge[i].begin_id = id;
				temp_res += temp_edge[i].resistance;
				temp_vol += temp_edge[i].voltage;
				
				new_edge.id = temp_edge[i].id;
				new_edge.begin_id = id;
				new_edge.end_id = temp_edge[i].end_id;
				new_edge.resistance = temp_res;
				new_edge.voltage = temp_vol;

				std::cout<<"id: "<< new_edge.id << "\n";
				std::cout<<"begin_id: "<< new_edge.begin_id << "\n";
				std::cout<<"end_id: "<< new_edge.end_id << "\n";
				std::cout<<"resistance: "<< new_edge.resistance << "\n";
				std::cout<<"voltage: "<< new_edge.voltage << "\n\n";
	
				vector_edge.push_back(new_edge);
			temp_res = 0;
			temp_vol = 0;
		}
	}
}


std::vector< Hotwire::edge> Hotwire::dfs(int id, int before_id, int before_ending_id){
	edge temp_edge;
	std::vector<edge> vector_edge;
	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		if(!element_map[id]->vector_endings[i].visited){
			element_map[id]->vector_endings[i].visited = true;
			if(element_map[id]->vector_endings[i].other_element_id != -1){
				temp_edge = deadly_dfs(element_map[id]->vector_endings[i].other_element_id, element_map[id]->vector_endings[i].other_element_ending_id, id, i);
				temp_edge.begin_id = id;
				vector_edge.push_back(temp_edge);
			}
		}
	}
	return vector_edge;
}


Hotwire::edge Hotwire::deadly_dfs(int id, int ending_id, int before_id, int before_ending_id){
	std::cout<<"point 1\n";
	edge new_edge;
	edge temp_edge;

	element_map[id]->vector_endings[ending_id].visited = true;

	if(element_map[ id ]->getType() == "knot"){
		new_edge.end_id = id;
		return new_edge;
	}
	
	std::cout<<"point 2\n";
	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		if(!element_map[id]->vector_endings[i].visited){
			element_map[id]->vector_endings[i].visited = true;
			if(element_map[id]->vector_endings[i].other_element_id != -1){

				temp_edge = deadly_dfs(element_map[id]->vector_endings[i].other_element_id, element_map[id]->vector_endings[i].other_element_ending_id, id, i);

				new_edge.resistance = element_map[id]->resistance;
				new_edge.voltage = element_map[id]->voltage;

				new_edge.resistance += temp_edge.resistance;
				new_edge.voltage += temp_edge.voltage;

				new_edge.end_id = temp_edge.end_id;

				return new_edge;
			}else{
				new_edge.end_id = id;
			}
		}else{
			new_edge.end_id = id;
		}
	}

	return new_edge;
}

int Hotwire::move(int id){
	if(elements_position_set.count( std::make_pair( ((mouse.getPosition().x/60))*60, ((mouse.getPosition().y/60))*60 )) > 0){
			return 0;
	}
	int b1 = 0;
	int b2 = 0;
	int I_F = 0;
	int I_S = 0;	
	elements_position_set.erase(std::make_pair(element_map[id]->x, element_map[id]->y));
	for(int i = 0; i < element_map[id]->vector_endings.size(); ++i){
		fixed->Remove(element_map[id]->vector_endings[i].ending_button);
		element_map[id]->x = ((mouse.getPosition().x/60))*60;
		element_map[id]->y = ((mouse.getPosition().y/60))*60;
		if(element_map[id]->vector_endings[i].lay == "left")
			fixed->Put( element_map[id]->vector_endings[i].ending_button, sf::Vector2f(element_map[id]->x - 3 - 5, element_map[id]->y + 30 - 3 - 5));
		if(element_map[id]->vector_endings[i].lay == "right")
			fixed->Put( element_map[id]->vector_endings[i].ending_button, sf::Vector2f(element_map[id]->x + 60 - 3 - 5, element_map[id]->y + 30 - 3 - 5));
		if(element_map[id]->vector_endings[i].lay == "down")
			fixed->Put( element_map[id]->vector_endings[i].ending_button, sf::Vector2f(element_map[id]->x + 30 - 3 - 5, element_map[id]->y + 60 - 3 - 5));
		if(element_map[id]->vector_endings[i].lay == "up")
			fixed->Put( element_map[id]->vector_endings[i].ending_button, sf::Vector2f(element_map[id]->x + 30 - 3 - 5, element_map[id]->y  - 3 - 5));
		if(element_map[id]->vector_endings[i].wire_id != -1){
			b1 = wires_map[ element_map[id]->vector_endings[i].wire_id ]->first_other_id;	
			b2 = wires_map[ element_map[id]->vector_endings[i].wire_id ]->second_other_id;

			I_F = wires_map[ element_map[id]->vector_endings[i].wire_id ]->first_other_ending_id;
			I_S = wires_map[ element_map[id]->vector_endings[i].wire_id ]->second_other_ending_id;

			wire_delete(element_map[id]->vector_endings[i].wire_id);
			wire_making(b1, b2, I_F, I_S);
		}
	}

	fixed->Remove(element_map[id]->image);
	fixed->Put(element_map[id]->image, sf::Vector2f(element_map[id]->x, element_map[id]->y));
	elements_position_set.insert(std::make_pair( ((element_map[id]->x/60))*60, ((element_map[id]->y/60))*60 ));
	moving = 0;
}

#include <utility>
int Hotwire::search_contour(){
	std::vector<std::pair<int, int> > list[100];
	for (int i = 1; i < vector_edge.size(); i++)
	{
		list[vector_edge[i].begin_id].push_back(std::make_pair(vector_edge[i].end_id, vector_edge[i].id));
		list[vector_edge[i].end_id].push_back(std::make_pair(vector_edge[i].begin_id, vector_edge[i].id));
	}
	std::queue<int> q;
	int f, s, way[vertex_amount], rebr[vertex_amount];
	if(vector_edge.empty()){
		return 0;
	}
	for (size_t i = 1; i <= vector_edge.size(); i++)
	{
		int just_another_variable;
		if (!edge_set.count(i))
		{
			just_another_variable = i;
			q.push(vector_edge[i].begin_id);
			f = vector_edge[i].end_id;
			s = vector_edge[i].begin_id;
		}
		else
		{
			continue;
		}
		bool used[vertex_amount] = {false};      /////////////////////////////////////////////////////////////////////////////////
		while(!q.empty()){
			int v = q.front();
			if (v == f)
				break;
			q.pop();
			for (size_t i = 0; i < list[v].size(); i++)
			{
				int to = list[v][i].first;
				if (used[to] == false)
				{
					q.push(to);
					used[to] = true;
					way[to] = v;
					rebr[to] = list[v][i].second;
				}
			}
		}
		edge_set.insert(just_another_variable);
		while (1)
		{
			edge_set.insert(rebr[f]);
			f = way[f];
			if (f == s)
				break;
		}
	}
}

int Hotwire::gauss (std::vector < std::vector<double> > a, std::vector<double> & ans) {
	static const float EPS = 0.0001;
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	std::vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (std::abs (a[i][col]) > std::abs (a[sel][col]))
				sel = i;
		if (std::abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			std::swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (std::abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			//return INF;
	return 1;
}
