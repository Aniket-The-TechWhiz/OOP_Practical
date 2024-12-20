#include <graphics.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
void scanfill(int x, int y, int o_col, int n_col) 
{
 int current = getpixel(x, y);
 if (current == o_col)
{
 delay(5);
 putpixel(x, y, n_col);
 scanfill(x + 1, y, o_col, n_col);
 scanfill(x - 1, y, o_col, n_col);
 scanfill(x, y + 1, o_col, n_col);
 scanfill(x, y - 1, o_col, n_col);
 }
}
int main()
{
 int x1, y1, x2, y2, x3, y3, xaverage, yaverage;
 int gdriver = DETECT, gmode;
 cout << "Enter the points of the triangle (x1 y1 x2 y2 x3 y3): ";
 cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 initgraph(&gdriver, &gmode, NULL);
 
 setcolor(WHITE); // Set color for the triangle outline
 line(x1, y1, x2, y2);
 line(x2, y2, x3, y3);
 line(x3, y3, x1, y1);
 // Calculate the average point
 xaverage = (x1 + x2 + x3) / 3;
 yaverage = (y1 + y2 + y3) / 3;
 // Fill color: make sure the background color is set correctly
 scanfill(xaverage, yaverage, getbkcolor(), WHITE);
 getch();
 closegraph();
 return 0;
}
