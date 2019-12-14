/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: hallelujah.cpp
 * Description: Inspired by the 1980's classic song "It's Raining Men" by The Weather Girls, this game is essentially what that would look like in reality (Best played when song is also playing in the background).
 */
#include <iostream>
#include "gfx2.h"
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

#include "raining_man.h"

void man(const int, int, int);
void raining_man(const int, int, int);
void menu(const int, const int, const int, int, int, char);
bool impact(int, int, int, int);

#define PI 3.14159265
#define RADIUS 60

int main()
{
    const int XSIZE = 700, YSIZE = 500, SIZE = 50;
    unsigned int delay = 10000;
    char c;
    int x = 350, y = 450, a, b, counter = 0, score = 0, response;
    string sc = to_string(score);
    char const *pchar = sc.c_str();
    bool play = true;
    int rainMen[] = {50, 150, 250, 350, 450, 550, 650};
    int speed[7] = {25};
    srand(time(NULL));
    a = rand() % 6 + 1;
    b = rand() % 7;
    // Rainman man1(50);
    // Rainman man1, man2(150), man3(250), man4(350), man5(450), man6(550), man7(650);

    gfx_open(XSIZE, YSIZE, "It's Raining Men!"); // Open a new window for drawing.
    gfx_color(200, 200, 0);

    menu(SIZE, XSIZE, YSIZE, x, y, c);

    while (true)
    {
        response = gfx_event_waiting();
        man(SIZE, x, y); // Make watch

        if (response)
        {
            gfx_clear();
            c = gfx_wait();
            gfx_text(340, 180, "Score");
            gfx_text(350, 200, pchar);
            if (c == 'Q') // On left click, change direction of hand
            {
                gfx_text(340, 180, "Score");
                gfx_text(350, 200, pchar);
                x -= 100;
                man(SIZE, x, y);
                for (int i = 0; i < 7; i++)
                {
                    a = rand() % 6 + 1;
                    switch (a)
                    {
                    case 1:
                        speed[i] += 5;
                        break;
                    case 2:
                        speed[i] += 7;
                        break;
                    case 3:
                        speed[i] += 9;
                        break;
                    case 4:
                        speed[i] += 11;
                        break;
                    case 5:
                        speed[i] += 13;
                        break;
                    case 6:
                        speed[i] += 15;
                        break;
                    }
                    if (i == b)
                    {
                    }
                    else
                    {
                        if (impact(rainMen[i], speed[i], x, y) == true)
                        {
                            return 0;
                        }
                        raining_man(SIZE, rainMen[i], speed[i]);
                    }
                }
            }
            else if (c == 'S')
            {
                gfx_text(340, 180, "Score");
                gfx_text(350, 200, pchar);
                x += 100;
                man(SIZE, x, y);
                for (int i = 0; i < 7; i++)
                {
                    a = rand() % 6 + 1;
                    switch (a)
                    {
                    case 1:
                        speed[i] += 5;
                        break;
                    case 2:
                        speed[i] += 7;
                        break;
                    case 3:
                        speed[i] += 9;
                        break;
                    case 4:
                        speed[i] += 11;
                        break;
                    case 5:
                        speed[i] += 13;
                        break;
                    case 6:
                        speed[i] += 15;
                        break;
                    }
                    if (i == b)
                    {
                    }
                    else
                    {
                        if (impact(rainMen[i], speed[i], x, y) == true)
                        {
                            return 0;
                        }
                        raining_man(SIZE, rainMen[i], speed[i]);
                    }
                }
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
            gfx_text(340, 180, "Score");
            gfx_text(350, 200, pchar);
            man(SIZE, x, y); // Make watch
            for (int i = 0; i < 7; i++)
            {
                a = rand() % 6 + 1;
                switch (a)
                {
                case 1:
                    speed[i] += 5;
                    break;
                case 2:
                    speed[i] += 7;
                    break;
                case 3:
                    speed[i] += 9;
                    break;
                case 4:
                    speed[i] += 11;
                    break;
                case 5:
                    speed[i] += 13;
                    break;
                case 6:
                    speed[i] += 15;
                    break;
                }
                if (speed[i] > 500)
                {
                    speed[i] = 0;
                    counter++;
                    if (counter == 7)
                    {
                        b = rand() % 7;
                        counter = 0;
                        score++;
                        sc = to_string(score);
                        pchar = sc.c_str();
                    }
                }
                if (i == b)
                {
                }
                else
                {
                    if (impact(rainMen[i], speed[i], x, y) == true)
                    {
                        return 0;
                    }
                    raining_man(SIZE, rainMen[i], speed[i]);
                }
            }
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
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y + (SIZE / 2) - SIZE));
    gfx_line((x + (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y - (SIZE / 2) - SIZE), (x + (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_line((x - (SIZE / 2)), (y + (SIZE / 2) - SIZE), (x - (SIZE / 2)), (y - (SIZE / 2) - SIZE));
    gfx_circle(x, y, SIZE / 2);
    gfx_circle(x, y, SIZE / 2);
}

void menu(const int SIZE, const int XSIZE, const int YSIZE, int x, int y, char c)
{
    gfx_line(150, 150, 550, 150);
    gfx_line(550, 150, 550, 300);
    gfx_line(550, 300, 150, 300);
    gfx_line(150, 300, 150, 150);
    gfx_color(255, 255, 255);
    gfx_line(175, 175, 525, 175);
    gfx_line(525, 175, 525, 275);
    gfx_line(525, 275, 175, 275);
    gfx_line(175, 275, 175, 175);
    gfx_color(200, 200, 0);
    gfx_text(200, 200, "Use the left and right arrow keys to move the man.");
    gfx_text(240, 225, "Avoid... the raining men! Hallelujah!");
    man(SIZE, x, y); // Make watch

    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

// Checks to see if there was an impact
bool impact(int xa, int ya, int x, int y)
{
    if (x <= xa + RADIUS && x >= xa - RADIUS && y <= ya + RADIUS && y >= ya - RADIUS)
        return true;
    return false;
}
