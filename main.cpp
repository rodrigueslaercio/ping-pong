#include <iostream>
#include <SFML/Graphics.hpp>
#include "BatPlayer1.h"


int main()
{
    // Create a video mode
    VideoMode vm(1920, 1080);

    // Create a window
    RenderWindow window(vm, "Ping-Pong", Style::Fullscreen);

    // The Player 1 Bat
    BatPlayer1 batPlayer1(1920 - 60, 1080 / 2);

    // The clock couting the frames
    Clock clock;

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

        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            batPlayer1.moveUp();
        }
        else
        {
            batPlayer1.stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            batPlayer1.moveDown();
        }
        else
        {
            batPlayer1.stopDown();
        }

        /*
        Update 
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */
        Time dt = clock.restart();
        batPlayer1.update(dt);

        /*
        Drawings
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        window.clear();
        window.draw(batPlayer1.getBatShape());
        window.display();
    }
}