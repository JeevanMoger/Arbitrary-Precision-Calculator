#include "apc.h"

extern int sign_flag;
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int compare_val = compare(*head1,*head2);
	if(compare_val == 0)
	{
		dl_insert_first(headR,tailR,0);
		return SUCCESS;
	}
	if(compare_val < 0 )
	{
		swap_lists(head1,tail1,head2,tail2);
		sign_flag = !sign_flag;
	}
	int borrow = 0;
	int num1 = 0, num2 = 0;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 == NULL)
			num1 = 0;
		else
			num1 = temp1 -> data;
		if(temp2 == NULL)
			num2 = 0;
		else
			num2 = temp2 -> data;
		if(borrow == 1)
		{
			num1 = num1 - 1;
		}
		if(num1 < num2)
		{
			num1 = num1 + 10;
			borrow = 1;
		}
		else
			borrow = 0;
		dl_insert_first(headR,tailR,(num1 - num2));
		if(temp1 != NULL)
			temp1 = temp1 -> prev;
		if(temp2 != NULL)
			temp2 = temp2 -> prev;
	}
	delete_leading_zeroes(headR,tailR);
	return SUCCESS;
}



