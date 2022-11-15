#pragma once

#define True 1
#define False 0

typedef struct _point
{
	float x;
	float y;
}Point;

typedef Point* Element;

typedef struct _node
{
	Element data;
	struct _node* link;
}Lnode;

typedef struct _head
{
	Lnode* front;
	Lnode* cur;
	int count;
	int (*sort)(Element item1, Element item2);
}Lhead;

Lhead* createList();

void insertion(Lhead* plist, Lnode* pre, Element item);

Element deletion(Lhead* plist, Lnode* pre);
void destroyList(Lhead* plist);
void setSortRule(Lhead* plist, int(*comp)(Element item1, Element item2));


void insertionbyRule(Lhead* plist, Element item);

