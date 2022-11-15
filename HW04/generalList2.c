#include <stdio.h>
#include <stdlib.h>
#include "generalList2.h"


Lhead* createList()
{
	Lhead* plist = (Lhead*)malloc(sizeof(Lhead));

	plist->count = 0;
	plist->front = (Lnode*)malloc(sizeof(Lnode));
	plist->front->link = NULL;
	plist->cur = NULL;
	plist->sort = NULL;
	return plist;

}

void setSortRule(Lhead* plist, int(*comp)(Element item1, Element item2))
{
	plist->sort = comp;
}

void insertion(Lhead* plist, Lnode* pre, Element item)
{
	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) // fail to allocate memory
	{
		printf("Fail to allocate memory\n");
		exit(-1);
	}
	else
		newnode->data = item;

	newnode->link = pre->link;
	pre->link = newnode;

	(plist->count)++;
}



void insertionbyRule(Lhead* plist, Element item)
{

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	// exception handle is emitted due to the page limit
	newnode->data = item;

	if (plist->count == 0)
	{
		insertion(plist, plist->front, item);
	}
	else
	{
		Lnode* temp = plist->front;
		while (temp->link != NULL && plist->sort(item, temp->link->data) != 0)
		{
			temp = temp->link;
		}

		newnode->link = temp->link;
		temp->link = newnode;

		(plist->count)++;
	}
}

Element deletion(Lhead* plist, Lnode* pre)
{
	Lnode* temp;
	Element return_val;

	temp = pre->link;
	return_val = temp->data;

	temp = pre->link;
	pre->link = temp->link;

	(plist->count)--;
	free(temp);
	return return_val;
}

void destroyList(Lhead* plist)
{
	while (plist->count != 0)
	{
		deletion(plist, plist->front);
	}
	free(plist->front);
	free(plist);
}
