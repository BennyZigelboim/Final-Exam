#include <stdio.h>
#include "StackUtil.h"
#include <malloc.h>
const char *ITEM_PRINTING_FORMAT = "item = %d\n";

static int lastErrorCode = 0;

Stack *CreateStack()
{
    Stack *stackPointer = malloc(sizeof(Stack));

    if (stackPointer != NULL)
    {
        stackPointer->root = NULL;
    }

    else
    {
        stackPointer = NULL;
        lastErrorCode = 3;
    }
    
    return stackPointer;
}

void DeleteStack(Stack *stack)
{
    if (stack == NULL || stack->root == NULL)
    {
        return;
    }

    Node *nodeToDelete = stack->root;
    Node *next = stack->root->next;

    do
    {
        free(nodeToDelete);
        nodeToDelete = next;
        next = nodeToDelete->next;

    } while (next != NULL);
    free(nodeToDelete);
    stack->root = NULL;
}

void StackPush(Stack *stack, item_t item)
{
    if (stack == NULL)
    {
        lastErrorCode = 4;
        return;
    }
    else
    {
        Node *newRoot = malloc(sizeof(Node));
        if (newRoot != NULL)
        {
            newRoot->item = item;
            newRoot->next = stack->root;
            stack->root = newRoot;
        }
        else
        {
            lastErrorCode = 2;
        }
    }
}

item_t StackPop(Stack *stack)
{
    if (stack == NULL || stack->root == NULL)
    {
        lastErrorCode = 1;

        return -1;
    }

    else
    {
        item_t res = stack->root->item;
        Node *newRoot = stack->root->next;
        free(stack->root);
        stack->root = newRoot;

        return res;
    }
}

int StackGetLastError()
{
    return lastErrorCode;
}

size_t StackSize(Stack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    size_t size = 0;

    Node *nodePointer = stack->root;

    while (nodePointer != NULL)
    {
        size++;
        nodePointer = nodePointer->next;
    }

    return size;
}

void StackPrint(Stack *stack)
{
    if (stack == NULL || stack->root == NULL)
    {
        return;
    }

    Node *nodePointer = stack->root;

    while (nodePointer != NULL)
    {
        printf_s(ITEM_PRINTING_FORMAT, nodePointer->item);
        nodePointer = nodePointer->next;
    }
}
