#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void translation(int x,int y,int x_,int y_){
 x+=x_;
 y+=y_;
 

}
int main(){
    int gd=DETECT,gm,i;
    initgraph(&gd,&gm,NULL);
    rectangle(50,50,200,200);
    
    _getch();
    return 0;
}