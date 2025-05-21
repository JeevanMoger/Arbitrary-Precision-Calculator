#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdlib.h>
#include <stdio.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

#define RESET   "\033[0m"  
#define RED     "\033[1;31m" 
#define GREEN   "\033[1;32m" 
#define YELLOW  "\033[1;33m"
/* Include the prototypes here */

/* Function prototypes for addition, subtraction, multiplication and division*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Helper Functions*/
int get_count(Dlist *head);
int list_compare(Dlist *head1, Dlist *head2);
void swap_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
void delete_leading_zeroes(Dlist **head,Dlist **tail);
int store_list(char *argv,Dlist **head,Dlist **tail);
int compare(Dlist *tail1 , Dlist *tail2);
int validations(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[],int argc);

/* List Operations */
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_delete_first(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
int dl_delete_list(Dlist **head, Dlist **tail);

#endif
