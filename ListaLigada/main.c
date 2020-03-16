#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}
int main() {
    LinkedList list;
    init(&list);
    
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=4;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=7;
    enqueue(&list, aux);

    printf("Primeiro item da lista: %d\n",*((int*)first(&list)));
    printf("Posição do valor: %d é: %d \n", *aux, indexOf(&list,aux,compara));
    printf("Valor da posição: %d\n",*((int*)getPos(&list,2)));
    printf("Removendo ... %d\n",*((int*)dequeue(&list)));
    printf("Removendo ... %d\n",*((int*)dequeue(&list)));
    printf("Removendo ... %d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
    return EXIT_SUCCESS;
}
