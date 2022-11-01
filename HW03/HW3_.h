#pragma once

typedef struct _customer {
	int custom_id;
	char menu;
}customer;

typedef struct _queueNode {
	customer* cus;
	struct _queueNode* link;
}qNode;

typedef struct _queueHead {
	int count;
	struct _queueNode* rear;
	struct _queueNode* front;
}qHead;

qHead* CreateQueue();
void enQueue(qHead* pq, customer* pcus);
customer* deQueue(qHead* pq);
customer* queueRear(qHead* pq);
customer* queueFront(qHead* pq);

customer* enterCustomer(int i);
