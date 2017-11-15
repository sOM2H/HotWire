#ifndef TM_H
#define TM_H
#define WS_W render_window.getSize().x
#define WS_H render_window.getSize().y
#define SFGUI_WS_W render_window.getSize().x 
#define SFGUI_WS_H render_window.getSize().y 
#define SFGUI_WS_BAR_W sfgui_window_bar->GetAllocation().width
#define SFGUI_WS_BAR_H render_window.getSize().y

//#include "texture_manager.h"
#include "elements.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <memory>
#include <set>
#include <queue>

class Hotwire{
    public: 
        Hotwire();
        ~Hotwire();

        sf::RenderWindow render_window;
		sfg::SFGUI sfgui;

		sfg::Canvas::Ptr canvas = sfg::Canvas::Create();
		sfg::Canvas::Ptr canvas_background = sfg::Canvas::Create();
		sfg::Canvas::Ptr canvas_background_start = sfg::Canvas::Create();

		sfg::Desktop desktop;

		sf::Mouse mouse;

		sfg::ScrolledWindow::Ptr scrolledwindow = sfg::ScrolledWindow::Create();

		sfg::Box::Ptr boxIN = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
		sfg::Box::Ptr box = sfg::Box::Create();	

		sfg::Window::Ptr sfgui_window = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_bar = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
///
		sfg::Window::Ptr sfgui_window_menu = sfg::Window::Create();
		sfg::Window::Ptr sfgui_window_start = sfg::Window::Create();
	
		sfg::Image::Ptr About_image = sfg::Image::Create();
		sfg::Image::Ptr background = sfg::Image::Create();
		sfg::Image::Ptr background_start = sfg::Image::Create();

		sfg::Button::Ptr Start = sfg::Button::Create();
		sfg::Button::Ptr About = sfg::Button::Create();
		sfg::Button::Ptr Tests = sfg::Button::Create();
		sfg::Button::Ptr Exit = sfg::Button::Create();
		sfg::Image::Ptr hotwire_start = sfg::Image::Create();

		sfg::Button::Ptr test1 = sfg::Button::Create();
		sfg::Button::Ptr test2 = sfg::Button::Create();
		sfg::Button::Ptr test3 = sfg::Button::Create();

		sfg::Button::Ptr backToMenu = sfg::Button::Create();

		sfg::Fixed::Ptr fixed_menu = sfg::Fixed::Create();
		sfg::Fixed::Ptr fixed_tests = sfg::Fixed::Create();
		sfg::Fixed::Ptr fixed_start = sfg::Fixed::Create();
///
		sfg::Window::Ptr sfgui_window_tests = sfg::Window::Create();

		sfg::Window::Ptr sfgui_window_about= sfg::Window::Create();


		sfg::Button::Ptr clear_button = sfg::Button::Create();

		sf::Vector2f pos_bar;

		std::string state = "none";

		struct edge{
			int id;
			int begin_id;
			int end_id;
			float resistance = 0;
			float voltage = 0;
		};

		std::map<std::string, sfg::Image::Ptr> image_map;

		sfg::Fixed::Ptr fixed = sfg::Fixed::Create();
		void init_image(const std::string & name);

		std::map<int, Element* > element_map;
		std::map<int, Wire* > wires_map;

		std::set<std::pair<int, int> > elements_position_set;

		std::set<int> edge_set;	

		std::vector<std::pair<int, int> > vector_wires;

		std::vector<std::vector<double>> vector_eq;

		struct wires_struct{
			sf::VertexArray wires;
		};

		std::map<int, sf::VertexArray *> map_draw_wire;
		//std::vector<sf::CircleShape *> vector_draw_circleshape;

		std::string buffer = "empty";

		int bufferFirstElement = -1;
		int bufferSecondElement = -1;

		int index_F_E_B = -1;
		int index_S_E_B = -1;

        bool running = false;

		int amountImageX;
		int amountImagey;


		int wire_id = 0;
		int element_id = 0;
		int edge_id = 0;
		int vertex_amount = 0;

		int  moving = 0;


		int element_delete(int id);
		int wire_delete(int id);

		int search_circuit(int id);
		
		std::vector<edge> vector_edge;

		std::vector<edge> dfs(int id, int before_id, int before_ending_id);
		edge deadly_dfs( int id, int ending_id, int before_id, int before_ending_id);


		int gauss (std::vector < std::vector<double> > a, std::vector<double> & ans);

		int search_contour();

		int element_making(std::string name, sf::Vector2i pos);
		int wire_making(int b1, int b2, int I_F_E_B, int I_S_E_B);
		
		int move(int id);

		std::string regex_string(std::string string);


        void init();
        void handle_events();
        void render();
        void update();
        void clear();
};
#endif
