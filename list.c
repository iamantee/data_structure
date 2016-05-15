/*
 * antee
 * 2016-05-15
 */

#include<stdio.h>
#include<stdlib.h>

/* prototype */
typedef struct node node;
typedef struct list list;

void * listCreate();
void * nodeCreate();
int push(list *plist, void *value);
void * iterator();

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

/* *
 * Description:
 * nodeCreate function is to init a new node.
 *
 * Return Value:
 * nodeCreate function return the inited node.
 * */
void * nodeCreate(){
  node *pnode;

  if((pnode = (node*) malloc(sizeof(struct node))) == NULL) return NULL;

  pnode->previous_node = NULL;
  pnode->next_node = NULL;
  pnode->value = NULL;

  return pnode;
}

/* *
 * Description:
 * listCreate function is to init a new linked list.
 *
 * Return Value:
 * listCreate function return the inited linked list.
 * */
void * listCreate(){
  list *plist;

  if((plist = (list*) malloc(sizeof(struct list))) == NULL) return NULL;

  plist->head_node = plist->tail_node = NULL;

  plist->length = 0;

  /*
  plist->push = push;
  plist->iterator = iterator;
  */

  return plist;
}

/* *
 * Description: 
 * push function is to push a new value into the specified linked list on the tail.
 * When the length of the linked list is 0, the value of head node and tail node are the same.
 * Although the number of nodes is 2 at this specific situation, the length of list is set to be 1. 
 *
 * Return Value:
 * push function returns 0 to refer to success and 1 for failure.
 * */
int push(list *plist, void *value){
  if(plist == NULL) return 1;
  
  node *pnode = nodeCreate();
  pnode->value = value;

  if(plist->length == 0){
    plist->head_node = plist->tail_node = pnode;
    plist->length = 1;
  } else if(plist->length == 1){
    plist->tail_node = pnode;
    plist->head_node->next_node = plist->tail_node;
    plist->tail_node->previous_node = plist->head_node;
    plist->length = 2;
  } else{
    plist->tail_node->next_node = pnode;
    pnode->previous_node = plist->tail_node;
    plist->tail_node = pnode;
    ++(plist->length);
  }

  return 0;
}

int main(int argc, char** argv){
  return 0;
}
