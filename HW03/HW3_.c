#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "HW3_.h"


qHead* CreateQueue()
{
	qHead* pq = (qHead*)malloc(sizeof(qHead));
	if (pq == NULL)
		exit(-1);
	
	pq->rear = NULL;
	pq->front = NULL;
	pq->count = 0;

	return pq;
}

void enQueue(qHead* pq, customer* pcus)
{
	// (1) fill this part
}

customer* deQueue(qHead* pq)
{
	if (pq->count == 0)
		exit(-1);
	
	qNode* delNode;
	customer* return_val;

	delNode = pq->front;
	return_val = pq->front->cus;
	pq->front = pq->front->link;
	free(delNode);
	return return_val;
}

customer* queueRear(qHead* pq) 
{
	if (pq->count == 0)
		exit(-1);

	return pq->rear->cus;
}

customer* queueFront(qHead* pq)
{
	if (pq->count == 0)
		exit(-1);

	return pq->front->cus;
}

customer* enterCustomer(int i)
{
	customer* pcus = (customer*)malloc(sizeof(customer));
	pcus->custom_id = i;
	char get_menu;

	switch (rand()%3)
	{
	case 0:
		get_menu = 'A';
		break;
	case 1:
		get_menu = 'B';
		break;
	case 2:
		get_menu = 'C';
		break;
	}

	pcus->menu = get_menu;

	return pcus;
}

