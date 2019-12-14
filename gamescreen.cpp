/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: crossboard.h
 * Description: Class interface for Crossboard class
 */
#include <iostream>
#include "gfx2.h"
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;

#include "gamescreen.h"

Gamescreen::Gamescreen()
{
}

Gamescreen::~Gamescreen()
{
}

void Gamescreen::showMenu(char c)
{
    gfx_color(255, 255, 255);
    gfx_rectangle(125, 125, 450, 200);
    gfx_color(200, 200, 0);
    gfx_fill_rectangle(150, 150, 400, 150);
    gfx_color(0, 0, 0);
    gfx_fill_rectangle(175, 175, 350, 100);
    gfx_color(0, 200, 200);
    gfx_text(200, 200, "Use the left and right arrow keys to move the man.");
    gfx_text(240, 225, "Avoid... the raining men! Hallelujah!");

    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

void Gamescreen::showGameover()
{
}

void Gamescreen::showScore()
{
}
