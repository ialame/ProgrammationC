#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void binaire (int n){
    if(n>0){
        binaire(n>>1);
        printf ("%d", n % 2);
    }
}

/*
 * f50ca-c624510e3f-b9165fa7dd-e565163082-5cbc1c83d2-792ffe5669-972ff5bdb4-b64b831957-a05224cb47-712ab72740-33b1ca34ea-c1fa0424fe-a57c161365-0abff47134-2bc1827934-099d720352-9e485
 */
int main (void)
{
    int i;
    binaire(13);
    return (EXIT_SUCCESS);
}