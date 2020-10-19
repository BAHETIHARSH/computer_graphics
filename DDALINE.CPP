
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
        return k + 1;
    }
    else
    {
        return k;
    };
}
void dda(int x1, int y1, int x2, int y2)
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
    float x1, x2, y1, y2;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    cout << "Enter Coordinates of centre of circle : ";
    cin >> x1 >> y1;
    cout << "Enter Coordinates of centre of circle : ";
    cin >> x2 >> y2;

    dda( x1, y2, x1, y2);
    getch();
    closegraph();
    return 0;
}
