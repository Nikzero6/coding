#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Queue
{
private:
    int arr[MAX_SIZE], front, rear, size;

public:
    Queue();
    void enqueue(int elem);
    void dequeue();
    void queueSize();
    void display();
};

Queue::Queue()
{
    size = 0;
    front = -1;
    rear = -1;
}

void Queue::enqueue(int elem)
{
    if (front == -1)
        front = 0;
    if (rear == MAX_SIZE - 1)
    {
        cout << endl
             << "QUEUE IS FULL!" << endl;
    }
    else
    {
        arr[++rear] = elem;
        size++;
        cout << endl
             << "INSERTED: " << elem << endl;
    }
}

void Queue::dequeue()
{
    if (front == -1)
    {
        cout << endl
             << "QUEUE IS EMPTY!" << endl;
    }
    else if (front >= rear)
    {
        cout << endl
             << "ELEMENT REMOVED IS: " << arr[front] << endl;
        front = -1;
        rear = -1;
        size--;
    }
    else
    {
        size--;
        cout << endl
             << "ELEMENT REMOVED IS: " << arr[front++] << endl;
    }
}

void Queue::queueSize()
{
    cout << endl
         << "SIZE OF QUEUE IS: " << size << endl;
}

void Queue::display()
{
    cout << endl;
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << "->";
    }
    cout << endl;
}

int main()
{
    Queue *q = new Queue();

    q->queueSize();
    q->enqueue(4);
    q->enqueue(11);
    q->enqueue(22);
    q->enqueue(88);
    q->enqueue(33);
    q->enqueue(44);
    q->display();
    q->queueSize();
    q->dequeue();
    q->dequeue();
    q->display();
    q->queueSize();

    return 0;
}