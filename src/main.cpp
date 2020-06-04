#include <iostream>
#include "Array2D.h"
#include "SFML/Graphics.hpp"
#include "DisplayableFluidBuilder.h"

//if using Windows Subsystem for Linux - this allows viewing sfml
#define WSL_ALLOW_DISPLAY setenv("DISPLAY", "127.0.0.1:0", true)

int main() {
    DisplayableFluidBuilder builder;
    auto fluid = builder.Size(64).TimeStep(0.1).Diffusion(0.0001).Build();






    /*
    //test
    WSL_ALLOW_DISPLAY;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
    }

*/
    return 0;
}
