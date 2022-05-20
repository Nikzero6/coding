#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Queue
{
private:
    int arr[MAX_SIZE], front, rear, size;

public:
    Queue();
    bool isFull();
    void enqueue(int elem);
    void dequeue();
    void display();
    void queueSize();
};

Queue::Queue()
{
    size = 0;
    front = -1;
    rear = -1;
}

bool Queue::isFull()
{
    if (front == 0 && rear == MAX_SIZE - 1)
        return true;
    else if (rear + 1 == front)
        return true;
    return false;
}

void Queue::enqueue(int elem)
{

    if (isFull())
    {
        cout << endl
             << "QUEUE IS FULL!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = elem;
        size++;
        cout << endl
             << "INSERTED: " << arr[rear] << endl;
    }
}

void Queue::dequeue()
{
    if (front == -1)
    {
        cout << endl
             << "QUEUE IS EMPTY!" << endl;
    }
    else if (front == rear)
    {
        cout << endl
             << "REMOVED ELEMENT IS: " << arr[front] << endl;
        front = -1;
        rear = -1;
        size--;
    }
    else
    {
        cout << endl
             << "REMOVED ELEMENT IS: " << arr[front] << endl;
        front = (front + 1) % 5;
        size--;
    }
}

void Queue::display()
{
    if (front <= rear)
    {
        cout << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << "->";
        }
        cout << endl;
    }
    else if (rear < front)
    {
        cout << endl;
        for (int i = front; i < MAX_SIZE; i++)
        {
            cout << arr[i] << "->";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << "->";
        }
        cout << endl;
    }
}

void Queue::queueSize()
{
    cout << endl
         << "SIZE OF QUEUE IS: " << size << endl;
}

int main()
{
    Queue *q = new Queue();

    q->queueSize();
    q->enqueue(5);
    q->enqueue(15);
    q->enqueue(35);
    q->enqueue(45);
    q->enqueue(25);
    q->enqueue(55);
    q->display();
    q->queueSize();
    q->dequeue();
    q->dequeue();
    q->queueSize();
    q->display();
    q->enqueue(4);
    q->enqueue(2);
    q->display();

    return 0;
}