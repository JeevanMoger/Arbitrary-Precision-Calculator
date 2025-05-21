#include "apc.h"
#include <stdio.h>


extern char operator;               //varable to store the operator
extern int sign_flag;

/* Function to store a number in a linked list*/
int store_list(char *argv,Dlist **head,Dlist **tail)
{
   for(int i = 0;  argv[i] != '\0' ; i++)
   {
        if(argv[i] >= '0' && argv[i] <= '9')                // the character must be a digit 
        {
            dl_insert_last(head,tail,argv[i] - 48);
        }
        else
        {
            printf(RED"ERROR : %s IS NOT A VALID NUMBER\n"RESET,argv);
            return FAILURE;
        }
   }
   return SUCCESS;
}

/* Function to insert the data at the last of a double linked list*/
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
    new -> data = data;
    new -> next = NULL;
    new -> prev = NULL;
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    (*tail) -> next = new;
    new -> prev = *tail;
    *tail = new;
    return SUCCESS;
}

/*Function to insert at first in a double linked list*/
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
    
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    new -> next = *head;
    (*head) -> prev = new;
    *head = new;
    return SUCCESS;
}

/*Function to print the given list*/
void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
            printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf(" \n");
    }
}

/*Function to delete the data present at the begining of the list*/
int dl_delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return FAILURE;
    Dlist *temp = NULL;

    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    else
    {
        temp = *head;
        *head = (*head) -> next;
        free(temp);
        (*head) -> prev = NULL;
        return SUCCESS; 
    }
}

/*Function to delete the zeroes present at the begining of the list*/
void delete_leading_zeroes(Dlist **head,Dlist **tail)
{
	Dlist *temp = *head;
	while(temp != NULL && temp -> data == 0)
	{
		dl_delete_first(head,tail);
		temp = temp -> next;
	}
	if(*head == NULL)
		dl_insert_first(head,tail,0);
}

/*Function to delete an entire list*/
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return FAILURE;
    while( *head != NULL)
    {
        dl_delete_first(head,tail);
    }
    return SUCCESS;
}

/*Function to get the count of number of elements present in the list*/
int get_count(Dlist *head)
{
	int count = 0;
	while(head != NULL)
	{
		head = head -> next;
		count++;
	}
	return count;
}
/*Function to swap the linked lists*/
void swap_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) 
{
    Dlist *temp_head = *head1;
    Dlist *temp_tail = *tail1;
    *head1 = *head2;
    *tail1 = *tail2;
    *head2 = temp_head;
    *tail2 = temp_tail;
}

/*Function to compare the two lists to find which number is greater*/
int compare(Dlist *head1, Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    int count1 = 0, count2 = 0;
    while (temp1 != NULL) {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
        return 1; 
    if (count1 < count2)
        return -1;

    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data > temp2->data)
            return 1; 
        if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}
/*Function to perform input validations*/
int validations(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[],int argc)
{
    if(argc < 4)
    {
        printf(RED"ERROR : INSUFFICIENT ARGUMENTS\n"RESET);
        printf(YELLOW"Invalid Input:-( Try again... COMMAND : ./calc.exe num1 +|-|x|/ num2\n"RESET);
        return FAILURE;
    }
    operator = *(argv[2]);    
    char *num1 = argv[1];
    char *num2 = argv[3];
    if(num1[0] == '+' || num1[0] == '-')
    {
        if(store_list(&(num1[1]),head1,tail1) == FAILURE)
            return FAILURE;
    }
    else
    {
        if(store_list(num1,head1,tail1) == FAILURE)
            return FAILURE;
    }

    delete_leading_zeroes(head1,tail1);
    if(num2[0] == '+' || num2[0] == '-')
    {
        if(store_list(&(num2[1]),head2,tail2) == FAILURE)
            return FAILURE;
    }
    else
    {
        if(store_list(num2,head2,tail2) == FAILURE)
            return FAILURE;
    }
    delete_leading_zeroes(head2,tail2);
    // find out the sign for addition operation
    if(operator ==  '+')
    {
        if(num1[0] != '-' && num2[0] == '-')
        {
            operator = '-';
            return 1;
        }
        if(num1[0] == '+' && num2[0] == '-')
        {
            operator = '-';
            return 1;
        }
        if(num1[0] == '-' && num2[0] != '-')
        {
            swap_lists(head1,tail1,head2,tail2);
            operator = '-';
            return 1;
        } 
        if(num1[0] == '-' && num2[0] == '-')
        {
            operator = '+';
            sign_flag = 1;
            return 1;
        }
        return 1;
    }
    if(operator == 'x' || operator == '/') // during multiplication or division if any one numbre is negative the resultant sign is negative 
    {
        if((num1[0] != '-' && num2[0] == '-') || (num1[0] == '-' && num2[0] != '-'))
        {
            sign_flag = 1;
            return 1;
        }
        return 1;
    }
    // finding the sign for subtraction operation
    if(operator == '-')
    {
        if(num1[0] != '-' && num2[0] == '-')
        {
            operator = '+';
            sign_flag = 0;
            return 1;
        }
        if(num1[0] == '-' && num2[0] == '-')
        {
            operator = '-';
            sign_flag = 1;
            return 1;
        }
        if(num1[0] == '-' && num2[0] != '-')
        {
            operator = '+';
            sign_flag = 1;
            return 1;
        }
        if(num1[0] != '-' || num2[0] != '-')
        {
            operator = '-';
            sign_flag = 0;
            return 1;
        }
        return 1;
    }
}