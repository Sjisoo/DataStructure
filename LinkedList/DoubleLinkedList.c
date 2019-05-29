#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int element;
    struct ListNode *prev, *next;
}ListNode;

ListNode* makeNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->element = val;
    node->prev = node->next = NULL;
    return node;
}

void addNode(ListNode** head, int newValue);
void deleteNode(ListNode** head, int value);
void peek(ListNode* ptr);
void insert(ListNode** head, int beforeValue, int newValue);
// void recoverNode(ListNode** node);

int main()
{
    ListNode *head = 0;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    addNode(&head, 60);
    peek(head);
    deleteNode(&head, 60);
    peek(head);
    // recoverNode(&head);
    deleteNode(&head, 30);
    peek(head);
    deleteNode(&head, 10);
    insert(&head, 40, 45);
    peek(head);
    printFront(head);
}

void addNode(ListNode** head, int newValue)
{
    // 노드 생성
    ListNode* node = makeNode(newValue);

    if (!(*head))
    {
        // head node에 값이 없을 경우
        *head = node;
    }
    else if ((*head)->next == NULL)
    {
        // 마지막 위치의 node일 경우
        node->prev = *head;
        (*head)->next = node;
        *head = node;
    }
    else
    {
        addNode(&(*head)->next,newValue);
    }
}

void deleteNode(ListNode** head, int value)
{
    if (*head == NULL)
    {
        // 현재 head node에 값이 없을 경우
        return;
    }
    else if ((*head)->element == value)
    {
        // 원래의 head 따로 저장
        ListNode* originHead = *head;

        if (!(*head)->prev && !(*head)->next)
        {
            // head node 하나일 경우 
            // prev, next 아무 것도 없음
            *head = NULL;
        }
        else if (!(*head)->prev && (*head)->next)
        {
            // next만 있을 경우 (맨 앞 노드)
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(originHead);
        }
        else if ((*head)->prev && !(*head)->next)
        {
            // prev만 있을 경우 (맨 끝 노드)
            *head = (*head)->prev;
            (*head)->next = originHead->next;
            free(originHead);
        }
        else
        {
            // next,prev 모두 있을 경우 (중간 노드)
            *head = (*head)->next;
            (*head)->prev = originHead->prev;
            free(originHead);

            /* 
            궁금한 점!
            중간 노드를 빼면 prev, next 노드들의 next, prev 포인터 변경 해줘야 함
            하지만, 아래 코드 작성 시 두 개의 데이터 삭제 됨
            -> free를 하면 자동적으로 originHead->prev->next = originHead->next가 되는 것?

            (*head)->prev->next = (*head)->next;
            (*head)->next->prev = (*head)->prev;
            *head = (*head)->next;
            */
        }
    }
    else
    {
        // 삭제할 value와 현재 head의 element가 다를 경우
        deleteNode(&(*head)->next, value);
    }
    
}

void insert(ListNode** head, int beforeValue, int newValue)
{
    ListNode* newNode = makeNode(newValue);
    ListNode* originNowNode = *head;

    if ((*head) == NULL)
    {
        *head = newNode;
    }
    else if ((*head)->element == beforeValue)
    {
        newNode->next = originNowNode->next;
        newNode->prev = originNowNode;

        originNowNode->next = newNode;
        originNowNode->next->prev = newNode;
    }
    else
    {
        return insert(&(*head)->next,beforeValue,newValue);
    }   
}

void peek(ListNode* ptr)
{
    ListNode* current = ptr;
    while (current != NULL)
    {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}

// void recoverNode(ListNode** node)
// {
//     (*node)->prev->next = (*node)->element;
//     (*node)->next->prev = (*node)->element;
// }