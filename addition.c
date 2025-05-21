#include "apc.h"

//Function to perform the division operation
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0;
	int num1 = 0, num2 = 0,sum = 0;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	while(temp1 != NULL || temp2 != NULL)
	{
		sum = 0;

		// Take numbers from the lists one by one and perform the operation 

		if(temp1 == NULL)					
			num1 = 0;
		else
			num1 = temp1 -> data;
		if(temp2 == NULL)
			num2 = 0;
		else
			num2 = temp2 -> data;

		sum = num1 + num2 + carry;

		//If sum > 9 then seperate carry from the sum and add the units place digit to the result
		if(sum > 9)
		{
			carry = (sum / 10) % 10;
			dl_insert_first(headR,tailR,sum % 10);
		}
		else
		{
			carry = 0;
			dl_insert_first(headR,tailR,sum);
		}
		// Traverse if temp not equal to NULL
		if(temp1 != NULL)
			temp1 = temp1 -> prev;
		if(temp2 != NULL)
			temp2 = temp2 -> prev;
	}
	if(carry)
		dl_insert_first(headR,tailR,carry);
	
	return SUCCESS;
}
