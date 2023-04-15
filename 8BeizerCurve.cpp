#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
// Cordinates
//  300 300 400 450 
// 500 100 600 300
void bezier_curve(int x[4], int y[4])
{
     /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, NULL);

    double t;
    for(t=0.0;t < 1.0;t+=0.0005)
    {
        double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        putpixel(xt,yt,WHITE);
    }
    for(int i=0;i < 4;i++)
        putpixel(x[i],y[i],YELLOW);
    
    delay(5000);
    closegraph();
}


int main()
{

    int x1,y1,x2,y2,n;
    double t1,t4;

    int x[4],y[4];
    int i;
   
        cout<<"Enter x and y coordinates\n";
        for(i=0;i<4;i++)
        {
            cout<<"x"<<i+1<<":";
            cin>>x[i];
            cout<<"y"<<i+1<<":";
            cin>>y[i];
            cout<<endl;
        }
        bezier_curve(x,y);
    
    return 0;
}