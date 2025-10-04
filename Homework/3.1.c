#include<stdio.h>

int main () {
    float h,w;

    printf("Enter H & W : ");
    scanf("%f %f",&h,&w);

    printf("%.1f",(h*w)/2);
}
