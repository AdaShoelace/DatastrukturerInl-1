#include <iostream>
#include "Stack.h"


int main()
{
    Stack<int> stack = Stack<int>();

    stack.push(30);

    stack.printStack();
    stack.push(35);
    
    stack.printStack();

    return 0;
}
