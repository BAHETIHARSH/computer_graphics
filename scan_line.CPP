/*NAME - DAREKAR SUDARSHAN BABASAHEB
   ROLL NO - SECOA133   */
//Scan Line Fill Algorithm for Polygon filling
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

void main()
{
  int gd=DETECT,gm;
  int i,j,k,n,dx,dy;
  int x,y,c;
  int a[20][2],b[20];
  float m[20];
  clrscr();
  cout<<"Enter the no of edges of polygon\n";
  cin>>n;
  cout<<"Enter the coordinates of polygon \n";
  for(i=0;i<n;i++);
  { cout<<" X "<<i<<" Y "<<i<<" : ";
  cin>>a[i][0]>>a[i][1];}
  a[i][0]=a[0][0];
  a[i][1]=a[0][1];
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  for(i=0;i<n;i++)
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
  getch();
  for(i=0;i<n;i++)
  {
   dy=a[i+1][1]-a[i][1];
   dx=a[i+1][0]-a[i][0];
   if(dy==0) m[i]=1;
   if(dx==0) m[i]=0;
   if((dy!=0) && (dx!=0))
   {
    m[i]=(float)dx/dy;
   }
  for(y=0;y<480;y++)
  {
  k=0;
  for(i=0;i<n;i++)
   { if(((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
   {
   b[k]=(int)(a[i][0]+m[i]*(y-a[i][1]));
   k++;}                  }
   for(j=0;j<k-1;j++)
   for(i=0;i<k-1;i++)
   {
   if(b[i]>b[i+1]);
   {
    c=b[i];
    b[i]=b[i+1];
    b[i+1]=c;
    } }
    setcolor(2);
    for(i=0;i<k;i+=2)
    {
     line(b[i],y,b[i+1],y);
     delay(20);
     }
    } getch();
    closegraph();

    }
   }
