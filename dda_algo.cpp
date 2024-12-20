#include <graphics.h>
#include<iostream.h>
#include <math.h>
#include <stdio.h>
#include<conio.h>

class shape
{
	public:

	void dda(int a,int b,int c,int d)
	{

	int i,lenght,x,y,x1=a,x2=c,y1=b,y2=d,dx,dy;
	dx=(x2-x1);
	dy=(y2-y1);
	if(dx>=dy)
	{
		lenght=dx;
	}
	else
	{
		lenght=dy;
	}
	dx=(x2-x1)/lenght;
	dy=(y2-y1)/lenght;
	x=x1;
	y=y1;
	for(i=1;i<=lenght+1;i++)
	{
		putpixel(x,y,WHITE);
		x=x+dx;
		y=y+dy;
	}
	}

	//breshenhams
void drawbr(int xc, int yc, int r) {
	int x = 0, y = r;
	int d = 3 - 2 * r;

	while (x <= y) {
	    putpixel(xc + x, yc + y, WHITE);
	    putpixel(xc - x, yc + y, WHITE);
	    putpixel(xc + x, yc - y, WHITE);
	    putpixel(xc - x, yc - y, WHITE);
	    putpixel(xc + y, yc + x, WHITE);
	    putpixel(xc - y, yc + x, WHITE);
	    putpixel(xc + y, yc - x, WHITE);
	    putpixel(xc - y, yc - x, WHITE);

	    if (d < 0) {
		d += 4 * x + 6;
	    } else {
		d += 4 * (x - y) + 10;
		y--;
	    }
	    x++;
	}
    }
};



int main()
{
int gd = DETECT, gm;
//Initialize graphics function
initgraph(&gd, &gm, "C://TURBOC3//BGI");


shape obj;
obj.dda(200,300,400,300);
obj.dda(200,300,300,200);
obj.dda(300,200,400,300);
obj.drawbr(300,260,40);
obj.drawbr(300,287,100);

getch();
closegraph();
return 0;
}

