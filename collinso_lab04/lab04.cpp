/*
 *  Orion Collins 
 *  Lab04: series math
 */

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n,x = 0;
    float sum;
    // check for correct numbers of args if not then prompt user for n
    if (argc != 2) {
        printf ("Please enter a value for n: ");
        scanf ("%i",&n);
    }
    else {
        n = atoi(argv[1]);
    }

    //Loop over each series, find the sum of that iteration then add its sqrt to the sum
    for (int i=1; i <= n; i++) {
        x = 0; //inSum
        for (int j = 1; j <= i; j++) {
            x += j;
        }
        sum += sqrt(x);
    }
    printf("The sum is %f\n",sum);
}
