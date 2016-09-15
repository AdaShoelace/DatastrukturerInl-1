#ifndef STACK_H
#define STACK_H

#include <iostream>

/*
 * Pierre Leidbring 08/09/16
 *
 * Klass för stacken.
 */
template<class T>
class Stack 
{
    public:
        Stack();
        void push(T data);
        T pop();
        T peek();
        int getSize();
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

//Konstruktor som sätter samtliga pekare till null vid initialisering.
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

//Metod vilken returnerar värdet av datan i första elementet på stacken.
template<class T>
T Stack<T>::peek()
{
    return head->data;
}

//Lägger till ett element överst i stacken.
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

//Returnerar antalet element i stacken.
template<class T>
int Stack<T>::getSize()
{
    return this->size;
}

//Metod som skriver ut alla element i stacken. Skrev i syfte av testning på egen hand.
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
