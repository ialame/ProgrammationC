#include <stdio.h>
#include <string.h>
#define MAX 50
typedef char mot[MAX] ;

int palindrome(mot m,p,q){
    if(q-p<=0)
        return 1;
    else{
        if(m[p]==m[q])
            return palindrome(m,p+1,q-1);
        else
            return 0;
    }
}

int main() {
    mot st1 = "laval";
    int p=0,q=strlen(st1)-1;
    if(palindrome(st1,p,q))
        printf("'%s' est un palindrome\n",st1);
    else
        printf("'%s' n'est un palindrome\n",st1);
    return 0;
}