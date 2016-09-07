#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T>
class Stack 
{
    public:
        Stack();
        void push(T data);
        T pop();
        //ta bort innan inlämning
        void printStack();
    private:
        int size; 

        struct Node
        {
            T data;
            Node* next;
        };

        Node* head;
        Node* current;
        Node* tail;
};

template<class T>
Stack<T>::Stack()
{
    head = 0;
    current = 0;
    tail = 0;
}


template<class T>
void Stack<T>::push(T data)
{
    Node* n = new Node;
    n->data = data;
    n->next = 0;

    if(0 != head)
    {
        current = n;
        current->next = head;
        head = current;
        tail->next = head;
    }
    else
    {
        head = n;
        tail = n;
    }
    size++;
}

//ta bort innan inlämning
template<class T>
void Stack<T>::printStack()
{

    int index = 0; 

    if(0 != head)
    {
        current = head;
        
        while(current->next != head && current->next != 0)
        {
            std::cout << index << ": " << current->data << std::endl;
            current = current->next;

            index++;
        }
    }

    else
    {
        std::cout << "The stack is empty!" << std::endl;
    }
}

#endif
