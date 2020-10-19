
// C++ Implementation for drawing line
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>
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
void ddaline(int x1,int y1,int x2,int y2,int color)
{int steps, dx, dy;
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

    putpixel(x1, y1, color);
    for (int i = 0; i < steps; i++)
    {
	x1 = x1 + xin;
	y1 = y1 + yin;
	putpixel(round(x1), round(y1), color);
    }
}
int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    int xc,yc,r;
    xc=100;
    yc=100;
    r=50;

    ddaline(round(xc-sqrt(3)*r/2),round(yc-r/2),round(xc+sqrt(3)/2*r),round(yc-r/2),13);
	ddaline(round(xc-sqrt(3)*r/2),round(yc-r/2),xc,round(yc+r),11);
	ddaline(round(xc+sqrt(3)*r/2),round(yc-r/2),xc,round(yc+r),1);
       //daline(200,200,100,100,15);
    getch();
    closegraph();
    return 0;
}
