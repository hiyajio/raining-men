/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: gamescreen.h
 * Description: Class interface for Gamescreen class
 */
#include <iostream>
#include "gfx2.h"
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;

// Connect needed external file
#include "gamescreen.h"

Gamescreen::Gamescreen()
{
    // Initialize gamescreen
    gfx_open(XSIZE, YSIZE, "It's Raining Men!");
    gfx_color(200, 200, 0);
}

Gamescreen::~Gamescreen()
{
}

void Gamescreen::showMenu(char c)
{
    // Display start menu
    gfx_color(255, 255, 255);
    gfx_rectangle(125, 125, 450, 200);
    gfx_color(200, 200, 0);
    gfx_fill_rectangle(150, 150, 400, 150);
    gfx_color(0, 0, 0);
    gfx_fill_rectangle(175, 175, 350, 100);
    gfx_color(0, 200, 200);
    gfx_text(185, 200, "Use the left & right arrow keys to move the man.");
    gfx_text(220, 225, "Avoid... the raining men! Hallelujah!");

    // Terminate program if q pressed
    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

void Gamescreen::showGameover(char c)
{
    // Display end menu
    gfx_rectangle(125, 125, 450, 200);
    gfx_color(255, 255, 255);
    gfx_text(335, 225, "Score");
    gfx_color(200, 200, 0);
    gfx_rectangle(150, 150, 400, 150);
    gfx_color(255, 0, 0);
    gfx_text(210, 200, "Gameover! Press spacebar twice to restart");

    // Terminate program if q pressed
    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

void Gamescreen::showScore()
{
    // Display score card
    gfx_color(200, 200, 0);
    gfx_circle(350, 190, 40);
    gfx_color(0, 255, 0);
    gfx_circle(350, 190, 50);
    gfx_color(255, 255, 255);
    gfx_text(335, 185, "Score");
}
