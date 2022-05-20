#include <iostream>
using namespace std;
#define MAX_SIZE 20

class Stack
{
private:
    int arr[MAX_SIZE], size, top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void stackSize();
    void push(int elem);
    void pop();
    void peek();
    void display();
};

Stack::Stack()
{
    size = 0;
    top = -1;
}

bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

bool Stack::isFull()
{
    if (top == MAX_SIZE - 1)
        return true;
    return false;
}

void Stack::stackSize()
{
    cout << endl
         << "STACK SIZE IS: " << size << endl;
}

void Stack::push(int elem)
{
    if (isFull())
    {
        cout << endl
             << "STACK IS FULL!" << endl;
    }
    else
    {
        arr[++top] = elem;
        size++;
        cout << endl
             << "INSERTED: " << elem << endl;
    }
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << endl
             << "STACK IS ALREADY EMPTY!" << endl;
    }
    else
    {
        size--;
        cout << endl
             << "POPPED: " << arr[top--] << endl;
    }
}

void Stack::peek()
{
    if (isEmpty())
    {
        cout << endl
             << "STACK IS EMPTY!" << endl;
    }
    else
    {
        cout << endl
             << "TOP ELEMENT IS: " << arr[top] << endl;
    }
}

void Stack::display()
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "->";
    }
    cout << endl;
}

int main()
{
    Stack *s = new Stack();
    s->stackSize();
    s->push(12);
    s->push(24);
    s->push(4);
    s->push(11);
    s->display();
    s->peek();
    s->stackSize();
    s->pop();
    s->pop();
    s->display();
    s->stackSize();
    s->peek();

    return 0;
}