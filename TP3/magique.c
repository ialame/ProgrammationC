#include <stdio.h>
#define MAX 50
typedef char mot[MAX] ;
typedef int matrice[MAX][MAX] ;
// Affichage de la matrice n x n
void afficheMatrice(matrice M,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n=3;
    // On initialise la matrice à 0
    matrice M={0};
    // On place (i,j) juste en dessous de la case centrale
    int i=n/2+1,j=n/2;
    for(int k=1;k<=n*n;k++){
        M[i][j]=k;
        // On passe à la case suivante au Sud-Est
        i=(i+1) % n;
        j=(j+1) % n;
        // Tant que la case (i,j) est occupée on se dirige vers le Sud-Ouest
        while(M[i][j]!=0 && k<n*n) {
            i=(i+1) % n;
            j=(j-1+n) % n;
        }
    }
    afficheMatrice(M,n);
    return 0;
}