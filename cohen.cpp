#include<iostream.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int L=10 , T=100 , R=50 , B=200,x1=5 , y1=150 , x2=150, y2=150;
	int gd=DETECT,gm;
	cout<<"L=10 , T=100 , R=50 , B=200"<<endl;
	cout<<"x1=5 , y1=150 , x2=15 , y2=150"<<endl;
	int r=0,l=0,t=0,b=0;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	outtextxy(10,50,"Before clipping  :");
	rectangle(L,T,R,B);
	line(x1,y1,x2,y2);
	getch();
	cleardevice();

	//left
	if(L>x1 && (T<y1 && B>y1))
	{
		l=1;
	}
	//bottom
	if((L<x2 && R>x2)&& B<y2)
	{
		b=1;
	}
	//right
	if(R<x2 && (T<y2 && B >y2))
	{
		r=1;
	}
	//top
	if((L<x1 && R >x1)&& T>y1)
	{
		t=1;
	}
       //	cout<<"right="<<r<<endl;
       //	cout<<"top="<<t<<endl;
       //	cout<<"bottom="<<b<<endl;
       //	cout<<"left="<<l<<endl;
	outtextxy(10,50,"Before clipping  :");
	rectangle(L,T,R,B);

	if (l==1)
	{
		x1=L;
		//line(L,y1,x2,y2);
	       //	cout<<L<<","<<y1<<","<<x2<<","<<y2<<endl;
	}
	if(t==1)
	{
	       //	line(x1,T,x2,y2);
		y1=T;
	       //	cout<<x1<<","<<T<<","<<x2<<","<<y2<<endl;
	}
	if (r==1)
	{
		x2=R;
	       //	line(x1,y1,R,y2);
	       //	cout<<x1<<","<<y1<<","<<R<<","<<y2<<endl;
	}
	if(b==1)
	{
		y2=B;
	       //	line(x1,y1,x2,B);
	}
	line(x1,y1,x2,y2);
	getch();
	cleardevice();

	return 0;
}
