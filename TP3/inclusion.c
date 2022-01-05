#include <stdio.h>
#define MAX 50
typedef char mot[MAX] ;
int len(mot m){
    int i=0;
    while(m[i])i++;
    return i;
}
int in(char c,mot m){
    int i=0;
    while(m[i]){
        if(c==m[i])
            return i;
        i++;
    }
    return -1;
}
int issubset(mot st1,mot st2){
    if (st1=='\0'){
        return 1;
    }else
    if (in(st1[0],st2)!=-1){
        return issubset(st1+1,st2);
    }else
        return 0;
}

int main() {
    mot st1 = "adlounks";
    mot st2 = "pkaodluoumn";
    if(issubset(st1,st2))
        printf("'%s' est inclus dans '%s'\n",st1,st2);
    else
        printf("'%s' n'est pas inclus dans '%s'\n",st1,st2);
    return 0;
}