#include "apc.h"

int sign_flag;
char option, operator;
extern Dlist *res1_head;
extern Dlist *res2_head;
int main(int argc, char *argv[])
{
	system("clear");
	/* Respective head and tail for number1,number2 and the result*/
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	
	// validate the given inputs
	if(validations(&head1,&tail1,&head2,&tail2,argv,argc) == 1)
	{
		printf("INFO : READ AND VALIDATE SUCCESS\n");
	}
	else
	{
		printf(RED"ERROR : READ AND VALIDATE FAILED\n"RESET);
		exit(0);
	}

	/*Based on the operator scanned perform the operations*/
	switch (operator)
	{
		case '+':
			/* Call the function to perform addition operation */
			if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			{
				printf("INFO : OPERATION SUCCESSFULL\n");
				printf(GREEN);
				printf("RESULT : ");
				printf(RESET);
				if(sign_flag)								// Sign flag for negative sign, if present after the operation
				{
					printf("-");
				}
				print_list(headR);
			}
			break;
		case '-':
			/*Call the function to perform subtraction operation*/
			if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			{
				printf("INFO : OPERATION SUCCESSFULL\n");
				printf(GREEN);
				printf("RESULT : ");
				printf(RESET);
				if(sign_flag)
					printf("-");
				print_list(headR);
				
			}
			break;
		case 'x':	
			/* call the function to perform the multiplication operation */
			if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			{	
				printf("INFO : OPERATION SUCCESSFULL\n");
				printf(GREEN);
				printf("RESULT : ");
				printf(RESET);
				if(sign_flag)
				{
					printf("-");
					sign_flag = 0;
				}
				print_list(headR);
			}
			break;
		case '/':
			/*Call the function to perform Division Opertion*/	
			if(division(&head1,&tail1,&head2,&tail2,&headR, &tailR) == SUCCESS)
			{
				printf("INFO : OPERATION SUCCESSFULL\n");
				printf(GREEN);
				printf("QUOTIENT : ");
				printf(RESET);
				if(sign_flag)
				{
					printf("-");
					sign_flag = 0;
				}
				print_list(headR);
				printf(GREEN);
				printf("REMAINDER : ");
				printf(RESET);
				print_list(res1_head);				
			}
			break;
		default:
			printf(YELLOW"Invalid Input:-( Try again... COMMAND : ./calc.exe num1 +|-|x|/ num2\n"RESET);
	}
	return 0;
}
