#include <stdio.h>
#include <stdlib.h>
typedef struct monome{
    int coeff;
    int exp;
    struct monome *suivant;
} Monome;

typedef struct{
    Monome *premier;
} Polynome;

/* Construction d'un nouveau Monome aX^n dont le suivant est NULL*/
Monome* newMonome()
{
    Monome *m =(Monome*) malloc(sizeof(*m));
    if (m == NULL) exit(EXIT_FAILURE);

    // Saisir m->coeff et m->exp
    printf("coefficient: ");scanf("%d",&m->coeff);
    printf("Exposant: ");scanf("%d",&m->exp);
    m->suivant = NULL;

    return m;
}

// constructeur d'un nouveau polynome nul
Polynome *newPolynome()
{
    // Allocation memoire d'un polynome et de son premier terme
    Polynome *polynome =(Polynome*) malloc(sizeof(Polynome));
    Monome *m =(Monome*) malloc(sizeof(*m));

    if (polynome == NULL || m == NULL) exit(EXIT_FAILURE);
    // Un polynôme nul doit contenir le monome 0X^0
    m->coeff = 0;
    m->exp = 0;
    m->suivant = NULL;
    // m est le premier terme du polynome
    polynome->premier = m;

    return polynome;
}
// Création et insertion d'un monome dans le polynôme
void insertion(Polynome *polynome)
{
    /* Création d'un nouveau terme */
    Monome *m = newMonome();
    if (polynome == NULL || m == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Insertion du monome au début de la liste polynomiale */
    m->suivant = polynome->premier;
    polynome->premier = m;
}

void suppression(Polynome *p)
{
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (p->premier != NULL)
    {
        Monome *aSupprimer = p->premier;
        p->premier = p->premier->suivant;
        free(aSupprimer);
    }

}

void destruction(Polynome *p)
{
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (p->premier != NULL)
    {
        Monome *aSupprimer = p->premier;
        p->premier = p->premier->suivant;
        free(aSupprimer);
    }
}
void afficher(Polynome *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Monome *actuel = liste->premier;

    while (actuel != NULL)
    {
        if(actuel->coeff!=0)
            printf("+%dX^%d ", actuel->coeff,actuel->exp);
        actuel = actuel->suivant;
    }
    printf("\n");
}

int power(int x,int n){
    if(n==0)
        return 1;
    int y=power(x,n/2);
    if(n%2==0)
        return y*y;
    else
        return y*y*x;
}
int valeurPolynome(Polynome* p,int x){
    int S=0;
    Monome* m = p->premier;
    S=m->coeff;
    while (m->suivant!=NULL){
        m=m->suivant;
        S=S*x+m->coeff;

    }


    return S;
}
int main() {
    //printf("%d\n",power(10,5));

    Polynome *p = newPolynome();
    insertion(p);
    insertion(p);
    insertion(p);
    afficher(p);
    printf("%d\n",valeurPolynome(p,2));
    //suppression(p);
    //afficher(p);
    destruction(p);
    free(p);
    printf("Fin!\n");

    return 0;
}
