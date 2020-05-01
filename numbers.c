#include"list.h"
#include<stdio.h>
#include<stdlib.h>

char get_option(void)
{
  fflush(stdin);
  char option;
  system("clear");
  printf("%s", Message);
  option = getchar();
  return option;
}

int main(void)
{
  List_ptr list = create_list();
  char option = get_option();
  while (option != 'm')
  {
    int number;
    int position;
    Status status;
    switch (option)
    {
      case 'a':
      //add a number to the end of the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      add_to_end(list, number);
      break;

      case 'b':
      //add a number to the start of the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      add_to_start(list, number);
      break;

      case 'c':
      //insert a number at a given position in the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      printf("\nEnter the position to add : ");
      scanf("%d", &position);
      status = insert_at(list, number, position);
      if(!status)
      {
        printf("\nNot possible to add at this position.");
      }
      break;

      case 'd':
      //add a unique item on the list at the end(if it already exists, do not insert)
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      status = add_unique(list, number);
      if(!status)
      {
        printf("\nThis number is already exist in list.");
      }
      break;

      case 'e':
      //remove a number from the beginning of the list
      status = remove_from_start(list);
      if(!status)
      {
        printf("\nThere is no elements to remove");
      }
      break;

      case 'f':
      //remove a number from the end of the list
      status = remove_from_end(list);
      if(!status)
      {
        printf("\nThere is no elements to remove");
      }
      break;

      case 'g':
      //remove a number from a given position in the list
      printf("\nEnter the position to remove : ");
      scanf("%d", &position);
      status = remove_at(list, position);
      if(!status)
      {
        printf("\nNot possible to remove from this position.");
      }
      break;

      case 'h':
      //remove first occurrence of a number
      break;

      case 'i':
      //remove all occurrences of a number
      break;

      case 'j':
      //clear the whole list
      clear_list(list);
      break;

      case 'k':
      //check if a number exists in the list
      break;

      case 'l':
      //display the list of numbers
      display(list);
      break;

      default:
      printf("\nUnexpected input try again");
      break;
    }
    option = get_option();
  }
  destroy_list(list);
  return 0;
}