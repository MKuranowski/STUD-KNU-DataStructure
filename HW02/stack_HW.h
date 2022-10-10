#pragma once
#define True 1
#define False 0

typedef char Element;

typedef struct _node
{
	Element data;
	struct _node* link;
} stackNode;

typedef struct _head
{
	int count;
	struct _node* top;
} stackHead;

stackHead* CreateStack();
void DestroyStack(stackHead* pHead);
void push(stackHead* pHead, Element item);
Element pop(stackHead* pHead);
Element stackTop(stackHead* pHead);
int isEmptyStack(stackHead* pHead);
int CompareOper(char op1, char op2);
int PriorityOper(char op);
char* infix2postfix(char* infix);
float evalPostfix(char* postfix);

