#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int element;
    struct Stack *link;
}Stack;

Stack* makeNode(int val)
{
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->element = val;
    node->link = NULL;
    return node;
}

void push(Stack** top, int newValue);
void pop(Stack** top);
void print(Stack* currentTop);
void stack_top(Stack* currentTop);

int main()
{
    Stack* top = 0;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    stack_top(top);
    push(&top,40);
    push(&top,50);
    push(&top,60);
    print(top);
    pop(&top);
    print(top);
    pop(&top);
    print(top);
}

void push(Stack** top, int newValue)
{
    Stack* originTop = *top;
    *top = makeNode(newValue);
    (*top)->link = originTop;
}

void pop(Stack** top)
{
    if ((*top) == NULL)
    {
        printf("Error: runtime error");
        return;
    }
    else
    {
        Stack* originTop = *top;
        *top = originTop->link;
        free(originTop);
    }
}

void stack_top(Stack* currentTop)
{
    if (!currentTop)
    {
        printf("Error: runtime error");
        return;
    }
    else
    {
        printf("%d\n",currentTop->element);
    }
}

void print(Stack* currentTop)
{
    while (currentTop != NULL)
    {
        printf("%d ", currentTop->element);
        currentTop = currentTop->link;
    }
    printf("\n");
}