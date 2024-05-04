#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"


int main()
{
    // Create a video mode
    VideoMode vm(1920, 1080);

    // Create a window
    RenderWindow window(vm, "Ping-Pong", Style::Fullscreen);

    // The Player 1 Bat
    Bat batPlayer1(1920 - 60, 1080 / 2);

    // The Player 2 Bat
    Bat batPlayer2(60, 1080 / 2);

    // The ball
    Ball ball(1920 - 1000, 1080 / 2);

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

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            batPlayer2.moveUp();
        }
        else
        {
            batPlayer2.stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            batPlayer2.moveDown();
        }
        else
        {
            batPlayer2.stopDown();
        }

        /*
        Update 
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */
        Time dt = clock.restart();
        batPlayer1.update(dt);
        batPlayer2.update(dt);
        ball.update(dt);

        /*
        Drawings
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        window.clear();
        window.draw(batPlayer1.getBatShape());
        window.draw(batPlayer2.getBatShape());
        window.draw(ball.getBallShape());
        window.display();
    }
}