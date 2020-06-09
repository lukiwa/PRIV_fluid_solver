#include <iostream>
#include <chrono>
#include "Array2D.h"
#include "SFML/Graphics.hpp"
#include "DisplayableFluidBuilder.h"
#include "SFML/OpenGL.hpp"

//if using Windows Subsystem for Linux - this allows viewing sfml
#define WSL_ALLOW_DISPLAY setenv("DISPLAY", "127.0.0.1:0", true)

void FluidTest();

void OpenGLTest();

int main() {
    WSL_ALLOW_DISPLAY;
    //OpenGLTest();
    FluidTest();
    return 0;
}

void OpenGLTest() {

    sf::Window window(sf::VideoMode(800, 600), "OpenGL",
                      sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);


    window.setActive(true);


    bool running = true;
    sf::Event event;

    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            } else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor4b(0, 0, 0, 12);
        glVertex2i(100, 100);
        glEnd();

        window.display();
    }


}


void FluidTest() {


    DisplayableFluidBuilder builder;
    sf::RenderWindow window;
    window.setFramerateLimit(30);
    auto fluid = builder.Size(200).
            TimeStep(2).
            Diffusion(0.0000001).
            Viscosity(0.0000001).
            Fade(0.5).
            Build(window);


    sf::Event event;

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    while (window.isOpen()) {
        end = std::chrono::system_clock::now();
        std::chrono::duration<float> diff = end - start;
        start = end;


        window.setTitle("Fluid simulator " + std::to_string(int(1.0f / diff.count())) + " fps");
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }

        //generate random velocities
        double rand1 = -1.0 + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));
        double rand2 = -1.0 + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (1.f + 1.f)));

        //add some density at the middle of the screen
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                fluid.AddDensity(window.getSize().x / 2, window.getSize().y / 2, std::rand() % 150);
            }
        }
        fluid.AddVelocity(window.getSize().x / 2, window.getSize().y / 2, rand1, rand2);
        window.clear(sf::Color::White);
        fluid.Render();
        window.display();
    }

}