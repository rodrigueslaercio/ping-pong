#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include <sstream>


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

    // HUD
    Font font;
    font.loadFromFile("fonts/DS-DIGIT.ttf");

    Text hudP1;
    Text hudP2;

    hudP1.setFont(font);
    hudP1.setCharacterSize(40);
    hudP1.setFillColor(Color::White);
    hudP1.setPosition(60, 60);

    hudP2.setFont(font);
    hudP2.setCharacterSize(40);
    hudP2.setFillColor(Color::White);
    hudP2.setPosition(1920 - 200, 60);


    // Scores
    int scoreP1 = 0;
    int scoreP2 = 0;

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


        // HUD settings
        std::stringstream ss;
        std::stringstream ss2;
        ss << "Score: " << scoreP1;
        ss2 << "Score: " << scoreP2;
        hudP1.setString(ss.str());
        hudP2.setString(ss2.str());

        // Check if the ball hit the bottom of the screen
        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();
        }

        // Check if the ball hit the top of the screen
        if (ball.getPosition().top < 0)
        {
            ball.reboundTop();
        }

        // Check if the ball hit the bat
        if (ball.getPosition().intersects(batPlayer1.getPosition()) || ball.getPosition().intersects(batPlayer2.getPosition()))
        {
            ball.reboundBat();
        }

        // Point for player 1
        if (ball.getPosition().left > window.getSize().x)
        {
            ball.point();

            scoreP1++;
        }

        // Point for player 2
        if (ball.getPosition().left < 0)
        {
            ball.point();

            scoreP2++;
        }

        /*
        Drawings
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        window.clear();
        window.draw(hudP1);
        window.draw(hudP2);
        window.draw(batPlayer1.getBatShape());
        window.draw(batPlayer2.getBatShape());
        window.draw(ball.getBallShape());
        window.display();
    }
}