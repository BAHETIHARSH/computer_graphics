#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
class graphics
{
	int xc,yc,r;
    public:
    void coordinates()
    {
	cout << "enter the center co-ordinates " << endl;
	cin>>xc>>yc;
	cout<<"enter the radius  :"<<endl;
	cin>>r;
	circle();
	circle1();
	ddaline(xc-sqrt(3)/2*r,yc-r/2,xc+sqrt(3)/2*r,yc-r/2,13);
	ddaline(xc-sqrt(3)*r/2,yc-r/2,xc,yc+r,11);
	ddaline(xc+sqrt(3)*r/2,yc-r/2,xc,yc+r,1);
	}
    void circle();
	int round(float f);
    void ddaline(int x1,int y1,int x2,int y2,int color);

    void circle1();

};
int graphics::round(float f)
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
void graphics::circle()
{
    int d,x,y;

	x=0;
	y=r;
	d=3-2*r;
      while(x<y)
	{
	    putpixel(xc+x,yc-y,15);
	    putpixel(xc-x,yc+y,15);
	    putpixel(xc+y,yc+x,15);
	    putpixel(xc-y,yc-x,15);
	    putpixel(xc+y,yc-x,15);
	    putpixel(xc+x,yc+y,15);
	    putpixel(xc-x,yc-y,15);
	    putpixel(xc-y,yc+x,15);
	    if(d<=0)
		d=d+4*x+6;
	    else
	    {
		d=d+4*(x-y)+10;
		y=y-1;
	    }
	    x=x+1;
	    delay(100);
	}
}

void graphics::ddaline(int x1,int y1,int x2,int y2,int color)
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
void graphics::circle1()
{
    int x,y,d;
    x=0;
    y=r/2;
    d=3-r;
    while(x<y)
    {
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc+y,yc-x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc-y,yc-x,15);
	if(d<=0)
	d=d+4*x+6;

	else
	{
		d=d+4*(x-y)+10;
		y=y-1;
		}
		x=x+1;

	}
}
int main()
{       int gd=DETECT,gm;
	initgraph(&gd,&gm,"//turboc3//bgi");
	graphics obj;
	obj.coordinates();
	getch();
	closegraph();
      return 0;
}
