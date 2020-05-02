#include"list.h"
#include<stdio.h>
#include<stdlib.h>

char get_option(void)
{
  fflush(stdin);
  char option;
  printf("%s", Main_Menu);
  option = getchar();
  return option;
}

void clear_screen_and_print_message(Char_ptr message)
{
  system("clear");
  printf("%s", message);
}

int main(void)
{
  List_ptr list = create_list();
  char option = get_option();
  while (option != 'm')
  {
    int number;
    int position;
    Char_ptr message;
    Status status;
    switch (option)
    {
      case 'a':
      //add a number to the end of the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      status =  add_to_end(list, number);
      message = status ? "\nDone.\n" : "\nNumber could not be added.\n";
      clear_screen_and_print_message(message);
      break;

      case 'b':
      //add a number to the start of the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      status =  add_to_start(list, number);
      message = status ? "\nDone.\n" : "\nNumber could not be added.\n";
      clear_screen_and_print_message(message);
      break;

      case 'c':
      //insert a number at a given position in the list
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      printf("\nEnter the position to add : ");
      scanf("%d", &position);
      status = insert_at(list, number, position);
      message = status ? "\nDone.\n" : "\nNot possible to add at this position.\n";
      clear_screen_and_print_message(message);
      break;

      case 'd':
      //add a unique item on the list at the end(if it already exists, do not insert)
      printf("\nEnter the number to add : ");
      scanf("%d", &number);
      status = add_unique(list, number);
      message = status ? "\nDone.\n" : "\nNot possible to add this number.\n";
      clear_screen_and_print_message(message);
      break;

      case 'e':
      //remove a number from the beginning of the list
      status = remove_from_start(list);
      message = status ? "\nDone.\n" : "\nThere is no element to remove.\n";
      clear_screen_and_print_message(message);
      break;

      case 'f':
      //remove a number from the end of the list
      status = remove_from_end(list);
      message = status ? "\nDone.\n" : "\nThere is no element to remove.\n";
      clear_screen_and_print_message(message);
      break;

      case 'g':
      //remove a number from a given position in the list
      printf("\nEnter the position to remove : ");
      scanf("%d", &position);
      status = remove_at(list, position);
      message = status ? "\nDone.\n" : "\nNot possible to remove from this position.\n";
      clear_screen_and_print_message(message);
      break;

      case 'h':
      //remove first occurrence of a number
      printf("\nEnter the number to remove : ");
      scanf("%d", &number);
      status = remove_first_occurrence(list, number);
      message = status ? "\nDone.\n" : "\nThis number does not exist in the list.\n";
      clear_screen_and_print_message(message);
      break;

      case 'i':
      //remove all occurrences of a number
      printf("\nEnter the number to remove : ");
      scanf("%d", &number);
      status = remove_all_occurrences(list, number);
      message = status ? "\nDone.\n" : "\nThis number does not exist in the list.\n";
      clear_screen_and_print_message(message);
      break;

      case 'j':
      //clear the whole list
      clear_list(list);
      break;

      case 'k':
      //check if a number exists in the list
      printf("\nEnter the number to check : ");
      scanf("%d", &number);
      status = is_element_exist(list, number);
      message = status ? "\nThe number exist in the list.\n" : "\nThe number does not exist in the list.\n";
      clear_screen_and_print_message(message);
      break;

      case 'l':
      //display the list of numbers
      system("clear");
      printf("\nElements : ");
      display(list);
      break;

      default:
      message = "\nUnexpected input try again\n";
      clear_screen_and_print_message(message);
      break;
    }
    option = get_option();
  }
  destroy_list(list);
  return 0;
}