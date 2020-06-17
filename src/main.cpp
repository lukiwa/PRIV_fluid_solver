#include <iostream>
#include "Array2D.h"
#include "SFML/Graphics.hpp"
#include "DisplayableFluidBuilder.h"
#include  "Random.h"

//if using Windows Subsystem for Linux - this allows viewing sfml
#define WSL_ALLOW_DISPLAY setenv("DISPLAY", "127.0.0.1:0", true)


int main() {

    WSL_ALLOW_DISPLAY;
    Random::Seed();

    DisplayableFluidBuilder builder;
    sf::RenderWindow window;
    const double scale = 3;
    auto fluid = builder.Size(600).
            TimeStep(0.25).
            Diffusion(0.0000001).
            Viscosity(0.0000001).
            Fade(0.08).
            Scale(scale).
            Build(window);


    sf::Event event;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }



        //add some density at the middle of the screen
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                fluid.AddDensity(window.getSize().x / scale / 2 + i, window.getSize().y / scale / 2 + j,
                                 Random::Int(0, 200));
            }
        }
        fluid.AddVelocity(window.getSize().x / scale / 2, window.getSize().y / scale / 2,
                          Random::Double(-5, 5),
                          Random::Double(-5, 5));
        window.clear(sf::Color::White);
        fluid.Render();
        window.display();
    }

    return 0;
}
