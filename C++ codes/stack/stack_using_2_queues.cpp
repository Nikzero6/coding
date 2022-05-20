#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 6

class Stack
{
private:
    queue<int> q1;
    void _reverse(queue<int> &q1);

public:
    Stack();
    void push(int elem);
    void pop();
    void top();
    void empty();
};

Stack::Stack()
{
}

void Stack::push(int elem)
{
    q1.push(elem);
    cout << endl
         << "INSERTED: " << elem << endl;
}

void Stack::pop()
{
    while(q1.size() > 1){
        
    }
    if (q1.empty())
    {
        cout << endl
             << "STACK IS EMPTY!" << endl;
        return;
    }
    else
    {
        _reverse(q1);
        cout << endl
             << "REMOVED: " << q1.front() << endl;
        q1.pop();
        _reverse(q1);
    }
}

void Stack::_reverse(queue<int> &q1)
{
    if (q1.empty())
        return;
    int popped = q1.front();
    q1.pop();
    _reverse(q1);
    q1.push(popped);
}

void Stack::top()
{
    if (q1.empty())
    {
        cout << endl
             << "STACK IS EMPTY!" << endl;
    }
    else
    {
        _reverse(q1);
        cout << endl
             << "TOP IS: " << q1.front() << endl;
        _reverse(q1);
    }
}

void Stack::empty()
{
    if (q1.empty())
    {
        cout << endl
             << "EMPTY" << endl;
    }
    else
    {
        cout << endl
             << "NOT EMPTY" << endl;
    }
}

int main()
{
    Stack s = Stack();

    s.empty();
    s.top();
    s.push(3);
    s.push(22);
    s.push(34);
    s.push(56);
    s.top();
    s.pop();
    s.pop();
    s.top();

    return 0;
}