/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: project.cpp
 * Description: Inspired by the 1980's classic song "It's Raining Men" by The Weather Girls, this game is essentially what that would look like in reality (Best played when song is also play in the background).
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

// Connect needed external file
#include "gamescreen.h"

void man(const int, int, int);
void rain_man(const int, int, int);
bool collide(int, int, int, int);

int main()
{
    Gamescreen Mainscreen; // Instantiate screen
    char newfont[] =
        "-misc-fixed-medium-r-normal--14-*-*-*-*-*-iso8859-1";
    gfx_changefont(newfont);
    unsigned int delay = 12000;
    char c;
    int x = 350, y = 450, a, b, counter = 0, score = 0, response, restart = 50;
    string sc = to_string(score);
    char const *pchar = sc.c_str();
    bool play = true;
    int rainMen[] = {50, 150, 250, 350, 450, 550, 650};
    int speed[7] = {25};
    srand(time(NULL));
    a = rand() % 7 + 1;
    b = rand() % 7;

    man(SIZE, XSTART, YSTART);
    Mainscreen.showMenu(c);

    do
    {
        response = gfx_event_waiting();
        man(SIZE, x, y); // Make playable character

        if (response)
        {
            gfx_clear();
            c = gfx_wait();
            Mainscreen.showScore();
            gfx_text(347, 205, pchar);
            if (c == 'Q') // Move left
            {
                Mainscreen.showScore();
                gfx_text(347, 205, pchar);
                x -= 100;
                if (x < 0) // Off screen (left)
                {
                    // Gameover sequence
                    gfx_clear();
                    gfx_flush();
                    gfx_color(255, 255, 255);
                    gfx_text(350, 250, pchar);
                    man(SIZE, XSTART, YSTART); // Make playable character
                    Mainscreen.showGameover(c);
                    do
                    {
                        c = gfx_wait();
                        if (c == 32) // Spacebar
                        {
                            // Reset sequence
                            counter = 0;
                            score = 0;
                            sc = to_string(score);
                            pchar = sc.c_str();
                            for (int i = 0; i < 7; i++)
                            {
                                rainMen[i] = restart;
                                restart += 100;
                                speed[i] = 25;
                            }
                            x = 350;
                            y = 450;
                            restart = 50;
                            a = rand() % 7 + 1;
                            b = rand() % 7;
                            play = true;
                        }
                        if (c == 'q') // Exit program
                            play = false;
                    } while (c != 32 && c != 'q');
                }
                man(SIZE, x, y);
                // NPC speed randomizer sequence
                for (int i = 0; i < 7; i++)
                {
                    a = rand() % 7 + 1;
                    switch (a)
                    {
                    case 1:
                        speed[i] += 2;
                        break;
                    case 2:
                        speed[i] += 5;
                        break;
                    case 3:
                        speed[i] += 8;
                        break;
                    case 4:
                        speed[i] += 11;
                        break;
                    case 5:
                        speed[i] += 14;
                        break;
                    case 6:
                        speed[i] += 17;
                        break;
                    case 7:
                        speed[i] += 20;
                        break;
                    }
                    if (i == b) // Make escape route
                    {
                    }
                    else
                    {
                        if (collide(rainMen[i], speed[i], x, y) == true) // Check for collision
                        {
                            // Gameover sequence
                            gfx_clear();
                            gfx_flush();
                            gfx_color(255, 255, 255);
                            gfx_text(350, 250, pchar);
                            man(SIZE, XSTART, YSTART); // Make playable character
                            Mainscreen.showGameover(c);
                            do
                            {
                                c = gfx_wait();
                                if (c == 32) // Spacebar
                                {
                                    // Reset sequence
                                    counter = 0;
                                    score = 0;
                                    sc = to_string(score);
                                    pchar = sc.c_str();
                                    for (int i = 0; i < 7; i++)
                                    {
                                        rainMen[i] = restart;
                                        restart += 100;
                                        speed[i] = 25;
                                    }
                                    x = 350;
                                    y = 450;
                                    restart = 50;
                                    a = rand() % 7 + 1;
                                    b = rand() % 7;
                                    play = true;
                                }
                                if (c == 'q') // Exit program
                                    play = false;
                            } while (c != 32 && c != 'q');
                        }
                        rain_man(SIZE, rainMen[i], speed[i]); // Make NPCs
                    }
                }
            }
            else if (c == 'S') // Move right
            {
                Mainscreen.showScore();
                gfx_text(347, 205, pchar);
                x += 100;
                if (x > 700) // Off screen (right)
                {
                    // Gameover sequence
                    gfx_clear();
                    gfx_flush();
                    gfx_color(255, 255, 255);
                    gfx_text(350, 250, pchar);
                    man(SIZE, XSTART, YSTART); // Make playable character
                    Mainscreen.showGameover(c);
                    do
                    {
                        c = gfx_wait();
                        if (c == 32) // Spacebar
                        {
                            // Reset sequence
                            counter = 0;
                            score = 0;
                            sc = to_string(score);
                            pchar = sc.c_str();
                            for (int i = 0; i < 7; i++)
                            {
                                rainMen[i] = restart;
                                restart += 100;
                                speed[i] = 25;
                            }
                            x = 350;
                            y = 450;
                            restart = 50;
                            a = rand() % 7 + 1;
                            b = rand() % 7;
                            play = true;
                        }
                        if (c == 'q') // Exit program
                            play = false;
                    } while (c != 32 && c != 'q');
                }
                man(SIZE, x, y); // Make playable character
                // NPC speed randomizer sequence
                for (int i = 0; i < 7; i++)
                {
                    a = rand() % 7 + 1;
                    switch (a)
                    {
                    case 1:
                        speed[i] += 2;
                        break;
                    case 2:
                        speed[i] += 5;
                        break;
                    case 3:
                        speed[i] += 8;
                        break;
                    case 4:
                        speed[i] += 11;
                        break;
                    case 5:
                        speed[i] += 14;
                        break;
                    case 6:
                        speed[i] += 17;
                        break;
                    case 7:
                        speed[i] += 20;
                        break;
                    }
                    if (i == b) // Make escape route
                    {
                    }
                    else
                    {
                        if (collide(rainMen[i], speed[i], x, y) == true) // Check for collision
                        {
                            // Gameover sequence
                            gfx_clear();
                            gfx_flush();
                            gfx_color(255, 255, 255);
                            gfx_text(350, 250, pchar);
                            man(SIZE, XSTART, YSTART); // Make playable character
                            Mainscreen.showGameover(c);
                            do
                            {
                                c = gfx_wait();
                                if (c == 32) // Spacebar
                                {
                                    // Reset sequence
                                    counter = 0;
                                    score = 0;
                                    sc = to_string(score);
                                    pchar = sc.c_str();
                                    for (int i = 0; i < 7; i++)
                                    {
                                        rainMen[i] = restart;
                                        restart += 100;
                                        speed[i] = 25;
                                    }
                                    x = 350;
                                    y = 450;
                                    restart = 50;
                                    a = rand() % 7 + 1;
                                    b = rand() % 7;
                                    play = true;
                                }
                                if (c == 'q') // Exit program
                                    play = false;
                            } while (c != 32 && c != 'q');
                        }
                        rain_man(SIZE, rainMen[i], speed[i]); // Make NPCs
                    }
                }
            }
            else if (c == 'q') // Exit program
            {
                break;
            }
            usleep(delay);
        }
        else
        {
            gfx_clear();
            Mainscreen.showScore();
            gfx_text(347, 205, pchar);
            man(SIZE, x, y); // Make playable character
            // NPC speed randomizer sequence
            for (int i = 0; i < 7; i++)
            {
                a = rand() % 7 + 1;
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
                if (i == b) // Make escape route
                {
                }
                else
                {
                    if (collide(rainMen[i], speed[i], x, y) == true) // Check for collision
                    {
                        // Gameover sequence
                        gfx_clear();
                        gfx_flush();
                        gfx_color(255, 255, 255);
                        gfx_text(350, 250, pchar);
                        man(SIZE, XSTART, YSTART); // Make playable character
                        Mainscreen.showGameover(c);
                        do
                        {
                            c = gfx_wait();
                            if (c == 32) // Spacebar
                            {
                                // Reset sequence
                                counter = 0;
                                score = 0;
                                sc = to_string(score);
                                pchar = sc.c_str();
                                for (int i = 0; i < 7; i++)
                                {
                                    rainMen[i] = restart;
                                    restart += 100;
                                    speed[i] = 25;
                                }
                                x = 350;
                                y = 450;
                                restart = 50;
                                a = rand() % 7 + 1;
                                b = rand() % 7;
                                play = true;
                            }
                            if (c == 'q') // Exit program
                                play = false;
                        } while (c != 32 && c != 'q');
                    }
                    rain_man(SIZE, rainMen[i], speed[i]); // Make NPCs
                }
            }
            usleep(delay);
        }
    } while (play);
}

// Make playable character
void man(const int SIZE, int x, int y)
{
    gfx_color(0, 200, 200);
    gfx_fill_rectangle(x - 25, y - 25, SIZE, SIZE);
    gfx_fill_circle(x, y - 50, SIZE / 2);
}

// Make NPCs
void rain_man(const int SIZE, int x, int y)
{
    gfx_color(200, 100, 0);
    gfx_fill_rectangle(x - 25, y - 75, SIZE, SIZE);
    gfx_fill_circle(x, y, SIZE / 2);
}

// Check for collision
bool collide(int xa, int ya, int x, int y)
{
    if (x <= xa + RADIUS && x >= xa - RADIUS && y <= ya + RADIUS && y >= ya - RADIUS)
        return true;
    return false;
}
