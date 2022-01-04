#include <stdlib.h>
#include <stdio.h>

void binaire (int n){
    if(n>0){
        binaire(n>>1);
        printf ("%d", n % 2);
    }
}

int main (void)
{
    int i;
    binaire(13);
    return (EXIT_SUCCESS);
}