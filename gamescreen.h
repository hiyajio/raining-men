/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: gamescreen.h
 * Description: Class interface for Gamescreen class
 */
#define RADIUS 60
#define SZSTART 50
#define XSIZE 700
#define YSIZE 500
#define XSTART 350
#define YSTART 450
const int SIZE = 50;

// Class interface of Gamescreen
class Gamescreen
{
public:
    Gamescreen();
    ~Gamescreen();
    void showMenu(char c);
    void showGameover(char c);
    void showScore();
};
