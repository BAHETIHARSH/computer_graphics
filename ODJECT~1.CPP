
// C++ Implementation for drawing line
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>

// circle
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
void bresenham_circle(int Xc,int Yc,int R)
{
    int  D, X, Y;
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






//line dda
int round(float f)
{
    int rounded, k;
    k = int(f);
	if ((f - k) >= 0.5)
    {
	return k+1;
    }
    else
    {
	return k;
    };
}
void dda(int x1,int y1,int x2,int y2)
{
    int steps, dx, dy;
    float m, xin, yin;
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
    for (int i = 0; i < steps; i++)
    {
	x1 = x1 + xin;
	y1 = y1 + yin;
	putpixel(round(x1), round(y1), WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1,y1,r;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    cout << "Enter Coordinates of centre of circle : ";
    cin >> x1>> y1;
    cout << "Enter the Radius of Circle : ";
    cin >> r;
    bresenham_circle(x1, y1, r);
    bresenham_circle(x1,y1,r/2);
    dda(x1, y1-r,x1+sqrt(3)*r/2, y1+r/2);
    dda(x1, y1-r,x1-sqrt(3)*r/2, y1+r/2);
    dda(x1-sqrt(3)*r/2, y1+r/2,x1-sqrt(3)*r/2, y1+r/2);

    getch();
    closegraph();
    return 0;
}
