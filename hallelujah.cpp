/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: hallelujah.cpp
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

#include "raining_man.h"

void man(const int, int, int);
void raining_man(const int, int, int);
void menu(char);
void gameover(char);
void scoresheet();
bool collide(int, int, int, int);

int main()
{
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
    // Rainman man1(50);
    // Rainman man1, man2(150), man3(250), man4(350), man5(450), man6(550), man7(650);

    gfx_open(XSIZE, YSIZE, "It's Raining Men!"); // Open a new window for drawing.
    gfx_color(200, 200, 0);

    menu(c);

    do
    {
        response = gfx_event_waiting();
        man(SIZE, x, y); // Make watch

        if (response)
        {
            gfx_clear();
            c = gfx_wait();
            scoresheet();
            gfx_color(255, 255, 255);
            gfx_text(340, 180, "Score");
            gfx_text(350, 200, pchar);
            if (c == 'Q') // On left click, change direction of hand
            {
                scoresheet();
                gfx_color(255, 255, 255);
                gfx_text(340, 180, "Score");
                gfx_text(350, 200, pchar);
                x -= 100;
                if (x < 0)
                {
                    gfx_clear();
                    gfx_flush();
                    gfx_color(255, 255, 255);
                    gfx_text(240, 225, "Score");
                    gfx_text(240, 250, pchar);
                    gameover(c);
                    do
                    {
                        c = gfx_wait();
                        if (c == 32)
                        {
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
                        if (c == 'q')
                            play = false;
                    } while (c != 32 && c != 'q');
                }
                man(SIZE, x, y);
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
                    if (i == b)
                    {
                    }
                    else
                    {
                        if (collide(rainMen[i], speed[i], x, y) == true)
                        {
                            gfx_clear();
                            gfx_flush();
                            gfx_color(255, 255, 255);
                            gfx_text(240, 225, "Score");
                            gfx_text(240, 250, pchar);
                            gameover(c);
                            do
                            {
                                c = gfx_wait();
                                if (c == 32)
                                {
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
                                if (c == 'q')
                                    play = false;
                            } while (c != 32 && c != 'q');
                        }
                        raining_man(SIZE, rainMen[i], speed[i]);
                    }
                }
            }
            else if (c == 'S')
            {
                scoresheet();
                gfx_color(255, 255, 255);
                gfx_text(340, 180, "Score");
                gfx_text(350, 200, pchar);
                x += 100;
                if (x > 700)
                {
                    gfx_clear();
                    gfx_flush();
                    gfx_color(255, 255, 255);
                    gfx_text(240, 225, "Score");
                    gfx_text(240, 250, pchar);
                    gameover(c);
                    do
                    {
                        c = gfx_wait();
                        if (c == 32)
                        {
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
                        if (c == 'q')
                            play = false;
                    } while (c != 32 && c != 'q');
                }
                man(SIZE, x, y);
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
                    if (i == b)
                    {
                    }
                    else
                    {
                        if (collide(rainMen[i], speed[i], x, y) == true)
                        {
                            gfx_clear();
                            gfx_flush();
                            gfx_color(255, 255, 255);
                            gfx_text(240, 225, "Score");
                            gfx_text(240, 250, pchar);
                            gameover(c);
                            do
                            {
                                c = gfx_wait();
                                if (c == 32)
                                {
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
                                if (c == 'q')
                                    play = false;
                            } while (c != 32 && c != 'q');
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
            scoresheet();
            gfx_color(255, 255, 255);
            gfx_text(340, 180, "Score");
            gfx_text(350, 200, pchar);
            man(SIZE, x, y); // Make watch
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
                if (i == b)
                {
                }
                else
                {
                    if (collide(rainMen[i], speed[i], x, y) == true)
                    {
                        gfx_clear();
                        gfx_flush();
                        gfx_color(255, 255, 255);
                        gfx_text(240, 225, "Score");
                        gfx_text(240, 250, pchar);
                        gameover(c);
                        do
                        {
                            c = gfx_wait();
                            if (c == 32)
                            {
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
                            if (c == 'q')
                                play = false;
                        } while (c != 32 && c != 'q');
                    }
                    raining_man(SIZE, rainMen[i], speed[i]);
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

// Make raining men
void raining_man(const int SIZE, int x, int y)
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

// Display starting menu
void menu(char c)
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
    man(SIZE, XSTART, YSTART); // Make watch

    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

// Display gameover screen
void gameover(char c)
{
    gfx_color(255, 255, 255);
    gfx_rectangle(125, 125, 450, 200);
    gfx_color(200, 200, 0);
    gfx_rectangle(150, 150, 400, 150);
    gfx_color(255, 0, 0);
    gfx_text(200, 200, "Gameover! Press spacebar twice to restart");
    man(SIZE, XSTART, YSTART); // Make watch

    c = gfx_wait();
    gfx_flush();

    if (c == 'q')
    {
        exit(0);
    }
}

// Display score styling
void scoresheet()
{
    gfx_color(200, 200, 0);
    gfx_circle(350, 190, 40);
    gfx_color(0, 255, 0);
    gfx_circle(350, 190, 50);
}
