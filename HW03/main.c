/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-11-01
 * Course: Data Structure
 */
#include <assert.h>
#include <stdio.h>
#include "HW3_.h"

customer* findFirstinCust(qHead* qA, qHead* qB, qHead* qC)
{
	// Since the we're looking for the 1st customer - it must be at the front
	// of some menu queue.
	if (queueFront(qA)->custom_id == 1) {
		// The first customer is in queue A
		return queueFront(qA);
	} else if (queueFront(qB)->custom_id == 1) {
		// The first customer is in queue B
		return queueFront(qB);
	} else if (queueFront(qC)->custom_id == 1) {
		// The first customer is in queue C
		return queueFront(qC);
	}

	assert(0 && "Customer 1 is not at the front of any menu queue");
}

int main()
{
	qHead* CafeteriaDesk = CreateQueue();
	for (int i = 0; i < 100; i++)
	{
		customer* pcus = enterCustomer(i+1);
		enQueue(CafeteriaDesk, pcus);
	}

	qHead* menu_a = CreateQueue();
	qHead* menu_b = CreateQueue();
	qHead* menu_c = CreateQueue();

	// Loop while there are customers waiting
	while (CafeteriaDesk->count) {
		customer* c = deQueue(CafeteriaDesk);

		// Select the appropiate queue by customers menu
		qHead* menu_queue = NULL;
		switch (c->menu) {
			case 'A':
				menu_queue = menu_a;
				break;
			case 'B':
				menu_queue = menu_b;
				break;
			case 'C':
				menu_queue = menu_c;
				break;
			default:
				assert(0 && "invalid customer menu");
		}

		// Add the customer to the menu-specific queue
		enQueue(menu_queue, c);
	}

	printf("%d customers choosen menu A \n", menu_a->count);
	printf("%d customers choosen menu B \n", menu_b->count);
	printf("%d customers choosen menu C \n", menu_c->count);

	printf("The first customer selects menu %c\n", findFirstinCust(menu_a, menu_b, menu_c)->menu);
}
