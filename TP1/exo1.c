#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double monRand (void);

int main (void)
{
    int i;
    double x,y;
    int p=0;
    srand (time (NULL));

    for (i = 0; i<1000000; i++)
    {
        x=monRand ();y=monRand ();
        if(x*x+y*y<1)p++;

    }
    printf ("%f\n", 4*p/1000000.);
    return (EXIT_SUCCESS);
}
double monRand (void)
{
    return (rand ()/ (double)RAND_MAX);
}