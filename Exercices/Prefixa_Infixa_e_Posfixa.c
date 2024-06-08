#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  struct node *parent;
  struct node *left;
  struct node *right;
  char c;
  int index;
}node;

typedef struct tree{
  struct node *root;
}tree;

void insert(tree *r, char c, int num){
  node *new = malloc(sizeof(node));
  new->right=NULL;
  new->left=NULL;
  new->parent=NULL;
  new->index=num;
  new->c=c;


  if(!r->root){
    r->root=new;
    return;
  }
  node *aux = r->root;
  while(aux->left || aux->right){
    if(aux->index > new->index){
      if (aux->left){
      aux=aux->left;}
      else{
        aux->left=new;
        new->parent = aux;
        return;
      }
    }
    else{
      if (aux->right){
        aux=aux->right;
      }
        else{
          aux->right=new;
          new->parent = aux;
          return;}
    }
  }
  if(aux->index > new->index){
    aux->left=new;
    new->parent=aux;
  }else{
    aux->right=new;
    new->parent=aux;
  }

}

void printar(node *r){
  if (r){
    printar(r->left);
    printar(r->right);
    printf("%c", r->c);
    free(r);
  }
}


void create_tree(char *s1, char *s2, int tam){
  tree *r=malloc(sizeof(tree));
  r->root=NULL;
  int i, j;
  char atual, num;
  for (i=0; i<tam; i++){
    atual = s1[i];
    for (j=0; j<tam; j++){
      if (s2[j]==atual){
        num=j;
        break;
      }
    }
    insert(r, atual, num);
  }
  printar(r->root);

}



int main(){

  int entradas, i, tamanho;
  char* s1 = malloc(1000*sizeof(char));
  char* s2 = malloc(1000*sizeof(char));

  scanf("%d", &entradas);

  for (i=0;i<entradas;i++){
    scanf("%d %s %s", &tamanho, s1, s2);
    create_tree(s1, s2, tamanho);
    printf("\n");


  }
  free(s1);
  free(s2);

  return 0;
}
