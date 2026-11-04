#include <iostream>
using namespace std;

class Stack 
{
private:
    int arr[100];
    int top;

public:
    Stack() 
    {
        top = -1;
    }

    void push(int value) 
    {
        if (top == 99) 
        {
            cout << "Stack is Full!" << endl;
            return;
        }

        arr[++top] = value;
    }

    int pop()
    {
        if (top == -1) 
        {
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty() 
    {
        return top == -1;
    }
};

class Queue 
{
private:
    int arr[100];
    int frontIndex;
    int rear;
    int count;

public:
    Queue() 
    {
        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int value)
    {
        if (count == 100) 
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        rear = (rear + 1) % 100;
        arr[rear] = value;
        count++;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            return -1;
        }

        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % 100;
        count--;

        return value;
    }

    int front()
    {
        if (isEmpty()) 
        {
            return -1;
        }

        return arr[frontIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() 
    {
        return count;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << arr[(frontIndex + i) % 100] << " ";
        }

        cout << endl;
    }

    void reverseK(int k)
    {
        if (k <= 1 || isEmpty())
        {
            return;
        }

        if (k > count) 
        {
            k = count;
        }

        Stack s;

        for (int i = 0; i < k; i++)
        {
            s.push(dequeue());
        }

        while (!s.isEmpty())
        {
            enqueue(s.pop());
        }

        int remaining = count - k;

        for (int i = 0; i < remaining; i++)
        {
            enqueue(dequeue());
        }
    }
};

int main() 
{
    Queue q;

    int n, value, k;

    cout << "Enter number of queue elements: ";
    cin >> n;

    if (n < 0 || n > 100)
    {
        cout << "Invalid Queue Size!" << endl;
        return 0;
    }

    cout << "Enter queue elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.enqueue(value);
    }

    cout << "\nOriginal Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    q.reverseK(k);

    cout << "\nQueue after reversing first K elements: ";
    q.display();

    return 0;
}
