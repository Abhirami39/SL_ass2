// calculate area and circumference of a circle given its radius 
//the value of pi should be stored as an float constant

//adding comment

#include<stdio.h>
main() {
	float radius;
    const float pi=3.14;
    
    printf("\n Enter the radius");
    
	float area= (pi *radius*radius);
	float circumference= 2.0*pi*radius;
	
	scanf("%f", &radius);
	printf("\n Area= %f" , area);
	printf("\n Circumference = %f", circumference);
}

