#include <iostream>
#include "Array2D.h"
#include "SFML/Graphics.hpp"
#include "DisplayableFluidBuilder.h"

//if using Windows Subsystem for Linux - this allows viewing sfml
#define WSL_ALLOW_DISPLAY setenv("DISPLAY", "127.0.0.1:0", true)

int main() {


    WSL_ALLOW_DISPLAY;
    constexpr int size = 200;
    DisplayableFluidBuilder builder;
    auto renderWindow = new sf::RenderWindow(sf::VideoMode(size, size), "Fluid");
    auto fluid = builder.Size(size).
            TimeStep(0.1).
            Diffusion(0.0000001).
            Viscosity(0.0000001).
            CreateWindow(renderWindow).Build();


    sf::Event event;


    while (renderWindow->isOpen()) {

        while (renderWindow->pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                renderWindow->close();
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                fluid.AddDensity(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2, std::rand() % 120);
            }
        }
        float rand1 = -1.f + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));
        float rand2 = -1.f + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));

        fluid.AddVelocity(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2, rand1, rand2);
        renderWindow->clear(sf::Color::White);
        fluid.Step();
        fluid.Render();
        fluid.Fade();
        renderWindow->display();
    }




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
