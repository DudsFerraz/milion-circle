#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int appendToVet(int vet[], int *len, int value){
    vet[(*len)++]=value;
    return value;
}

int removeIndexFromVet(int vet[], int *len, int index){
    int eliminado = vet[index];
    for(int i=index;i<*len-1;i++){
        vet[i]=vet[i+1];
    }
    (*len)--;
    return eliminado;
}

int main(){
    int n, x, xEsimo, eliminado, nEliminados=0, lenVetor=0, indexProxEliminado=1;

    printf("Número de partcicpantes:");
    scanf("%d",&n);
    int vetor[n];
    printf("X:");
    scanf("%d",&x);

    for(int i=1;i<=n;i++){
        appendToVet(vetor,&lenVetor,i);
    }

    while(lenVetor>1){
        eliminado = removeIndexFromVet(vetor,&lenVetor,indexProxEliminado);
        indexProxEliminado+=1;
        if(indexProxEliminado>=lenVetor){
            if(indexProxEliminado>lenVetor){
                indexProxEliminado=1;
            }else{
                indexProxEliminado=0;
            }
        }
        nEliminados++;
        if(nEliminados==x){
            xEsimo=eliminado;
        }
    }

    printf("Eliminacao %d: %d\n",x,xEsimo);
    printf("Vencedor: %d\n",vetor[0]);
    return 0;
}