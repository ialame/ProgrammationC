#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n;
    if(argc>1)
        n=atoi(argv[1]);
    else{
        printf("Donner le nombre de secondes:");
        scanf("%d",&n);
    }
    n=n%(24*3600);// n est le nombre des secondes dans une journée
    int s=n%60;
    n=n/60;
    int m=n%60;
    n=n/60;
    if(n<10)
        printf("0");
    printf("%d:",n);
    if(m<10)
        printf("0");
    printf("%d:",m);
    if(s<10)
        printf("0");
    printf("%d\n",s);
    return 0;
}