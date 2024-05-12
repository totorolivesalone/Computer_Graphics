#include <iostream> 
#include <stdio.h> 
#include <graphics.h>
using namespace std; 
struct point 
{ 
int x,y; 
}; 
void hermite(point p1,point p4,double r1,double r4) 
{ 
float x,y,t; 
for(t=0.0; t<=1.0; t+=0.001) 
{ 
x = (2*t*t*t-3*t*t+1)*p1.x + (-2*t*t*t+3*t*t)*p4.x + (t*t*t-2*t*t+t)*r1 + (t*t*t-t*t)*r4; 
y = (2*t*t*t-3*t*t+1)*p1.y + (-2*t*t*t+3*t*t)*p4.y + (t*t*t-2*t*t+1)*r1 + (t*t*t-t*t)*r4; 
putpixel(x,y,YELLOW); 
} 
} 
int main() 
{ 
int gd=DETECT, gm, errorcode; 
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
cout<<"********** Hermite Curve **********"<<endl; 
errorcode = graphresult(); 
if(errorcode != grOk) 
{ 
cout<<"Graphics error: "<<grapherrormsg(errorcode); 
cout<<"Press any key to halt:"; 
getch(); 
exit(1); 
} 
double r1,r4; 
point p1,p2; 
cout<<"Enter 2 hermite points : "; 
cin>>p1.x>>p1.y>>p2.x>>p2.y; 
cout<<"\nEnter tangents at p1 and p4 : "; 
cin>>r1>>r4; 
hermite(p1,p2,r1,r4); 
putpixel(p1.x,p1.y,WHITE); 
putpixel(p2.x,p2.y,WHITE); 
getch(); 
closegraph();
return 0; 
} 

