/*
 * antee
 * 2016-05-15
 */

#include<stdio.h>
#include<stdlib.h>

/* prototype */
typedef struct node node;
typedef struct list list;

list listCreate();
int push(void *pointer);
(void*) iterator();

/* structure */
struct node{
  node * previous_node;
  node * next_node;
  void * value;
};

struct list{
  node * head_node;
  node * tail_node;

  unsigned long length;

  void (*push)(void *pointer);
  void (*iterator)(void);
};

/* function implememtation */
list listCreate(){
  list *plist;

  if(plist = malloc(sizeof(*plist)) == NULL) return NULL;

  plist->head = plist->tail = NULL;

  plist->length = 0;

  plist->push = push;
  plist->iterator = iterator;

  return plist;
}

int push(void *pointer){
  if(plist == NULL) return 1;
  
  node *pnode;

}

int main(int argc, char** argv){
  return 0;
}
