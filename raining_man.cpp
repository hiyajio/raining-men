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

#include "raining_man.h"

Rainman::Rainman()
{
    int x = 50;
    int y = 25;
    gfx_color(0, 200, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y + (SIZE / 2) - SIZE));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x - (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_circle(x, y, SIZE / 2);
    gfx_circle(x, y, SIZE / 2);
}

Rainman::Rainman(int x)
{
    int y = 25;
    gfx_color(0, 200, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y + (SIZE / 2) - SIZE));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x - (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_circle(x, y, SIZE / 2);
    gfx_circle(x, y, SIZE / 2);
}

Rainman::~Rainman()
{
}

void Rainman::show(int x, int y)
{
    y = y + 25;
    gfx_color(0, 200, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y + (SIZE / 2) - SIZE));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x - (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_circle(x, y, SIZE / 2);
    gfx_circle(x, y, SIZE / 2);
}
