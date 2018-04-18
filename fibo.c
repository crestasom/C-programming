#include <stdio.h>
void main(){
double a=0.0,b=1.0,c=0;
int x=100;
for(int i=0;i<x;i++){
c=a+b;
printf("\n%d\t%lf",i,c);
a=b;
b=c;
}
getch();
}
