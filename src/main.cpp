#include <iostream>
#include "Array2D.h"
#include "SFML/Graphics.hpp"
#include "DisplayableFluidBuilder.h"

//if using Windows Subsystem for Linux - this allows viewing sfml
#define WSL_ALLOW_DISPLAY setenv("DISPLAY", "127.0.0.1:0", true)

int main() {


    WSL_ALLOW_DISPLAY;
    DisplayableFluidBuilder builder;
    sf::RenderWindow window;
    auto fluid = builder.Size(200).
            TimeStep(0.1).
            Diffusion(0.0000001).
            Viscosity(0.0000001).
            Fade(0.5).
            Build(window);


    sf::Event event;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                fluid.AddDensity(window.getSize().x / 2, window.getSize().y / 2, std::rand() % 120);
            }
        }
        float rand1 = -1.f + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));
        float rand2 = -1.f + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));

        fluid.AddVelocity(window.getSize().x / 2, window.getSize().y / 2, rand1, rand2);

        window.clear(sf::Color::White);
        fluid.Render();
        window.display();
    }

    return 0;
}
