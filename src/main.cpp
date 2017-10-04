#include "hotwire.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>


const int fps = 60;
const sf::Time frame_time = sf::seconds(1.f / fps);

int main(void) {
    sf::Clock clock;
    sf::Time start_time, current_time;
    sfg::SFGUI sfgui;
    Hotwire* hotwire = new Hotwire();
    hotwire->init();
    while(hotwire->running) {
        current_time = clock.getElapsedTime();
        hotwire->handle_events();
        while(current_time - start_time > frame_time){
             hotwire->handle_events();
             hotwire->update();
             start_time += frame_time;
        }
        hotwire->update();
        hotwire->render();
    }
    hotwire->clear();
}
