/* Instituto Federal de Mato Grosso (IFMT) -  Engenharia de Computação  - Estrutura de Dados II  - Prof.Dr. João Paulo D. Pretti - Aluna Danubia G. Macedo - 09/03/2020.

Neste algoritmo é apresentado a implemetanção de uma Lista Duplamente Ligada em C. 


*/
#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"
bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}
void impressao(void *data) {
    int *dado = (int*)data;
    printf("%d - ",*dado);
}
int main() {
    DoublyLinkedList list;
    init(&list);

    int *aux = (int *)malloc(sizeof(int));
    *aux=7;
    //push(&list, aux);
    enqueue(&list, aux);

    aux = (int *)malloc(sizeof(int));
    *aux=4;
    //push(&list, aux);
    enqueue(&list, aux);

    aux = (int *)malloc(sizeof(int));
    *aux=6;
    //push(&list, aux);
    enqueue(&list, aux);

    aux = (int *)malloc(sizeof(int));
    *aux = 8;

    int *remove = (int *)malloc(sizeof(int));
    *remove = 4;
   
   show(&list,impressao);
   showMem(&list);

    
    printf("Adicionando valor %d na posição 2: %d\n", *aux, add(&list,2,aux));   
    printf("Remoção do valor %d: %d\n", *remove, removeData(&list,remove,compara));
    printf("Primeiro valor: %d\n",*((int*)first(&list)));
    printf("Ultimo valor: %d\n",*((int*)last(&list)));    
    printf("Posição do valor %d: %d\n", *aux, indexOf(&list,aux,compara));
    printf("Dado contido na posição 0: %d\n",*((int*)getPos(&list,0))); 
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    // printf("%d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
    return EXIT_SUCCESS;
}
