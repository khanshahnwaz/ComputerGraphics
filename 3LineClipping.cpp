#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
using namespace std;
// define window size
    int x_min=50;
    int x_max=400;
    int y_min=50;
    int y_max=400;
void inputWindowSize(int* x_min, int* y_min, int* x_max, int* y_max){
    cout<<"Enter x_min: ";
    cin>>*x_min;
    cout<<"\nEnter y_min: ";
    cin>>*y_min;
    cout<<"\nEnter x_max: ";
    cin>>*x_max;
    cout<<"\nEnter y_max: ";
    cin>>*y_max;
    
 }

void inputLine(double& x1, double& x2, double& y1, double& y2){
    cout<<"\nEnter cordinates for line.\n\n";
    cout<<"Enter x1: ";
    cin>>x1;
    cout<<"\nEnter y1: ";
    cin>>y1;
    cout<<"\nEnter x2: ";
    cin>>x2;
    cout<<"\nEnter y2: ";
    cin>>y2;

}
int computeRegion(int x,int y , int x_min, int x_max, int y_min, int y_max){
    // TBRL  CODE
    int code=0;
    if(x<x_min)  // x < x_min
      code= 1;//0001;  //LEFT
    else if(x>x_max)   // x > x_max
       code=2;//0010;  // RIGHT
    else if(y<y_min)  // y < y_min
       code=4;//0100;  // BOTTOM
    else code=8;//1000;  // y > y_max  TOP
  
   return code;
}

void cohenSutherland(int code1, int code2 ,double x1,double y1, double x2, double y2, int x_min, int x_max, int y_min, int y_max){

    int code;
    double x,y;
    if(code1==0 && code2==0){
        cout<<"Line completely visible. Accepted! ";
    }else if(code1 & code2){
        cout<< (code1 & code2);
        // If not 0000 means line is completely invisible 
        cout<<"Line completely invisile. Rejected! ";
    }else{
        // Line partially visible
        // check which code is outside
        cout<<"Line partially visible. \n";
        if(code2 !=0 ) 
           code=code2;
        else code=code1;

        if(code==8){
            x=x1 + (x2-x1) * (y_max-y1)/(y2-y1);
            y=y_max; 
        }else if(code==4){
            x=x1+(x2-x1) * (y_min-y1)/ (y2-y1);
            y=y_min;
        } else if(code=2){
            y=y1+(y2-y1) * (x_max-x1)/(x2-x1);
            x=x_max;
        }else{
            y=y1+(y2-y1) * (x_min-x1)/(x2-x1);
            x=x_min;
        }
  
         //   Assign new co-ordinates
        if(code==code1){
            x1=x;
            y1=y;
        }else{
            x2=x;
            y2=y;
        }

        cout<<"Line accepted from (x1,y1):"<<x1<<","<<y1<<" and (x2,y2):"<<x2<<","<<y2;
        clearviewport();
        rectangle(x_min,y_min,y_max,x_max);
        line(x1,y1,x2,y2);
        // line(130,130,200,200);
    }

}
int main(){

    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    int gd = DETECT, gm, i;    /* request autodetection */
    initgraph(&gd, &gm, NULL); /* initialize graphics mode */

    
    // int x_min,y_min,x_max,y_max;
    // inputWindowSize(&x_min,&y_min,&x_max,&y_max);
    rectangle(x_min,y_min,y_max,x_max);
    delay(3000);
    // define both endpoints of line
    double x2=450;
    double y2=450;
    double x1=200;
    double y1=200;
    // double x1,y1,x2,y2;
    // inputLine(x1,y1,x2,y2);
    setcolor(GREEN);
    line(x1,y1,x2,y2);
    setcolor(WHITE);
    delay(2000);
    // now find the region code for both the endpoints
    int code1=computeRegion(x1,y1, x_min, x_max, y_min, y_max);
    int code2=computeRegion(x2,y2, x_min, x_max, y_min, y_max);
    cout<<"Code1:"<<code1<<" and Code2: "<<code2 << endl;
    // Cohen sutherland algorithm 
    cohenSutherland(code1,code2 ,x1,y1, x2, y2, x_min, x_max, y_min, y_max);
    _getch();
    return 0;
}