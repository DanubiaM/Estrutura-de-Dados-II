#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
//Init tem como função iniciar a lista, com um nó lixo, sendo sua função apenas não deixar com que a lista seje nula
void init(DoublyLinkedList *list){ 
  Node *trashNode = (Node*)malloc(sizeof(Node));
  trashNode->data = NULL;
  trashNode->next = trashNode;
  trashNode->previous = trashNode;

  list->first = trashNode;
   
}
//Esta função é responsavel por inserir um valor no final da lista
int enqueue(DoublyLinkedList *list, void *data){
  
  Node *newNode = (Node*)malloc(sizeof(Node));
  //verifica-se se existe espaço na memoria ainda parar criar a lista, caso n retorna -1
  if(newNode == NULL) return -1;

  newNode->data = data;
  newNode->next = list->first;
  newNode->previous = list->first->previous;
  list->first->previous->next = newNode;
  list->first->previous = newNode;
    
  list->size++;

  return 1;
}
//Função responsavel por remover um item no inicio da fila
void* dequeue(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;
    Node *trash = list->first;
    Node *first = list->first->next;
    
    first->next->previous = trash;
    trash->next = first->next;
    
    void *data = first->data;
    free(first);
    list->size--;
    
    return data;
}
//Função reponsavel por retornar o primeiro dado da lista.
void* first(DoublyLinkedList *list){
    if(isEmpty(list)) return NULL;
    Node *aux =  list->first->next;

    return aux->data;
}
//Função responsavel por retornar o ultimo dado da lista
void* last(DoublyLinkedList *list){
    return list->first->previous->data;
}
//função responsavel por inserir o dado no inicio da lista
int push(DoublyLinkedList *list, void *data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return -1;
    newNode->data = data;
    newNode->next = list->first->next;
    newNode->previous = list->first;

    list->first->next->previous = newNode;
    list->first->next = newNode;

    list->size++;
    return 1;
}
//Função reponsavel por remover no inicio da lista
void* pop(DoublyLinkedList *list){
    return dequeue(list);
}
//Função responsavel  por apresenta o primeiro dado da lista
void* top(DoublyLinkedList *list){
    return first(list);
}
//Procedimento que verifica se a lista é vazia
bool isEmpty(DoublyLinkedList *list){
 return (list->size==0);
}
//Função responsavel por procurar a posição que se encontra tal dado
int indexOf(DoublyLinkedList *list, void *data, compare equal){
    int cont = 0; // cria-se uma variavel contadora
    if(isEmpty(list)) return -1; //verifica-se se a lista esta vazia
    Node *aux = list->first->next; //cria um nó auxiliar 
    
    while(aux != list->first){ // enquanto o endereço do primeiro nó for diferente do endereço do próximo nó, ira continuar o laço

      if(equal(data, aux->data) == true) return cont; //quando achar o valor igual ao solicitado de data retorna o contador da posição

      aux = aux->next; // este ira atualizar o aux, para andar por cada nó.
      cont++;//contador de posição.
    }
    return -2;
}
//Esta função é responsavel por devolver o dado que esta na posição solicitada
void* getPos(DoublyLinkedList *list, int pos){
    Node *aux= getNodeByPos(list,pos);
    if(aux == NULL){ return NULL; }else{ return aux->data; }
}

//Função que retorna o endereço do nó na posição solicitada
Node* getNodeByPos(DoublyLinkedList *list, int pos){
 
    if(isEmpty(list) ||  pos>=list->size ) return NULL;
   

    Node *aux = list->first->next;

    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next);
    return aux;
}
//Função responsavel por adicionar um dado na posição solicitada
int add(DoublyLinkedList *list, int pos, void *data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) return -1;

  Node *aux = getNodeByPos(list,pos);
  if(aux == NULL) return -2;

  newNode->data = data;
  newNode->next = aux;
  newNode->previous = aux->previous;

  aux->previous->next = newNode;
  aux->previous = newNode; 

  list->size++;
  return 1;
}
//Função responsavel por adicionar a ListSource na ListaDest
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){
  Node *aux = getNodeByPos(listDest,pos-1);
  if(aux == NULL) return -1;
  if(isEmpty(listSource)) return -2;

  listSource->first->previous = aux;
  listSource->first->previous->next = aux->next;

  aux->next = listSource->first;
  aux->next->previous = listSource->first->previous;

  listDest->size += listSource->size; 

  return listSource->size;

}
//Função responsavel por remover um elemento baseado na função fornecida
void* removePos(DoublyLinkedList *list, int pos){
  Node *aux  = getNodeByPos(list,pos);
  if(aux == NULL) return NULL;

  aux->previous->next = aux->next;
  aux->next->previous = aux->previous;

  void* data = aux->data;

  free(aux);

  list->size--;
  
  return data;
  }
//Função responsavel por remover o dado solicitado pelo usuario
int removeData(DoublyLinkedList *list, void *data, compare equal){
    if(isEmpty(list)) return 0;
    Node *aux = list->first->next;
    while(aux != list->first ){    
        if(equal(aux->data,data)){
          aux->previous->next = aux->next;
          aux->next->previous = aux->previous;
          free(aux->data);
          free(aux);
          return 1;
          list->size--;
        }
      aux = aux->next;
    }
    return 0;
}
//Função responsavel por exibir o dado de todos os nós da lista
void show(DoublyLinkedList *list, printNode print){
    Node *aux = list->first->next;
    printf("Dados contidos na lista: \n");
    while(aux != list->first){
        print(aux->data);
        aux = aux->next;
    }
    printf("\n");
}
//Esta função é responsavel por exibir o endereço do trash Node, os próximos nós, data, previous e next
void showMem(DoublyLinkedList *list){
    Node *aux = list->first->next;

    printf("\nTrash Node: %p\n", list->first);
    printf("Addr No \t Previous \t Data \t\t\t Next\n");
    while(aux != list->first){
      printf("%p->\t %p\t %p\t\t %p\n",aux ,aux->previous, aux->data, aux->next);
      aux= aux->next;    
    }
    printf("\n");
}
