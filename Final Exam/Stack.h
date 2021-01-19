#pragma once

typedef int item_t;

typedef struct Node_t
{
    item_t item;
    struct Node_t *next;
} Node;

typedef struct Stack_t
{
    Node *root;
} Stack;