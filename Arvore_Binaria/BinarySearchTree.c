#include "BinarySearchTree.h"




int add(TreeNode **root, void *element, TreeComparator f){

    TreeNode *Node  = (TreeNode*)malloc((sizeof(TreeNode)));
     //verifica se já existe algo no nó raiz       

    if(*root==NULL){ // se o meu nó raiz for nulo, ele nao existe nada
        Node->element = element;  // aqui eu adiciono o valor do elemento no element do nó  
        Node->left = NULL; 
        Node->right = NULL;    
        *root = Node;   // ele recebe o endereço do meu node criado
        return 1;
    };

    // caso agr ele nao seja uma arvore vazia
    // nessa situação tem de verificar se ele é maior ou menor que os nós filhos

    int compvalue = f(element, (*root)->element); // verifica se o elemento é maior que o elemento do root

    if (compvalue > 0){ // caso for, ira chamar essa função novamente recursivamente, agora sendo root o nó do lado direito
        return add(&(*root)->right, element, f);
    } else if (compvalue < 0) { // se for menor, ele irá chamar a funcação novamente recursivamente, agora  sendo root nó do lado esquerdo
        return add(&(*root)->left, element, f);
    } else {
        return -1;
    };

};

int find(TreeNode *root, void *key, TreeComparator f, void **element){
    int compvalue;
    
    // Verifica se é nulo, se for logo não deve buscar  o elemento
    if (root == NULL)
        return 0;
    
    compvalue = f(key, root->element); // verifica se a chave é maior que o root
    if (compvalue == 0) { // se for 0, encontrou o elemento
        *element = root->element;
        return 1;
    };
  
    if (compvalue > 0) // se for maior, entao deve-se chamar essa função novamente passando right como parametro
        return find(root->right, key, f, element);
    
    return find(root->left, key, f, element); // se nao for maior, nem igual a 0, signigica que é menor, logo chama a função novamente com parametro left
};

void in_order(TreeNode *root, printNode print){

   if (root!=NULL) { // se o root for diferente de nulo 
        in_order(root->left, print); // ele chamara a função novamente avançando pela esquerda
        print(root->element);       
        in_order(root->right, print);
    };

};

void pre_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        print(root->element);
        pre_order(root->left, print);
        pre_order(root->right, print);
    };
};

void post_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        post_order(root->left, print);
        post_order(root->right, print);
        print(root->element);
    };
};


TreeNode *greaterRight(TreeNode **no){
    if((*no)->right != NULL)
        return greaterRight(&(*no)->right);
    else{
        TreeNode *aux = *no;
        if((*no)->left != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *no = (*no)->left;
        else
            *no = NULL;
        return aux;
    }
}

TreeNode *smallerLeft(TreeNode **no){
    if((*no)->left != NULL)
        return smallerLeft(&(*no)->left);
    else{
        TreeNode *aux = *no;
        if((*no)->right != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
            *no = (*no)->right;
        else
            *no = NULL;
        return aux;
    };
};

int removeTreeNode(TreeNode **root, void *key, TreeComparator f){
    if(*root==NULL) return 0;
    
    int compvalue = f(key, (*root)->element); // verifica se a chave é maior que o root

    if (compvalue == 0) { // se for 0, encontrou o elemento, agora deve verificar se esse nó contem filhos, 
        TreeNode *aux = *root;
        if((*root)->left == NULL && (*root)->right==NULL){ // se não tiver filho apenas remove
            free(aux);
            *root = NULL;
        } else if( (*root)->left == NULL){ // se não houver no no lado esquerdo, o root deve receber o nó da direta
                    (*root) = (*root)->right;
                    aux->right = NULL;
                    free(aux);
                    aux = NULL;
                };
                if((*root)->right == NULL){// se não houver no no lado direito, o root deve receber o nó da esquerda
                    *root= (*root)->left;
                    aux->left = NULL;
                    free(aux);
                    aux = NULL;
                }
                else{ // porem se haver ambos os lados nó
                        TreeNode *aux = greaterRight(&(*root)->left); // chama a função que retorna o maior deles
                        aux->left = (*root)->left;
                        aux->right = (*root)->right;
                        (*root)->left = (*root)->right = NULL;
                        free((*root));  
                        *root = aux;  
                        aux = NULL;
                };

        };
        

  
    if(compvalue > 0) {        // se for maior, entao deve-se chamar essa função novamente passando right como parametro
        return removeTreeNode((*root)->right,key,f);
    }else if( compvalue <0){
         return removeTreeNode((*root)->left,key,f);
    };
};


int height (TreeNode *root) {

      if (root == NULL)
        return -1; // altura da árvore vazia
    else {
        int hl = height(root->left); //altura esquerda
        int hr = height(root->right); //altura direita
        if (hl < hr) return hr + 1;
        else return hl + 1;
    }
}
void destroy (TreeNode **root) {
    if (*root==NULL) return;
    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root=NULL;
}