#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack_HW.h"

stackHead* CreateStack()
{
	stackHead* pHead = (stackHead*)malloc(sizeof(stackHead));
	if (pHead == NULL) //fail to allocate memory for stack head
		return NULL;

	pHead->count = 0;
	pHead->top = NULL;
	return pHead;
};
void DestroyStack(stackHead* pHead)
{
	if (pHead->top == NULL)
		free(pHead);
	else
	{
		stackNode* temp;
		while (pHead->top != NULL)
		{
			temp = pHead->top;
			pHead->top = pHead->top->link;
			free(temp);
		}
		free(pHead);
	}
};
void push(stackHead* pHead, Element item)
{
	stackNode* pNode = (stackNode*)malloc(sizeof(stackNode));
	if (pNode == NULL) //fail to allocate memory for new stack node
		exit(-1);

	pNode->data = item;
	pNode->link = pHead->top;
	pHead->top = pNode;
	pHead->count++;
};

Element pop(stackHead* pHead)
{
	if (pHead->count == 0) //empty stack
	{
		printf("stack is empty\n");
		return 0;
	}
	else
	{
		Element top_item = pHead->top->data;
		stackNode* pOldTop = pHead->top;
		pHead->top = pOldTop->link;
		free(pOldTop);

		pHead->count--;
		return top_item;
	}
};

int isEmptyStack(stackHead* pHead)
{
	if (pHead->count == 0)
		return True;
	else
		return False;
};
int PriorityOper(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 1;
	}
	return -1;
};
int CompareOper(char op1, char op2)
{
	int op1_pri = PriorityOper(op1);
	int op2_pri = PriorityOper(op2);
	if (op1_pri > op2_pri)
		return 1;
	else if (op1_pri < op2_pri)
		return -1;
	else
		return 0;
};
char* infix2postfix(char *infix)
{
	int length = strlen(infix);
	char* postfix = (char*)malloc(length + 1);
	stackHead* pHead = CreateStack();
	Element token;
	int index_postfix = 0;
	Element topOper;
	int compare_oper;

	for (int i = 0; i < length; i++)
	{
		token = infix[i];
		if (isdigit(token))
		{
			postfix[index_postfix] = token;
			index_postfix++;
		}
		else
		{
			if (pHead->top == NULL)
				push(pHead, token);
			else
			{
				topOper = stackTop(pHead);
				compare_oper = CompareOper(topOper, token);
				if (compare_oper == 1)
				{
					while (pHead->count != 0)
					{
						Element temp = pop(pHead);
						postfix[index_postfix] = temp;
						index_postfix++;
					}
				}
				else
					push(pHead, token);
			}
		}
	}
	while (pHead->count != 0)
	{
		Element temp = pop(pHead);
		postfix[index_postfix] = temp;
		index_postfix++;
	}
	postfix[index_postfix] = '\0';
	DestroyStack(pHead);
	return postfix;
};

int char2int(char op)
{
	if (isdigit(op))
		return op - '0';
	else
	{
		printf("can't be converted to an integer\n");
		exit(-1);
	}
};


////////////// HW2 : complete the following functions ///////////////
/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-10-12
 * Course: Data Structure
 */

Element stackTop(stackHead* pHead)
{
	// Check if there's an element on the stack
	if (pHead->count < 1) {
		fputs("stackTop called with empty stack", stderr);
		abort();
	}

	// Return the head's value
	return pHead->top->data;
};

float evalPostfix(char* postfix)
{
	// Create a stack for the operands
	stackHead* stack = CreateStack();

	// Iterate over characters of the string
	for (char* p = postfix; *p; ++p) {
		// Get the current character
		char c = *p;

		if (isdigit(c)) {
			// c is a digit - push its value onto the stack
			push(stack, c - '0');
		} else {
			// Otherwise - assume that c is a an operator

			// Pop 2 operands from the stack
			int n2 = pop(stack);
			int n1 = pop(stack);
			int result;

			// Perform the operation
			switch (c) {
				case '+':
					result = n1 + n2;
					break;

				case '-':
					result = n1 - n2;
					break;

				case '/':
					result = n1 / n2;
					break;

				case '*':
					result = n1 * n2;
					break;

				default:
					// Invalid operator - halt the program
					fprintf(stderr, "invalid operator: %c\n", c);
					abort();
			}

			// Push the result onto the stack
			push(stack, result);
		}
	}

	// After all the calculations - pop the result from the stack
	float result = pop(stack);

	// Deallocate stack resources
	DestroyStack(stack);

	return result;
}

