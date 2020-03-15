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

  if(isEmpty(list)){
    list->first = newNode; //se estiver vazia ira adicionar o novo nó no next.
  }else{
    Node *aux= list->first;
    while(aux->next != NULL){ //o nó auxiliar ira percorrer a lista e verificar onde o next sera NULL, logo quando for igual a NULL saira do laço e ira receber o newNode
      aux = aux->next;
     }
  aux->next = newNode;
}

list->size++;
}
void* first(LinkedList *list){
	Node *aux;
	if(isEmpty(list)){
		return NULL;
	}else{
		*aux=list->first; //verificar se ta funcionando ,diferente do prof
		return aux->data;
	}
}
//vai retornar o ultimo valor da lista
//primeiro ira verificar se a lista  lista esta vazia, se nao estiver ira procurar o valor final que tiver NULL
//quando achar ira retornar o  date deste no
void* last(LinkedList *list){
	void *data=NULL;
	if(!isEmpty(list)){
		Node *aux= list->first;
		while(aux->next !=NULL){
			aux= aux->next;
		}
		data = aux->data;
	}
	return data;
}
//ira inserir o valor no inicio da lista
//cria o novo no, recebe o valor, se a lista for vazia, list->first ira receber o novo no
//se nao for vazia, o novo nó ira apontar para first, first ira apontar agr para o endereço do primeiro no
//ira adicionar mais um ao tamanho
int push(LinkedList *list, void *data){
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data= data;
	if(NewuNode=NULL) return -1;

	if(isEmpty(list)){
		return list->first = NewNode;
	}
	NewNode->next = list->first;
	list->first = NewNode;
	list->size++;
	return 1;
}
//remove o primeiro valor da lista
//se a lista for vazia retorna null, caso n, um no aux recebe o endereço do primeiro no
//o endereço do primeiro no vai receber o endereço da onde o no aux esta apontando
//data recebe o dado do no aux
//libera o no aux, pois ele é o elemento a ser removido
//diminui um na lista
void* dequeue(LinkedList *list){
	Node *aux;
	if(isEmpty(list)){
		return NULL;
	}
	aux = list->first;
	list->first = aux->next; //temos aqui uma diferença da do prof. ver se funcioa
	void *data = aux->data;
	free(aux);
	list->size--;
	return data;
}
//funciona da mesma maneira que o pop
void* pop(LinkedList *list){
	return dequeue(list);
}
//mostra o topo da lista, logo utiliza a funcao first
void* top(LinkedList *list){
	return first(list);
}
//funcao responsavel por retornar a posicao onde esta o valor dado pelo usuario
//primeiro verifica se a lista esta vazia, se estiver retorna -1
//cria um aux que recebe o  endereco do primeiro no da lista
//o laco ira procurar a posicao do valor dito pelo usuario enquando aux ->data!=data &&aux!=NULL
//adiciona um contador para contar a quantidade de vezes que o laco passou,assim ira ter a posição
int indexOf(LinkedList *list, void *data, compare equal){
	if(isEmpty(list)) return -1;
	int n=0;
	Node *aux= list->first;

	while(!equal(aux->data,data) && aux!=NULL){
		aux=aux->next;
		n++;
	}
	return (aux=NULL)?-1:n; // le-se, se aux for igual a NULL, retona -1 se nao retorna n
}
//funcao responsavel por retornar  o endereco do no na posição solicitada
Node* getNodeByPos(LinkedList *list, int pos){
	int i=0;
	if(isEmpty(list) || pos>=list->size) return NULL;
	Node *aux = list->first;
	while(i<pos-1){//verificar se esta funcionando, prof ta diferente
		aux= aux->next;
		i++;
	}
	return aux;
}
//funcao resposavel por retornar o dado na posicao especeficada
void* getPos(LinkedList *list, int pos){
	Node *aux = getNodeByPos(list,pos);
	if(aux==NULL)?NULL:aux->data;
}
//funcao responsavel por inserir o dado na posicao solicitada pelo usuario
int add(LinkedList *list, int pos, void *data){

	if(isEmpty(list)) return push(list,data);

	Node *aux = getNodeByPos(list,pos-1); //retorna o endereço do nó naquela posicação
	if(aux=NULL) return -2;
	Node *NewNode =  (Node*)malloc(sizeof(Node));
	if (NewNode=NULL) return -1;

	NewNode->next = aux->next;
	aux->next= NewNode;
	NewNode->data= data; //diferente do prof aqui<<

	list->size++;
	return 1;
}
//funcao responsavel por adicionar uma lista de origem dentro de uma lista de destino apartir de uma posição dada.
int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
	if(listDest==NULL || isEmpty(listDest)) return -1;
	if(listSource==NULL || isEmpty(listSource)) return -2;
	Node *last=NULL;

	for(last = listSource->first; last->next!=NULL;last=last->next);//nao entendi a leitura
	if(pos == 0 ){
		last->next = listDest->first;
		listDest->first = listSource->first;
	}else{
	Node *aux = getNodeByPos(listDest,pos-1);
	if(aux==NULL) return -3;
	last->next = aux->next;
	aux->next = listSource->first;
	}
	listDest->size +=listSource->size;
	reuturn listSource->size;
}
//ira remover um elemento da lista, dado a posição
void* removePos(LinkedList *list, int pos){
	if(isEmpty(list) || pos>=list->size) return NULL;

	Node *aux = getNodeByPos(list, pos-1);
	Node *DeletNode =  aux->next;

	aux->next= DeletNode->next;

	void* DataDelet = DeletNode->data;

	free(DeletNode);
	list->size--;
	return DataDelet;
}
bool removeData(LinkedList *list, void *data, compare equal){
	if(isEmpty(list)) return -1;
	Node *removeData = NULL;
	if(equal(list->first->data,data)){
		removeData= list->first;
		list->first = list->first->next;
		free(removeData->data);
		free(removeData);
		list->size--;
		return true;
	}else{
		Node *aux=list->first;
		while(aux->next!=NULL && !equal(aux->next->data,data)){
			aux=aux->next;
		}
		if(aux->next!=NULL){
			Node *nodeRemove =  aux->next;
			aux->next= nodeRemove->next;
			free(remove->data);
			free(nodeRemove);
			list->size--;
			return true;
		}else{
			return false;
		}
	}
//como pensei em fazer
//int cont=0;
//Node *aux= list->first;
//while(aux->next=NULL){
//	if (cont==0) dequeue(aux)
//	cont++;
//	if(equal(data,aux->data){
//		Node *remove=getNodeByPos(lis,cont-1);
//		remove->next = aux->data;
//		free(aux->data);
//		free(aux);
//		return true;
//	}
//}
//return false;
}
//funcao responsavel por retornar a posicao que se contra tal dado
int indexOf(LinkedList *list, void *data, compare equal){
	if(isEmpty(list)) return -1;
	Node *aux =  list->first;
	int n;
	while(aux!=NULL && !equal(aux->data,data)){
		aux=aux->next;
		n++;
	}
	return(aux==NULL)?-1:n;
}
