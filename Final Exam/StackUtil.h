#pragma once
#include "Stack.h"


/**
* @brief Creates a new stack.
*
* @return a pointer to the new stack
*
* @note may cause error code 3 if there is a problem with memory allocation
*/
Stack *CreateStack();

/**
* @brief Deletes the given stack.
*
* @param stack the stack to be deleted
*/
void DeleteStack(Stack *stack);

/**
* @brief Pushes the given item into the given stack.
*
* @param stack the given stack
* @param item the item to be pushed
*
* @note may cause error code 2 or 4
*/
void StackPush(Stack *stack, item_t item);

/**
* @brief Pops the top item from the given stack.
*
* @param stack the given stack
*
* @return the top item of the given stack
*
* @note may cause error code 1
*/
item_t StackPop(Stack *stack);

/**
* @brief Returns the last errror code.
*
* @return the last errror code
*
* @note error code  - no error
        error code 1 - trying to pop from empty stack
*       error code 2 unable to push item due to error in memry allocation
*       error code 3 unable to create stack due to error in memry allocation
*       error code 4 tryng to push to a null stack
*/
int StackGetLastError();


/**
* @brief Return the size of the given stack.
*
* @param stack the given stack
*
* @return the size of the given stack
*/
size_t StackSize(Stack *stack);

/**
* @brief Prints the items of the given stack.
*
* @param stack the given stack
*/
void StackPrint(Stack *stack);