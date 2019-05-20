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
    // 노드 생성
    ListNode* node = makeNode(newValue);

    if (!(*head))
    {
        // head node에 데이터가 없을 경우
        *head = node;    
    }
    else if ((*head)->next == NULL)
    {
        // 마지막 위치의 node일 경우
        (*head)->next = node;
    }
    else
    {
        // 마지막 위치가 나올 때까지 next 포인터 변경
        addNode(&(*head)->next,newValue);
    }
}

void deleteNode(ListNode** head, int value)
{
    ListNode* originNode = *head;

    if (!(*head))
    {
        // 현재 head node에 값이 없을 경우
        return;
    }
    else if ((*head)->element == value && !((*head)->next))
    {
        // next 노드가 없을 경우 (맨 뒤 노드)
        *head = NULL;
    }
    else if ((*head)->element == value && ((*head)->next))
    {
        // next 노드가 있을 경우
        *head = originNode->next;
        free(originNode);
    }
    else
    {
        // 삭제할 value와 현재 head의 element가 다를 경우
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