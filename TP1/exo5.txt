#include <stdio.h>
#define Nmax 10
typedef int Matrice[Nmax][Nmax];
void affiche(Matrice M,int n,int p){
    int i = 0, j = 0;
    for( ; i < n; ++i, puts(""))
        for(j=0 ; j < p; ++j)
            printf("%d ", (M[i][j]));
}
int main(void)
{
    int i = 0, j = 0;
    Matrice pascal = {0};
    pascal[0][0]=1;
    for(i=1;i<5;i++)
    { 	pascal[i][0]=1;
        for(j=1;j<i;j++)
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        pascal[i][i]=1;
    }
    affiche(pascal,5,5);
    return 0;
}