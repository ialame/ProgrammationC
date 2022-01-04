#include <stdio.h>

int main(void)
{
    char c;
    int n=2;
    int N= 512;
    int x=N;
    int b;
    while(N>0) {
        printf("N=%d\n",N);
        printf("Votre nombre est strictement supérieur à %d (o/n)", x);
        scanf("%c",&c);
        b = 'o' == c;
        c=getchar();
        N = N / 2;
        if (b) {
            x += N;
        } else
            x -= N;
    }
    if(b)
        printf("Votre nombre est %d", x + 1 );
    else
        printf("Votre nombre est %d",x );
    return 0;
}
