#include "function.h"

#define ll long long int

int main(){
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF ){
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}
//
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int n);
void freeList(Node* head);
int solveJosephus(Node **head, int step);

#endif

#include <stdlib.h>
Node *createList(int n)
{
    Node *head, *now, *back;
    head = (Node*)malloc(sizeof(Node));
    now = head;
    for(int i=1;i<=n-1;i++)
    {
        back = (Node*)malloc(sizeof(Node));
        now->number = i;
        now->next = back;
        now = back;
    }
    now->number = n;
    now->next = head;
    return head;
}
void freeList(Node* head)
{
    free(head);
}
int solveJosephus(Node **head, int step)
{
    int ppl = 1, stepmod;
    Node *now, *delete;
    now = *head;    
    while(now->next != *head)
    {
        ppl++;
        now = now->next;
    }
    if(ppl == 1) return (*head)->number;
    stepmod = step % ppl;
    if(stepmod == 0) stepmod = ppl;
    for(int i=0;i<stepmod-1;i++) now = now->next;
    delete = now->next;
    now->next = delete->next;
    free(delete);
    *head = now->next;
    return solveJosephus(head,step); 
}
//
