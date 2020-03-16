#ifndef DataStructure_LinkedList_h
#define DataStructure_LinkedList_h

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;//


//Estrutura do Nó, contendo o dado e o endereço do proximo ponteiro, guardar as informações do nó
typedef struct Node {
    void *data; //guardar onde o esta o dado, por isso void, pode ser qualquer tipo de  dado
    struct Node *next; //endereço do proximo nó da lista
}Node;

typedef struct LinkedList {
    Node *first;  //endereço do primeiro ponteiro
    int size;     //guarda a quantidade de elemento da lista
}LinkedList;
//ponteiro de uma função
typedef bool (*compare)(void*,void*);
/* int *n1= (int*)date1;
    int *n2 = (int*)date2;
    if(*n1==n*2)?true:false
*/
//retorna booleado, e tem como parametro dois voids

void init(LinkedList *list); //inicializa a estrutura

int enqueue(LinkedList *list, void *data);//toda vez que fazer inserção tem de fazer malloc
//o malloc devolve um endereço void, por isso em (Node*)malloc... precisa de colocar o Node* par dizer o tipo de retorno
///date valor inserido
//return 1 representa a quantidade de inserção

void* dequeue(LinkedList *list);//remoção de elemento
//se tiver elemento, remove o primeiro

void* first(LinkedList *list);//quer saber quem é o primeiro elemento da lista
//se a lista for vazia retorna null se nao retorna date 

void* last(LinkedList *list);//para saber quem é o ultimo da lista

int push(LinkedList *list, void *data);//insere no inicio da fila
//o novo no aponta para o first, depois p first vai apontar para o novo no
//sempre começa o algoritmo movimentando o novo nó ar n perder enedereço

void* pop(LinkedList *list);//msm da dequeue, porem usa a função dependendo se esta trabalhando com pilha ou fila

void* top(LinkedList *list);//o primeiro é frist

bool isEmpty(LinkedList *list);

int indexOf(LinkedList *list, void *data, compare equal);//devolver a posição do dado solicitado
//equal procura a igualdade
//enquanto o date do aux n for igual ao solicitado, ele vai procurar.
//se nao achare retorna -1
//ponteiro de funçao guarda o endereço onde começa o algoritmo
//a variavel equal é do tipo compare, a compare recebe dois voids e retorna um booleano

void* getPos(LinkedList *list, int pos);//quer saber o dado que esta guardado naquela posição

Node* getNodeByPos(LinkedList *list, int pos);//devolver o endereço do nó pedido pelo programador.Ex.: Quarto nó
//Retorna Node* porque devolve um endereço
//enquanto o aux nao for nulo ou o contador menor que a posição solicitada, incrimentar o aux recebe o proximo valor.

int add(LinkedList *list, int pos, void *data);//inserir em alguma posição intermediaria solicitada pelo usuario
//o aux para na posição -1, pois é ele que guarda o endereço do proximo(nest), ou seja armazena o endereço da proxima posição que é onde quero inserir

int addAll(LinkedList *listDest, int pos, LinkedList *listSource); //adiciona uma lista de origem dentro de uma de destino
//lista de origem é de onde vem os dados, a de destino é para  onde vai os dados
//se quiser inserir na posição 0, o final da minha lista tem de apontar para o inicio da outra
//caso nao seja na primeira posição, chama o getNodeByPos, o ultimo no da lista origem aponta para a proxima posição da lista destino, e o next da lista de destino aponta para o first da origem

void* removePos(LinkedList *list, int pos);//remove uma posição solicitada
//se quiser remover a posição 1, tem de parar na posição 0, pois aponta (next) para o proximo, o que sair vai para o trash(lixo)(noderemove)

bool removeData(LinkedList *list, void *data, compare equal);//remove um dado da lista


#endif
