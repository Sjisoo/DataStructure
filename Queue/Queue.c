#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int element;
    struct Queue* link;
}Queue;

Queue* makeNode(int val)
{
    Queue* node = (Queue*)malloc(sizeof(Queue));
    node->element = val;
    node->link = NULL;
    return node;
}

void push(Queue** front, Queue** rear, int newValue);
void pop(Queue** front, Queue** rear);
void queue_front(Queue* currentFront);
void print(Queue* currentFront);

int main()
{
    Queue *head=0, *tail=0;
    push(&head,&tail,10);
    push(&head,&tail,20);
    push(&head,&tail,30);
    push(&head,&tail,40);
    push(&head,&tail,50);
    push(&head,&tail,60);
    print(head);
    queue_front(head);
    pop(&head,&tail);
    print(head);
    pop(&head,&tail);
    print(head);
    pop(&head,&tail);
    print(head);
}

void push(Queue** front, Queue** rear, int newValue)
{
    Queue* newTail = makeNode(newValue);
    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = newTail;
    }
    else
    {
        // link -> 다음 노드의 주소
        (*rear)->link = newTail;
        *rear = newTail;
    }
}

void pop(Queue** front, Queue** rear)
{
    Queue* originFront = *front;
    if (*front == NULL && *rear == NULL)
    {
        printf("Error: runtime error");
        return;        
    }
    else 
    {
        if (*front == *rear)
        {
            *front = *rear = NULL;
        }
        else
        {
            *front = originFront->link;
        }
        free(originFront);
    }
    
}

void queue_front(Queue* currentFront)
{
    if (!currentFront)
    {
        printf("Error: runtime error");
        return;
    }
    else
    {
        printf("%d\n", currentFront->element);
    }
}

void print(Queue* currentFront)
{
    while (currentFront != NULL)
    {
        printf("%d ", currentFront->element);
        currentFront = currentFront->link;
    }
    printf("\n");
}