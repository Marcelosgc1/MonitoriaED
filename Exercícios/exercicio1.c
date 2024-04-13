#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node *next;
}node;

int impressaoDaLista(struct node **head){
    struct node *aux = *head;
    while (aux->next)
    {
        printf("%d | ", aux->numero);
        aux = aux->next;
    }
    printf("%d", aux->numero);
    return 0;
}

int insert(struct node **head, int n){
    struct node *aux = *head;
    struct node *new = malloc(sizeof(struct node));
    new->numero = n;
    new->next = NULL;

    /*
    Se a HEAD for NULL, ou seja, nenhuma struct node existir ainda,
    então a struct node 'new' é atribuida à head, 
    como primeiro elemento da lista encadeada.
    */

    if (*head==NULL){
        *head=new;
        return 0;
    }

    /*
    Se o número do primeiro elemento da lista encadeada for maior
    que o número do elemento que queremos pôr na lista, então
    fazemos a 'new->next' apontar para o primeiro elemento, e fazemos
    a head apontar para 'new', dessa forma, o primeiro elemento da
    lista encadeada passa da ser a 'new'.
    */

    if (new->numero<=aux->numero){
        new->next = aux;
        *head = new;
        return 0;
    }

    /*
    Se não for nenhum dos casos acima, então começamos a percorrer
    os elementos da lista encadeada. O programa vai pegar o número
    do elemento à frente da auxiliar, (ou seja, se a auxiliar aponta 
    para o primeiro elemento, o programa vai pegar o segundo elemento)
    e verificar se é maior que o número da struct node 'new' que foi
    criada. Se for o caso, a 'new' passa a apontar pra esse elemento 
    que está na frente e a struct node que a 'aux' aponta passa a 
    apontar para a 'new', dessa forma, inserindo o elemento no meio
    da lista. Se não for o caso, então a 'aux' começa a apontar para
    o próximo elemento da lista e refaz a avaliação do valor, percorrendo
    a lista até achar um valor maior que a do número da new.    
    */

    while (aux->next)
    {
        if (new->numero<=aux->next->numero){
            new->next = aux->next;
            aux->next = new;
            return 0;
        }
        aux = aux->next;
    }

    /*
    Se toda lista for percorrida, e não for achado nenhum valor maior
    que o número da new, então a struct node 'new' é inserida no fim
    da lista encadeada.
    */

    aux->next = new;
    return 0;

};




int main(){
    int n;
    struct node *head = NULL;
    printf("Escreva um numero: \n");
    scanf("%d", &n);
    while (n>0)
    {
        insert(&head, n);
        printf("Escreva um numero: \n");
        scanf("%d", &n);        
    }
    
    impressaoDaLista(&head);

    return 0;
}
