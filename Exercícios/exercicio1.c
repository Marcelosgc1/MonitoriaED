#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node *next;
}node;

int printteste(struct node **head){
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
    int flag=0;
    new->numero = n;
    
    if (*head==NULL){
        *head=new;
        new->next = NULL;
    }else{
        while (aux->next)
        {
            printf("rola");
            if (aux->numero<new->numero && aux->next->numero>new->numero){
                new->next = aux->next;
                aux->next = new;
                flag=1;
                break;
            }
            aux = aux->next;
        }
        if (flag==0){aux->next = new;}
    }
    printf("%d\n", aux->numero);

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
        scanf("%d", &n);        
    }
    
    printteste(&head);
    
    


    return 0;
}