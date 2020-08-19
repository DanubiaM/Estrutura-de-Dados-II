
#include <assert.h> // Biblioteca que verifica se a expressão é verdade ou falsa, se verdadeira continua o programa, se falso encerra o programa
#include <string.h>
#include "BinarySearchTree.h"


//Elemento que será guardado na árvore
typedef struct BinarySearchTreeElement {
    int key;
    char value[10];
} BinarySearchTreeElement;


// Função para comparação dos elementos
static int BinarySearchTreeElementComparator(void *element1, void *element2) {
    BinarySearchTreeElement *e1 = (BinarySearchTreeElement *) element1;
    BinarySearchTreeElement *e2 = (BinarySearchTreeElement *) element2;
    
    if (e1->key > e2->key)
        return 1;
    if (e1->key < e2->key)
        return -1;
    return 0;
}
//exibe o dado
void printInteger(void *data) {
    
   BinarySearchTreeElement *bste = (BinarySearchTreeElement*)data;
    printf("%d ", bste->key);
};


int main(int argc, char **argv) {

    TreeNode *tree = NULL;
    BinarySearchTreeElement *el, findEl;
    
    // Adiciona alguns elementos
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL); // se ele for diferente de nulo nao cancela o programa
    el->key = 10;
    snprintf(el->value, 10, "Val 10"); // uma forma de garantir que não passe do tamanho solicitado
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1); // adiciona o valor de el
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1); // se retornar -1 é pq deu erro

    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL); // se ele for diferente de nulo nao cancela o programa
    el->key= 6 ;
    snprintf(el->value, 10, "Val 6"); // uma forma de garantir que não passe do tamanho solicitado
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1); // adiciona o valor de el
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);

    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL); // se ele for diferente de nulo nao cancela o programa
    el->key = 8 ;
    snprintf(el->value, 10, "Val 8"); // uma forma de garantir que não passe do tamanho solicitado
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1); // adiciona o valor de el
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);


    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL); // se ele for diferente de nulo nao cancela o programa
    el->key = 15 ;
    snprintf(el->value, 10, "Val 15"); // uma forma de garantir que não passe do tamanho solicitado
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1); // adiciona o valor de el
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL); // se ele for diferente de nulo nao cancela o programa
    el->key = 12 ;
    snprintf(el->value, 10, "Val 12"); // uma forma de garantir que não passe do tamanho solicitado
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1); // adiciona o valor de el
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    
    in_order(tree, printInteger);
    printf("\n");
    pre_order(tree, printInteger);
    printf("\n");
    post_order(tree, printInteger);
    printf("\n");
    printf("Altura: %d ", height(tree));
    printf("\n");

    findEl.key = 8;
    assert(find(tree, (void *) &findEl, &BinarySearchTreeElementComparator,(void **) &el) == 1);
    assert(strcmp(el->value, "Val 8") == 0);

    //para um valor nao existente
    findEl.key = 0;
    assert(find(tree, (void *) &findEl, &BinarySearchTreeElementComparator,(void **) &el) == 1);
    assert(strcmp(el->value, "Val 0") == 0);

   
};

