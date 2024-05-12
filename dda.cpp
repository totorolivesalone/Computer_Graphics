#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
using namespace std;

	int main()
	{
	int i,steps,x1,x2,y1,y2,dx,dy;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cout<<"********** DDA Algorithm **********"<<endl;
	cout<<"\nEnter the value of x1: ";
	cin>>x1;
	cout<<"Enter the value of y1: ";
	cin>>y1;
	cout<<"Enter the value of x2: ";
	cin>>x2;
	cout<<"Enter the value of y2: ";
	cin>>y2;
	dx=x2-x1;
	cout<<"dx="<<dx<<endl;
	dy=y2-y1;
	
	cout<<"dy="<<dy<<endl;
	if(abs(dx)>abs(dy))
	{
	steps=abs(dx);
	}
	else
	{
	steps=abs(dy);
	}
	float xinc,yinc,X=x1,Y=y1; //xinc yinc are the incrementing factors present in dda , ie value of m
	cout<<"No. of iterations: "<<steps<<endl;
	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	for(i=0;i<steps;i++)
	{
	putpixel(round(X),round(Y),WHITE);
	X=X+xinc;
	Y=Y+yinc;
	}
	getch();
	closegraph();
	return 0;
	}

 
