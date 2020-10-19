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
        ddaline(xc-sqrt(3)/2*r,yc-r/2,xc+sqrt(3)/2*r,yc-r/2);
        ddaline(xc,yc+r,xc-sqrt(3)/2*r,yc-r/2);
        ddaline(xc,yc+r,xc+sqrt(3)/2*r,yc-r/2);
	}
    void circle();

    void ddaline(int x1,int y1,int x2,int y2);

    void circle1();
    int round(float x);

};
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
void graphics::ddaline(int x1,int y1,int x2,int y2)
{
    int steps,i;
    float dx,dy,xinc,yinc,x,y;
    x=x1;
    y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
		else
		steps=abs(dy);
		xinc=dx/steps;
		yinc=dy/steps;
		for(i=0;i<steps;i++)
		{
			putpixel(round(x),round(y),15);
			x=x+xinc;
			y=y+yinc;
			delay(50);
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
int graphics::round(float x)
{
    int a;
    a=x+0.5;
    return a;
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
