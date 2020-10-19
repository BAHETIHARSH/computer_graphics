#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
class point
{
public:
    int x, y;
};
void draw_window(point A, point B)
{
    line(A.x, A.y, A.x, B.y);
    line(A.x, B.y, B.x, B.y);
    line(B.x, B.y, B.x, A.y);
    line(B.x, A.y, A.x, A.y);
}
void draw_line(point D, point E)
{
    line(D.x, D.y, E.x, E.y);
}
unsigned char encode(point Z,point wlower,point wupper){
    unsigned char code=0x0;
    if(Z.x < wlower.x)
	    code = 0x1;
    if(Z.x > wupper.x)
	    code = 0x2;
    if(Z.y < wlower.y)
	    code = 0x4;
    if(Z.y > wlower.y)
	    code = 0x8;
    return code;
}
int clipping(point winlower,point winupper,point p1,point p2,point* mp1,point* mp2){
    unsigned char c1,c2;
    int ac = 0;
    int done = 0;
    float m = 0;
    while (!done)
    {
	c1=encode(p1,winlower,winupper);
	c2=encode(p2,winlower,winupper);
	if(!(c1|c2)){
	    done = 1;
	    ac = 1;
	}
	else if (c1&c2)
	{
	    done = 1;
	}
	else
	{
	    m = (float)(p2.y-p1.y)/(p2.x-p1.x);
	    if(c1 == 0x1)
	    {
		p1.y += (winlower.x-p1.x)*m;
		p1.x = winlower.x;
	    }
	    else if(c1 == 0x2)
	    {
		p1.y += (winupper.x-p1.x)*m;
		p1.x = winupper.x;
	    }
	    else if(c1 == 0x4)
	    {
		p1.x += (winlower.y-p1.y)/m;
		p1.y = winlower.y;
	    }
	    else if(c1 == 0x8)
	    {
		p1.x += (winupper.y-p1.y)/m;
		p1.y = winupper.y;
	    }
	     if(c2 == 0x1)
	     {
		p2.y = p1.y + (winlower.x-p1.x)*m;
		p2.x = winlower.x;
	     }
	    else if(c2 == 0x2)
			{
				p2.y = p1.y +(winupper.x-p1.x)*m;
				p2.x = winupper.x;
	    }
	     else if(c2 == 0x4)
	     {
		 p2.x = p1.x+(winlower.y-p1.y)/m;
		 p2.y = winlower.y;
	     }
	     else if(c2 == 0x8)
	     {
		 p2.x = p1.x+ (winupper.y-p1.y)/m;
		 p2.y = winupper.y;
	     }

	}

    }
    mp1->x=p1.x;
	mp1->y=p1.y;
	mp2->x=p2.x;
	mp2->y=p2.y;
    return ac;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    point winlower, winupper;
    point p1, p2;
    point mp1, mp2;
    cout << "Enter the Co ordinate of winlower'x  and winlower'y : ";
    cin >> winlower.x >> winlower.y;
    cout << "Enter the Co ordinate of winupper'x  and winupper'y : ";
    cin >> winupper.x >> winupper.y;
    cout << "Enter the Co ordinate of X1  and Y1 : ";
    cin >> p1.x >> p1.y;
    cout << "Enter the Co ordinate of X2  and Y2 : ";
    cin >> p2.x >> p2.y;
    mp1.x = p1.x;
    mp1.y = p1.y;
    mp2.x = p2.x;
    mp2.y = p2.y;
    cleardevice();
    draw_window(winlower, winupper);
    draw_line(p1, p2);
    delay(5000);
    cleardevice();
    int condition = 0;
    condition = clipping(winlower,winupper,p1,p2,&mp1,&mp2);
    if (condition == 0){
        draw_window(winlower, winupper);
        }
    else
    {
    draw_window(winlower, winupper);
    draw_line(mp1, mp2);
    }
       
    getch();
    return 0;
}