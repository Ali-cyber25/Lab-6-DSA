#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string* documents;
    int frontIndex;
    int rear;
    int count;
    int maxSize;

public:

    Queue(int size)
    {
        maxSize = size;
        documents = new string[maxSize];

        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(string document_name)
    {

        if (isFull())
        {
            cout << "Print Queue is Full!" << endl;
            return;
        }

        rear = (rear + 1) % maxSize;
        documents[rear] = document_name;
        count++;

        cout << document_name  << " added to Print Queue!" << endl;
    }

    void dequeue() 
    {

        if (isEmpty())
        {
            cout << "No Print Jobs Available!" << endl;
            return;
        }

        cout << "Printing Document: " << documents[frontIndex] << endl;

        frontIndex = (frontIndex + 1) % maxSize;
        count--;

        cout << "Document Printed Successfully!" << endl;
    }

    void front() 
    {

        if (isEmpty())
        {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "Next Document to Print: " << documents[frontIndex] << endl;
    }

    void display() 
    {

        if (isEmpty())
        {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "\nPending Print Jobs:" << endl;

        for (int i = 0; i < count; i++) 
        {
            cout << i + 1 << ". "
                << documents[(frontIndex + i) % maxSize]
                << endl;
        }
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull() 
    {
        return count == maxSize;
    }

    ~Queue() 
    {
        delete[] documents;
    }
};

int main() 
{

    int size, choice;
    string document_name;

    cout << "Enter Maximum Print Queue Size: ";
    cin >> size;

    if (size <= 0) 
    {
        cout << "Invalid Queue Size!" << endl;
        return 0;
    }

    Queue q(size);

    do 
    {

        cout << "\n===== PRINTER QUEUE SYSTEM =====" << endl;
        cout << "1. Add New Print Job" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. Check Next Document" << endl;
        cout << "4. Display Pending Print Jobs" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Document Name: ";
            cin >> ws;
            getline(cin, document_name);

            q.enqueue(document_name);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting Printer Queue System..."
                << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    }
    while (choice != 5);

    return 0;
}