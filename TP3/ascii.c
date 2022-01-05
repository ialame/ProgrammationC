#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum(char* chaine){
    int S=0;
    char *p =NULL;
    p=chaine;
    while(*p != '\0'){
        S = S + *p;
        p++;
    }
    return S;
}
int main(int argc, char *argv[]){
    char s[10];
    if(argc>1){
        strcpy(s,argv[1]);
    }else{
        printf("Saisir une chaine de caractère de taille <10:");
        scanf("%s",s);
    }
    printf("Somme=%d\n",sum(s));
    return 0;
}