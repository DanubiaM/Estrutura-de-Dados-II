//https://codeforwin.org/2015/11/c-program-to-create-and-traverse-circular-linked-list.html

void init(LinkedList *list){
     
  list->first = NULL;
  list->size = 0;
}
//apenas sera vazia quando o tamanho for igual a 0
bool isEmpty(LinkedList *list){
    return (list->size ==0);
}


int enqueue(LinkedList *list, void *data){

  Node *newNode= (Node*)malloc(sizeof(Node)); //ira reservar um espaço na memoria do tipo nó para a criação do novo nó
  if(newNode == NULL) return -1; //caso o não exista espaço na memoria ira ter retorno -1

  newNode->data = data; //agora o novo nó ira receber o valor
  newNode->next = NULL; //e apontara para NULL
  //é necessário verificar se a lista esta vazia para saber o local onde sera adicionado

  if(isEmpty(list))   
    list->first = newNode; //se estiver vazia ira adicionar o novo nó no next.
  else{
    Node *aux= list->first;
    while(aux->next != NULL){ //o nó auxiliar ira percorrer a lista e verificar onde o next sera NULL, logo quando for igual a NULL saira do laço e ira receber o newNode
      aux = aux->next;
     }
  aux->next = newNode;    
}

list->size++;
}
void* first(LinkedList *list);