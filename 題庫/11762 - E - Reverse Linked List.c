#include <stdio.h>
#include <stdlib.h>
#include "function.h"
Node* Create_List(Node* head, int newdata)
{
	if(head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = newdata;
		head->next = NULL;
		return head;
	}
	Node *p = head;
	while(p->next != NULL) p = p->next;
	p->next = (Node*)malloc(sizeof(Node));
	p->next->data = newdata;
	p->next->next = NULL;
	return head;
}
Node* Reverse_List(Node* head)
{
	Node *pfront = head, *p = head->next, *pback;
	head->next = NULL;
	while(p !=NULL)
	{
		pback = p->next;
		p->next = pfront;
		pfront = p;
		p = pback;
	}
	return pfront;
}
void Print_List(Node* head)
{
	while(head->next != NULL)
	{
		printf("%d->",head->data);
		head = head->next;
	}
	printf("%d\n",head->data);
}
void Free_List(Node* head)
{
	Node *back;
	while(head != NULL)
	{
		back = head->next;
		free(head);
		head = back;
	}
}
