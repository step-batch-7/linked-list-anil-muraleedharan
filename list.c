#include<stdlib.h>
#include<stdio.h>
#include"list.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
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

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  list->count++;
  if(list->head == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if(position > list->count)
  {
    return Failure;
  }
  if(position == 0)
  {
    return add_to_start(list, value);
  }
  int count = 0;
  Node_ptr p_walk = list->head;
  Node_ptr place_to_add = list->head;
  while (count < position)
  {
    place_to_add = p_walk;
    p_walk = p_walk->next;
    count++;
  }
  Node_ptr to_be_added = create_node(value);
  to_be_added->next = place_to_add->next;
  place_to_add->next = to_be_added;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value == value)
    {
      return Failure;
    }
    p_walk = p_walk->next;
  }
  return add_to_end(list, value);
}

Status remove_from_start(List_ptr list)
{
  if(list->count == 0)
  {
    return Failure;
  }
  list->count--;
  Node_ptr element_to_remove = list->head;
  list->head = element_to_remove->next;
  free(element_to_remove);
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if(list->count == 0)
  {
    return Failure;
  }
  if(list->count == 1)
  {
    return clear_list(list);
  }
  list->count--;
  Node_ptr p_walk = list->head;
  Node_ptr last;
  int count = 0;
  while (count < list->count)
  {
    last = p_walk;
    p_walk = p_walk->next;
    count++;
  }
  last->next = NULL;
  list->last = last;
  free(p_walk);
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if(list->count == 0 || position > list->count - 1)
  {
    return Failure;
  }
  if(position == 0)
  {
    return remove_from_start(list);
  }
  int count = 0;
  Node_ptr p_walk = list->head;
  while (count < position - 1)
  {
    p_walk = p_walk->next;
    count++;
  }
  Node_ptr to_be_freed = p_walk->next;
  int value = to_be_freed->value;
  p_walk->next = to_be_freed->next;
  free(to_be_freed);
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      return remove_at(list, position);
    }
    p_walk = p_walk->next;
    position++;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;
  Status status = Failure;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      remove_at(list, position);
      status = Success;
      position--;
    }
    p_walk = p_walk->next;
    position++;
  }
  return status;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while(p_walk != NULL)
  {
    printf("%d  ", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while(p_walk != NULL){
    Node_ptr next = p_walk->next;
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