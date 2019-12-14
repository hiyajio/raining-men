/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: hallelujah.cpp
 * Description: Inspired by the 1980's classic song "It's Raining Men" by The Weather Girls, this game is essentially what that would look like in reality (Best played when song is also playing in the background).
 */
#include <iostream>
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <vector>

void man(const int, int, int);
void raining_man(const int, int, int);
void menu(const int, int, int, char);
bool impact(int circleX, int circleY, int x, int y);

#define PI 3.14159265

int main()
{
    const int XSIZE = 700, YSIZE = 500, SIZE = 50, MENUSML = 49, MENULRG = 451, RADIUS = 25;
    unsigned int delay = 10000;
    char c;
    int x = 350, y = 450, response;
    int counter = 0;
    int i = 72;
    bool play = true;

    gfx_open(XSIZE, YSIZE, "It's Raining Men!"); // Open a new window for drawing.
    gfx_color(200, 200, 0);

    menu(SIZE, x, y, c);

    while (true)
    {
        response = gfx_event_waiting();
        man(SIZE, x, y); // Make watch

        if (response)
        {
            gfx_clear();
            c = gfx_wait();
            if (c == 'Q') // On left click, change direction of hand
            {
                x = x - 25;
                man(SIZE, x, y);
            }
            else if (c == 'S')
            {
                x = x + 25;
                man(SIZE, x, y);
            }
            else if (c == 'q')
            {
                break; // Quit if it is the letter q.
            }
            usleep(delay);
        }
        else
        {
            gfx_clear();
            man(SIZE, x, y); // Make watch
            usleep(delay);
        }
    }
}

void man(const int SIZE, int x, int y)
{
    gfx_color(0, 200, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y + (SIZE / 2)));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x - (SIZE / 2)), (y - (SIZE / 2)));
    gfx_circle(x, y - SIZE, SIZE / 2);
    gfx_circle(x, y - SIZE, SIZE / 2);
}

void raining_man(const int SIZE, int x, int y)
{
    gfx_color(0, 200, 200);
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y + (SIZE / 2)));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x - (SIZE / 2)), (y - (SIZE / 2)));
    gfx_circle(x, y - SIZE, SIZE / 2);
    gfx_circle(x, y - SIZE, SIZE / 2);
}

void menu(const int SIZE, int x, int y, char c)
{
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y + (SIZE / 2)));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2)), (x + (SIZE / 2)), (y - (SIZE / 2)));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2)), (x - (SIZE / 2)), (y - (SIZE / 2)));
    gfx_text(200, 200, "| Use the left and right arrow keys to move the man. |");
    gfx_text(240, 225, "| Avoid... the raining men! Hallelujah! |");
    man(SIZE, x, y); // Make watch

    c = gfx_wait();
    gfx_flush();
}

// // Checks to see if there was an impact
// bool impact(int circleX, int circleY, int x, int y)
// {
//     if (x <= circleX + targetRadius && x >= circleX - targetRadius && y <= circleY + targetRadius && y >= circleY - targetRadius)
//         return true;
//     return false;
// }
