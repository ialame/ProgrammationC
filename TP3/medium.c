#include <stdio.h>
#include <limits.h>

void permute(int t[],int i,int j){
    int a=t[i];
    t[i]=t[j];
    t[j]=a;
}
int main(){
    int t[]={2,7,4,8,9,1,11,20,15,10,5};
    int n=sizeof(t)/sizeof(1);
    int i=0;int p=0,q=n-1;
    while (p<q){
        // On cherche le max M et le min m du tableau entre l indice p et l'indice q
        int M=INT_MIN,m=INT_MAX,im=-1,iM=-1;
        for(int i=p;i<=q;i++){
            if(t[i]<m){
                im=i;
                m=t[i];
            }
            if(t[i]>M){
                iM=i;
                M=t[i];
            }
        }
        // On place les valeurs min et max aux extrémités d'indices p et q
        // Pour permuter les valeurs il faut distinguer 3 cas:
        if(iM==p && im==q){
            permute(t,p,q);
        }else if(iM==p){
            permute(t,iM,q);
            permute(t,im,p);
        }else{
            permute(t,im,p);
            permute(t,iM,q);
        }
        p++;q--;
    }
    for(i=0;i<n;i++)
        printf("%d ",t[i]);
    printf("\nMédium=%d\n",t[n/2]);
    return 0;
}

