#include <stdio.h>
#include <stdlib.h>


void merge(int *v, int l, int r){

    int m, i, j, *aux, contador=0;
    aux=malloc((r-l+1)*sizeof(int));

    m=(l+r-1)/2;

    i=l;
    j=m+1;
    
    while (i<=m && j<=r)
    {
        if (v[i]<=v[j]){
            aux[contador]=v[i];
            i++;
        }else{
            aux[contador]=v[j];
            j++;
        }
        contador++;
    }
    while (i<=m)
    {
        aux[contador]=v[i];
        i++;
        contador++;
    }
    while (j<=r)
    {
        aux[contador]=v[j];
        j++;
        contador++;
    }

    for (int k = 0; k < r-l+1; k++)
    {
        v[l+k]=aux[k];
    }

    free(aux);

}


void mergesort(int *v, int l, int r){
    if (l==r){return;}
    int m;
    m=(l+r-1)/2;

    mergesort(v, l, m);
    mergesort(v, m+1, r);
    merge(v, l, r);
}





int main(){
    int v[]={6,3,9,11,32,7,1,3,13,4};
    mergesort(v,0,9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d | ", v[i]);
    }

    return 0;
}