#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* next;
}node;


typedef struct queue{
    node* head;
    node* last;
}queue;


void insert(queue* q, int n){
    node* new = malloc(sizeof(node));
    new->num = n;
    new->next = NULL;
    
    if (q->last){
        q->last->next = new;
    }else{
        q->head = new;
    }
    q->last = new;
}

void pop(queue* q){
    node* aux = q->head;
    if (q->head){
        q->head=q->head->next;
        free(aux);
    }
    if (!q->head){
        q->last = NULL;
    }
}

int top(queue* q){
    return q->head->num;
}

int main(){
    return 0;
}

