/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-11-01
 * Course: Data Structure
 */
#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>  // NOTE: This header is not standard and doesn't exist on some OSs
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

void enQueue(qHead* pq, customer* pcus) {
	// Create a new containing the customer
	qNode* new_node = malloc(sizeof(qNode));
	new_node->cus = pcus;
	new_node->link = NULL;

	if (pq->count == 0) {
		// If the queue is empty - set the front and rear to the new node
		pq->front = new_node;
		pq->rear = new_node;
	} else {
		// Otherwise - append the new node to the end of the queue
		pq->rear->link = new_node;
		pq->rear = new_node;
	}

	// Increase the amount of elements in the queue
	++pq->count;
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

	// NOTE: This part was missing
	--pq->count;

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

