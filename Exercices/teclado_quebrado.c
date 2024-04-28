#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    node* last;
    node* atual;
}queue;

int impressaoDaLista(queue *q){
    struct node *aux = q->head;
    while (aux)
    {
        printf("%c", aux->c);
        aux = aux->next;
    }
    return 0;
}

void killList(queue *q){
    while (q->head){
        q->atual=q->head;
        q->head=q->head->next;
        free(q->atual);
    }
    q->last=NULL;
    q->atual=NULL;
}


void insertAtual(queue* q, char c, int v){
    node* new = malloc(sizeof(node));
    new->c = c;
    new->next = NULL;

    if (q->atual){
        if (v){
            new->next=q->head;
            q->head=new;
        }else if(q->last==q->atual){
            q->atual->next = new;
            q->last=new;
            
        }else{
            new->next=q->atual->next;
            q->atual->next=new;
        }
    }else{
        q->head = new;
        q->last = new;
    }
    q->atual=new;
    
}


int main(){
    char c;
    queue q;
    int variavel=0;
    
    q.head=NULL;
    q.last=NULL;
    q.atual=NULL;
    
    while((c=getchar()) != EOF){
        if (c!='\n'){
            if (c=='['){
                q.atual=q.head;
                variavel=1;
            }else if (c==']'){
                q.atual=q.last;
                variavel=0;
            }else{
                insertAtual(&q, c, variavel);
                variavel=0;
            }
        }else{
        impressaoDaLista(&q);
        printf("\n");
        killList(&q);   
        }     
    }
    return 0;
}