#include <stdio.h>

int main()
{
    int weight;
    int overweight_cost = 5;
    int fee;
    printf ("Calculate baggage fees (the first 20 kilos are FREE!)\nEnter the Total Weight of all carry-ons:\n");
    scanf ("%i",&weight);
    if (weight < 0) 
    {
        printf ("The weight: %i, can't be negative\nTry Again, Goodbye!\n", weight);
        return 0;
    }
    fee=((weight-20)*overweight_cost);
    if (fee < 0) 
    {
        fee = 0;
    }
    printf ("Weight: %i kilos\nFee: %i riyals\n",weight,fee);
    return 0;
}