#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int element;
    struct ListNode *next;
}ListNode;

ListNode* makeNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->element = val;
    node->next = NULL;
    return node;
}

void addNode(ListNode** head, int newValue);
void deleteNode(ListNode** head, int value);
void peek(ListNode* ptr);

int main()
{
    ListNode* head = 0;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    addNode(&head, 60);
    peek(head);
    deleteNode(&head, 60);
    peek(head);
    deleteNode(&head, 30);
    peek(head);
    deleteNode(&head, 10);
    peek(head);
}

void addNode(ListNode** head, int newValue)
{
    ListNode* node = makeNode(newValue);

    if (!(*head))
    {
        *head = node;    
    }
    else if ((*head)->next == NULL)
    {
        (*head)->next = node;
    }
    else
    {
        addNode(&(*head)->next,newValue);
    }
}

void deleteNode(ListNode** head, int value)
{
    ListNode* originNode = *head;

    if (!(*head))
    {
        return;
    }
    else if ((*head)->element == value && !((*head)->next))
    {
        *head = NULL;
    }
    else if ((*head)->element == value && ((*head)->next))
    {
        *head = originNode->next;
        free(originNode);
    }
    else
    {
        deleteNode(&(*head)->next,value);
    }
}

void peek(ListNode* ptr)
{
    ListNode* current = ptr;
    while (current != NULL)
    {
        printf("%d ",current->element);
        current = current->next;
    }
    printf("\n");    
}