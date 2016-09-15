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
        T peek();
        int getSize();
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
    head = NULL;
    current = NULL;
    tail = NULL;
    size = 0;
}

template<class T >
T Stack<T>::pop()
{
    Node* temp;

    if(NULL != head)
    {
        temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        size--;
        return data;
    }
    else
    {
       return 0;
    }


}

template<class T>
T Stack<T>::peek()
{
    return head->data;
}

template<class T>
void Stack<T>::push(T data)
{
    Node* n = new Node;
    n->data = data;
    n->next = NULL;

    if(NULL != head)
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

template<class T>
int Stack<T>::getSize()
{
    return this->size;
}

//ta bort innan inlämning
template<class T>
void Stack<T>::printStack()
{

    int index = 0; 

    if(NULL != head)
    {
        current = head;
        
        while(current->next != head && current->next != NULL)
        {
            std::cout << index << ": " << current->data << std::endl;
            current = current->next;

            index++;
        }
        if(current == tail)
        {
            std::cout << index << ": " << current->data << std::endl;
        }
    }

    else
    {
        std::cout << "The stack is empty!" << std::endl;
    }
}

#endif
