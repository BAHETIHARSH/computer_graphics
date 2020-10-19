
// Harsh Balaprasad Baheti
// division :A
// roll no. 112
#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
//using namespace std;
// driver code
class shape
{public:
    shape()
    {
	int x1, y1, r;
	cout << "Enter Coordinates of centre of circle : ";
	cin >> x1 >> y1;
	cout << "Enter the Radius of Circle : ";
	cin >> r;
	int halfer;
	halfer = round(sqrt(3) * r / 2);
	dda(x1, y1 - r, round(x1 + halfer), round(y1 + r / 2));
	dda(x1, y1 - r, round(x1 - halfer), round(y1 + r / 2));
	dda(round(x1 + halfer), round(y1 + r / 2), round(x1 - halfer), round(y1 + r / 2));
	B_circle(x1, y1, r);
	B_circle(x1, y1, r / 2);
    }
    int round(float f)
    {
	int rounded, k;
	k = int(f);
	if ((f - k) >= 0.5)
	{
	    return k + 1;
	}
	else
	{
	    return k;
	};
    }
    void dda(int x1, int y1, int x2, int y2)
    {
	int steps;
	float m, xin, yin, dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dy) > abs(dx))
	{
	    steps = abs(dy);
	}
	else
	{
	    steps = abs(dx);
	};
	xin = dx / steps;
	yin = dy / steps;

	putpixel(x1, y1, WHITE);
	float a, b;
	a = x1;
	b = y1;
	for (int i = 0; i < steps; i++)
        {
            a = a + xin;
            b = b + yin;
            putpixel(round(a), round(b), WHITE);
            delay(50);
        }
    }
    void plotCircle(int xc, int yc, int x, int y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
    void B_circle(int Xc, int Yc, int R)
    {
        int D, X, Y;
        D = 3 - 2 * R;
        X = 0;
        Y = R;
        plotCircle(Xc, Yc, X, Y);
	while (X < Y)
        {
            if (D < 0)
            {
                D = D + 4 * X + 6;
                X = X + 1;
                Y = Y;
            }
            else
            {
                D = D + 4 * X - 4 * Y + 10;
                X = X + 1;
                Y = Y - 1;
            };

            plotCircle(Xc, Yc, X, Y);
        }
    }
};
int main()
{
    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the graphics systems
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    shape one;
    getch();

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();
    return 0;
}
