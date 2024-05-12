#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;
 void lineBresenham(int,int,int,int);   // function prototype to draw a straight line using Bresenham's algorithm
 
 int main()
 
 {
     int x1,y1,x2,y2;  
     cout<<("Enter the points: ");
     cin>>x1>>y1>>x2>>y2;
     int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

     // marking the two-end points with circles
     circle(x1,y1,5);   
     circle(x2,y2,5);
    
     lineBresenham(x1,y1,x2,y2);  // function call to draw a straight line using Bresenham's algorithm
     
     getch();
     return 0;
}  // end of main

// function definition to draw a straight line using Bresenham's algorithm
void lineBresenham(int x1,int y1,int x2,int y2)
{
     int x,y,xInc,yInc,p,dx,dy,absDx,absDy;  // declaring variables
     // initializing variables and calculating some constants
     x=x1;
     y=y1;
     dx=x2-x1;
     dy=y2-y1;
     absDx=abs(dx);
     absDy=abs(dy);
     //case 1:m= undefined
     p=2*absDy-absDx;
     if(x1==x2 && y1==y2)  //same point
               putpixel(x1,y1,WHITE);  // plot the pixel with color 'color'
     else if(y1==y2)  // horizontal line case 2: m=0
     {
          // calculate xInc, y remains constant
          if(x1<x2)
             xInc=1;
          else
             xInc=-1;
          
          while(x!=x2)
          {
             putpixel(x,y,WHITE); // plot the pixel with color 'color'
             x+=xInc;   // change x
             
          } 
          putpixel(x,y,WHITE); // plot the pixel with color 'color'
     } 
     else if(x1==x2)  // vertical ,case 3:m=undefined 
     {
          // calculate yInc, x remains constant
          if(y1<y2)
             yInc=1;
          else
             yInc=-1;
          while(y!=y2)
          {
             putpixel(x,y,WHITE);  // plot the pixel with color 'color'
             y=y+yInc;   // change y
             
          } 
          putpixel(x,y,WHITE);
     } 
     else if(absDy<absDx) // gentle slope
     {
          // calculate xInc
          if(x1<x2)
            xInc=1;
          else
            xInc=-1;
          // calculate yInc
          if(y1<y2)
            yInc=1;
          else
            yInc=-1;
          
          
          while(x!=x2)
          {
              if(p>0) // move to NE, y changes
              {
                  p=p+2*absDy-2*absDx;
                  y+=yInc;
              }
              else   // move to E pixel
                  p=p+2*absDy;
              x+=xInc;
              putpixel(x,y,WHITE);  // plot the pixel with color 'color'
               // holding the present state for 1 milliseconds
          }   
     }
     else  // sharp
     {
          // calculate xInc
         if(x1<x2)
            xInc=1;
          else
            xInc=-1;
           // calculate yInc
          if(y1<y2)
            yInc=1;
          else
            yInc=-1;
            
            
          
          while(y!=y2)
          {
             if(p>0)  // x changes
             {
                p=p+2*absDx-2*absDy;
                x+=xInc;
             }
             else   // x remains same
                 p=p+2*absDx;
             y+=yInc;
                 // holding the present state for 1 milliseconds
             putpixel(x,y,WHITE);   // plot the pixel with color 'color'
          }       
     }
}  // end of function

