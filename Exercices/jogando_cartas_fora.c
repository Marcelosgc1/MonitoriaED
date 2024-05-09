#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node *next;
}node;

typedef struct stack{
  node * head;
  node * last;
}stack;

int criar(int n, stack *s){
  for (int i = 1; i <= n; i++)
  {
    node * new = malloc(sizeof(node));
    new->next=NULL;
    new->numero=i;
    if (s->head==NULL){
      s->head=new;
      s->last=new;
    }
    else{
      s->last->next=new;
      s->last=new;
    }
  }
  return 0;
}

int descarte_e_colocar_no_fim(stack *s){
  int num;
  node * aux=s->head;
  num=s->head->numero;
  s->head=s->head->next;
  free(aux);
  //deletado
  if (s->head != s->last){
  aux=s->head;
  s->head=s->head->next;
  aux->next=NULL;
  s->last->next=aux;
  s->last=aux;
  printf(" %d,", num);
  return 0;
  }
  
  printf(" %d", num);
  return 0;
}

int main(){
  int flag=0, n;
  stack s;


  while (flag==0){
    s.head=NULL;
    s.last=NULL;
    scanf("%d", &n);
    if (n==0){
      flag=1;
    }
    else{
      printf("Discarded cards:");
      criar(n, &s);
      while (s.head != s.last){
        descarte_e_colocar_no_fim(&s);
      }
      printf("\nRemaining card: %d\n", s.head->numero);
      free(s.head);
    }
  }
  return 0;
}
