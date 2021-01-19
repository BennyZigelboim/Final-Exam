#include <stdio.h>
#include "StackUtil.h"


int main(void)
{
    Stack *stack = CreateStack();

    StackPush(stack, 1);
    StackPush(stack, 2);
    StackPush(stack, 3);

    StackPop(stack);

    StackPrint(stack);

    DeleteStack(stack);

    return 0;
}


