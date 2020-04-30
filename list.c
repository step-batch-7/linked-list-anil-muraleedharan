#include<stdlib.h>
#include<stdio.h>
#include"list.h"

Node *create_node(int value)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List *create_list(void)
{
  List *list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node *new_node = create_node(value);
  list->count++;
  if(list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
    return Success;
  }
  list->last->next = new_node;
  list->last = new_node;
  return Success;
}

void display(List_ptr list)
{
  Node *p_walk = list->head;
  while(p_walk != NULL)
  {
    printf("%d  ", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list){
  Node *p_walk = list->head;
  while(p_walk != NULL){
    Node *next = p_walk->next;
    free(p_walk);
    p_walk = next;
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  if(clear_list(list)){
    free(list);
  }
}