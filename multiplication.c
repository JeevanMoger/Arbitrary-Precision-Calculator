#include "apc.h"
#include <stdio.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0;
	int num1, num2 , prod = 0;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	Dlist *res1_head = NULL;
	Dlist *res1_tail = NULL;
	Dlist *res2_head = NULL;
	Dlist *res2_tail = NULL;	
	Dlist *res3_head = NULL;
	Dlist *res3_tail = NULL;
	int count = get_count(*head2);
	int count1 = 0;
	while(temp2 != NULL)
	{
		num1 = temp2 -> data;
		temp1 = *tail1;
		carry = 0;
		while (temp1 != NULL)
		{
			num2 = temp1 -> data;
			prod = 0;
			prod = num1 * num2 + carry;
			if(prod > 9)
			{
				
				carry = (prod / 10);
				dl_insert_first(&res1_head,&res1_tail,prod % 10);
			}
			else
			{
				carry  = 0;
				dl_insert_first(&res1_head,&res1_tail,prod);
			}
			temp1 = temp1 -> prev;
		}
		count1++;
		if(carry)
			dl_insert_first(&res1_head,&res1_tail,carry);
		addition(&res1_head,&res1_tail,&res2_head,&res2_tail,&res3_head,&res3_tail);

		dl_delete_list(&res1_head,&res1_tail);
		
		res2_head = res3_head;
		res2_tail = res3_tail;
		res1_head = NULL;
		res1_tail = NULL;
		res3_head = NULL;
		res3_tail = NULL;
		if(count1 > 0 && count1 < count)
		{
			for(int i = 0; i < count1 ; i++)
			{
				dl_insert_first(&res1_head,&res1_tail,0);
			}
		}
		temp2 = temp2 -> prev;
	}
	*headR = res2_head;
	*tailR = res2_tail;
	return SUCCESS;
}
