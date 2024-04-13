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


    if (*head==NULL){
        *head=new;
        return 0;
    }

    if (new->numero<=aux->numero){
        new->next = aux;
        *head = new;
        return 0;
    }

    while (aux->next)
    {
        if (new->numero<=aux->next->numero){
            new->next = aux->next;
            aux->next = new;
            return 0;
        }
        aux = aux->next;
    }
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
