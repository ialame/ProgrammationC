#include <stdio.h>
typedef int Matrice[9][9];
void saisir(Matrice M,int n){
    int i = 0, j = 0;
    for( ; i < n; ++i)
        for( j = 0 ; j < n; ++j){
            printf("Donner valeur de case [%d,%d]= ",i+1,j+1);
            scanf("%d", &M[i][j]);
        }

}
void affiche(Matrice M,int n){
    int i = 0, j = 0;
    for( ; i < n; ++i, puts(""))
        for(j=0 ; j < n; ++j)
            printf("%d ", (M[i][j]));
}
void somme(Matrice A,Matrice B,Matrice C, int n){
    int i = 0, j = 0;
    for( ; i < n; ++i)
        for(j=0 ; j < n; ++j)
            C[i][j]=A[i][j]+B[i][j];
}
void produit(Matrice A,Matrice B,Matrice C, int n){
    int i = 0, j ,k;
    for( ; i < n; ++i)
        for(j=0 ; j < n; ++j){
            C[i][j]=0;
            for(k=0;k<n;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }

}
int main(void)
{
    int c;
    int n=2;
    Matrice A,B,M;
    do{
        do{
            printf("1) Saisir une matrice M.\n");
            printf("2) Afficher une matrice M.\n");
            printf("3) Sommer deux matrices.\n");
            printf("4) Multiplier deux matrices.\n");
            printf("0) Quitter.");
            printf("\nChoisir une action:");
            scanf("%d",&c);

        }while (c<0 && c>4);
        switch (c) {
            case 1:
                saisir(M,n);
                break;
            case 2:
                affiche(M,n);
                break;
            case 3:
                printf("Saisir la première matrice A:\n");
                saisir(A,n);
                printf("Saisir la deuxième matrice B:\n");
                saisir(B,n);
                somme(A,B,M,n);
                printf("La matrice somme M=:\n");
                affiche(M,n);
                break;
            case 4:
                printf("Saisir la première matrice A:\n");
                saisir(A,n);
                printf("Saisir la deuxième matrice B:\n");
                saisir(B,n);
                produit(A,B,M,n);
                printf("La matrice produit M=:\n");
                affiche(M,n);
                break;
            case 0:
                break;
        }
    }while (c!=0);
    return 0;
}
