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

void iwanttobreakfree(queue *q){
    while (q->head){
        q->atual=q->head;
        q->head=q->head->next;
        free(q->atual);
    }
    q->last=NULL;
    q->atual=NULL;
}


void insert_atual(queue* q, char c, int v){
    node* new = malloc(sizeof(node));
    new->c = c;
    new->next = NULL;

    if (q->atual){
        if (v){
            new->next=q->head;
            q->head=new;
            q->atual=new;
        }else if(q->last==q->atual){
            q->atual->next = new;
            q->atual=new;
            q->last=new;
            
        }else{
            new->next=q->atual->next;
            q->atual->next=new;
            q->atual=new;
        }
    }else{
        q->head = new;
        q->last = new;
        q->atual = new;
    }
    
}


int main(){
    char c[1000];
    queue q;
    int variavel=0;
    q.head=NULL;
    q.last=NULL;
    q.atual=NULL;
    int i=0;
    scanf("%s", c);
    while(c[i] != EOF){
        if (c[i]!='\0'){
            if (c[i]=='['){
                q.atual=q.head;
                variavel=1;
            }else if (c[i]==']'){
                q.atual=q.last;
                variavel=0;
            }else{
                insert_atual(&q, c[i], variavel);
                variavel=0;
            }
            i++;
        }else{
            impressaoDaLista(&q);
            printf("\n");
            i=0;
            iwanttobreakfree(&q);
            c[0]='\0';
            scanf("%s", c);
        }
    }
  return 0;
}