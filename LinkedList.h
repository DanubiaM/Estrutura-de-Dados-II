#ifndef DataStructure_LinkedList_h
#define DataStructure_LinkedList_h

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;
//Estrutura do Nó, contendo o dado e o endereço do proximo ponteiro
typedef struct Node {
    void *data; //guardar o dado
    struct Node *next; //endereço do proximo ponteiro
}Node;

typedef struct LinkedList {
    Node *first;  //endereço do primeiro ponteiro
    int size;     //guarda o tamanho
}LinkedList;

typedef bool (*compare)(void*,void*);

void init(LinkedList *list);
int enqueue(LinkedList *list, void *data);
void* dequeue(LinkedList *list);
void* first(LinkedList *list);
void* last(LinkedList *list);
int push(LinkedList *list, void *data);
void* pop(LinkedList *list);
void* top(LinkedList *list);
bool isEmpty(LinkedList *list);
int indexOf(LinkedList *list, void *data, compare equal);
void* getPos(LinkedList *list, int pos);
Node* getNodeByPos(LinkedList *list, int pos);
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);

#endif