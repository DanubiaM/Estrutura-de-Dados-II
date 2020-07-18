#ifndef DataStructure_DoublyLinkedList_h
#define DataStructure_DoublyLinkedList_h

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;//


//Estrutura do Nó, contendo o dado e o endereço do proximo ponteiro e o anterior, guardar as informações do nó
typedef struct Node {
    void *data; //guardar onde o esta o dado, por isso void, pode ser qualquer tipo de  dado
    struct Node *next; //endereço do proximo nó da lista
    struct Node *previous; //endereço do nó anterior
}Node;

typedef struct DoublyLinkedList {
    Node *first;  //endereço do primeiro ponteiro
    int size;     //guarda a quantidade de elemento da lista
}DoublyLinkedList;


typedef bool (*compare)(void*,void*);
typedef void (*printNode)(void*);
void init(DoublyLinkedList *list);
int enqueue(DoublyLinkedList *list, void *data);
void* dequeue(DoublyLinkedList *list);
void* first(DoublyLinkedList *list);
void* last(DoublyLinkedList *list);
int push(DoublyLinkedList *list, void *data);
void* pop(DoublyLinkedList *list);
void* top(DoublyLinkedList *list);
bool isEmpty(DoublyLinkedList *list);
int indexOf(DoublyLinkedList *list, void *data, compare equal);
void* getPos(DoublyLinkedList *list, int pos);
Node* getNodeByPos(DoublyLinkedList *list, int pos);
int add(DoublyLinkedList *list, int pos, void *data);
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource); 
void* removePos(DoublyLinkedList *list, int pos);
bool removeData(DoublyLinkedList *list, void *data, compare equal);


#endif
