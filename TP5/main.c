#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alphabet = " abcdefghijklmnopqrstuvwxyz";

long* diviseurs(long n) {
    long* d = (long *) malloc(sizeof(long));
    int k = 1;
    long i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            d[k - 1] = i;
            d = (long *) realloc(d, (k + 1) * sizeof(long));
            k = k + 1;
        }
        i = i + 1;
    }
    d[k - 1] = -1;
    return d;
}

int* nombresPremiers(int n){
    int* P=(int*) malloc(sizeof(int));
    P[0]=2;
    int dimP = 1;
    for(int i=3;i<n;i=i+2){
        int estPremier = 1;
        for(int k=0;k<dimP;k++) {
            int p = P[k];
            if (p * p > i) break;
            if (i % p == 0){
                estPremier = 0;
                break;
            }
        }
        if (estPremier){
            P=(int*) realloc(P,(dimP+1) * sizeof(int));
            P[dimP]=i;
            dimP++;
        }
    }
    P=(int*)realloc(P,(dimP+1)*sizeof(int));
    P[dimP]=-1;
    return P;
}

int ithPrime(int n){
    int* P=(int*) malloc(sizeof(int));
    P[0]=2;
    int dimP = 1, i=3;
    while(1){
        int estPremier = 1;
        for(int k=0;k<dimP;k++) {
            int p = P[k];
            if (p * p > i) break;
            if (i % p == 0){
                estPremier = 0;
                break;
            }
        }
        if (estPremier){
            P=(int*) realloc(P,(dimP+1) * sizeof(int));
            P[dimP]=i;
            dimP++;
            if (dimP==n){
                free(P);
                return i;
            }
        }
        i=i+2;
    }
}



int* numeration(n,base){
    int* B= (int*)malloc(sizeof(int));
    int k=0;
    while (n!=0){
        B[k] = n % base;
        n = n / base;
        k++;
        B = (int*) realloc(B,(k+1)*sizeof(int));
    }
    B[k]=-1;
    return B;
}


long puissance(long x, int n){
    int* d=numeration(n,2);
    long p = 1;
    long z = x;
    int i=0;
    while(d[i]!=-1){
        int k=d[i];
        if(k==1) p=p*z;
        z=z*z;
        i++;
    }
    return p;
}

long puissanceModulo(long x, int n,int m){
    int* d=numeration(n,2);
    long p = 1;
    long z = x % m;
    int i=0;
    while(d[i]!=-1){
        int k=d[i];
        if(k==1) p=p*z % m;
        z=z*z % m;
        i++;
    }
    return p;
}
char int2char(int n){
    return alphabet[n];
}

int char2int(char c){
    int n=strlen(alphabet);
    for(int i=0;i<n;i++){
        if (alphabet[i]==c) return i;
    }
    return -1;
}
int text2int(char* text){
    int s=0;
    int i=0;
    while (text[i]!='\0'){
        s+=char2int(text[i])*puissance(27,i);
        i=i+1;
    }
    return s;
}
char* int2text(int N){
    int* m = numeration(N,27);
    int k=0;
    while (m[k]!=-1) k++;
    char* text = (char*) malloc((k+1)*sizeof(char));
    int i=0;
    for (int i=0;i<k;i++){
        text[i]=int2char(m[i]);
    }
    return text;
}

char** split(char* s){
    if(s==NULL)
        return NULL;
    int n = strlen(s);
    int N=n/5+2;
    char** t = (char**) malloc(N*sizeof(char*));
    for(int i=0;i<N-1;i++){
        t[i] = (char*) malloc(6*sizeof(char));
        for(int j=0;j<5;j++)
            t[i][j]=s[5*i+j];
        t[i][6]='\n';
    }
    t[N-1] = (char*) malloc(4*sizeof(char));
    strcpy(t[N-1],"FIN");
    return t;
}

int main() {
    long p = ithPrime(4000);
    long q = ithPrime(5000);
    long N=p*q;
    printf("%d\n",N);
    long K=3*(p-1)*(q-1)+1;
    long* D=diviseurs(K);
    long alpha = D[0];
    long beta = K/D[0];
    char* message = "salut";
    int M=text2int(message);
    printf("Message num??ris??: ( %s => %d )\n",message,M);
    int Mc = puissanceModulo(M,alpha,N);
    printf("Message num??rique crypt??: ( %d => %d )\n",M, Mc);
    printf("Message alphab??tique crypt??: ( %d = %s )\n",Mc,int2text(Mc) );
    int Md = puissanceModulo(Mc,beta,N);
    printf("Message num??rique d??crypt??: ( %d => %d = %s )\n",Mc, Md,int2text(Md));
    free(D);
    return 0;
}
