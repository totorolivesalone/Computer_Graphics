#include<iostream>
#include<iomanip>
#include<graphics.h>
#include<stdio.h>
using namespace std;
void drawcircle(int x0,int y0,int r)
{
	int x=0;
	int y=r;
	int d=1-r;
	while(y>=x){
		putpixel(x0+x,y0+y,WHITE);
		putpixel(x0+y,y0+x,WHITE);
		putpixel(x0-y,y0+x,WHITE);
		putpixel(x0-x,y0+y,WHITE);
		putpixel(x0-x,y0-y,WHITE);
		putpixel(x0-y,y0-x,WHITE);
		putpixel(x0+y,y0-x,WHITE);
		putpixel(x0+x,y0-y,WHITE);
		if(d<=0){
			d+=2*x+3;
			x=x+1;
			
		}
		else
		{
			d+=2*(x-y)+5;
			x+=1;
			y-=1;
		
		}
	}
}
int main()
{
	int x,y,r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cout<<"**********Mid point Circle drawing Algorithm **********"<<endl;
	cout<<"Enter radius of circle"<<endl;
	cin>>r;
	cout<<"Enter center of circle coordinates:";
	cin>>x>>y;
	drawcircle(x,y,r);
	getch();
	
	return 0;
}

