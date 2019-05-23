#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
    int element;
    struct Deque *prev,*next;
}Deque;

Deque* makeNode(int val)
{
    Deque* node = (Deque*)malloc(sizeof(Deque));
    node->element = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void push_front(Deque** front, Deque** back, int newValue);
void push_back(Deque** front, Deque** back, int newValue);
void pop_front(Deque** front, Deque** back);
void pop_back(Deque** front, Deque** back);
void printAll(Deque* currentFront);
void printFront(Deque* currentFront);
void printBack(Deque* currentBack);

int main()
{
    Deque *front=0, *back=0;
    push_front(&front,&back,10);
    push_front(&front,&back,5);
    push_back(&front,&back,20);
    push_back(&front,&back,25);

    printFront(front);
    printBack(back);
    printAll(front);

    pop_front(&front,&back);
    pop_front(&front,&back);

    printf("\n");

    printFront(front);
    
    pop_back(&front,&back);
    printBack(back);

    printAll(front);
}

void push_front(Deque** front, Deque** back, int newValue)
{
    Deque* newFront = makeNode(newValue);

    if (*front == NULL && *back == NULL)
    {
        *front = *back = newFront;
    }
    else
    {
        (*front)->prev = newFront;
        (*front)->prev->next = *front;
        *front = newFront;
    }
}

void push_back(Deque** front, Deque** back, int newValue)
{
    Deque* newBack = makeNode(newValue);

    if (*front == NULL && *back == NULL)
    {
        *front = *back = newBack;
    }
    else
    {
        (*back)->next = newBack;
        (*back)->next->prev = newBack;
        *back = newBack;
    }
}

void pop_front(Deque** front, Deque** back)
{
    Deque* originFront = *front;

    if (*front == NULL && *back == NULL)
    {
        printf("Error: runtime error");        
        return;
    }
    else 
    {
        if (*front == *back)
        {
            *front = *back = NULL;
        }
        else
        {
            *front = originFront->next;
            (*front)->prev = originFront->prev;
        }
        free(originFront);
    }
}

void pop_back(Deque** front, Deque** back)
{
    Deque* originBack = *back;

    if (*front == NULL && *back == NULL)
    {
        printf("Error: runtime error");
        return;
    }
    else 
    {
        if (*front == *back)
        {
            *front = *back = NULL;
        }
        else
        {
            *back = originBack->prev;
            (*back)->next = originBack->next;
        }
        free(originBack);
    }
}

void printAll(Deque* currentFront)
{
    while (currentFront != NULL)
    {
        printf("%d ", currentFront->element);
        currentFront = currentFront->next;
    }
    printf("\n");
}

void printFront(Deque* currentFront)
{
    printf("%d\n", currentFront->element);
}

void printBack(Deque* currentBack)
{
    printf("%d\n", currentBack->element);
}