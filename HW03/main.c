#include <stdio.h>
#include "HW3_.h"

customer* findFirstinCust(qHead* q1, qHead* q2, qHead* q3)
{
	// (4) fill this part
}

int main()
{
	qHead* CafeteriaDesk = CreateQueue();
	for (int i = 0; i < 100; i++)
	{
		customer* pcus = enterCustomer(i+1);
		enQueue(CafeteriaDesk, pcus);
	}


	// (2) fill this part



	printf("%d customers choosen menu A \n", // (3) fill this part);
	printf("%d customers choosen menu B \n", // (3) fill this part);
	printf("%d customers choosen menu C \n", // (3) fill this part);
	


	printf("The first customer selects menu %c\n", // (5) fill this part);
}