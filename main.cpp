#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Create a video mode
    VideoMode vm(1920, 1080);

    // Create a window
    RenderWindow window(vm, "Ping-Pong", Style::Fullscreen);

    while (window.isOpen())
    {

        /*
        Handle the player key presses
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
        Drawings
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        window.clear();
        window.display();
    }
}