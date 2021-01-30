#include <stdio.h>
#include <math.h>

int main()
{
    int radius;
    float sphere_volume;
    float pi = (3.14159);
    
    printf ("Lets Calculate the volume of a sphere!\nEnter a radius:\n");
    scanf ("%i",&radius);

    sphere_volume=((4/3)*pi)*(pow(radius,3));
    printf ("\nsphere volume is: %f\n",sphere_volume);   
}