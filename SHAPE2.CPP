
// Harsh Balaprasad Baheti
// division :A
// roll no. 112
#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
//using namespace std;

class shape
{
public:
    shape()
    {
        int x1, y1, l, w;
        cout << "Enter the value of X and Y : ";
        cin >> x1 >> y1;
        cout << "Enter the length and width of reactangle : ";
	cin >> l >> w;

	dda(x1, y1, x1 + l, y1);
	dda(x1, y1, x1, y1 + w);
	dda(x1 + l, y1 + w, x1 + l, y1);
	dda(x1 + l, y1 + w, x1, y1 + w);

	dda(x1+l/2, y1, x1 , y1+w/2);
	dda(x1, y1+w/2, x1+l/2, y1 + w);
	dda(x1 + l/2, y1 + w, x1 + l, y1+w/2);
	dda(x1 + l, y1 + w/2, x1+l/2, y1 );			

	B_circle(x1+l/2,y1+w/2,l*w/(sqrt(w*w+l*l)*2));
    }

private:
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
	   // delay(50);
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
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    shape two;
    getch();
    closegraph();
    return 0;
}
