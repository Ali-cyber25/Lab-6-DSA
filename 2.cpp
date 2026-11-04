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
			cout << "Stack is Full! " << endl;
			return;
		}

		arr[++top] = value;
	}

	void pop()
	{
		if (top == -1)
		{
			return;
		}

		top--;
	}

	int peek()
	{
		return arr[top];
	}

	bool isEmpty()
	{
		return top == -1;
	}
};

class Queue
{
private:
	Stack s1;
	Stack s2;

public:
	void enQueue(int value)
	{
		s1.push(value);
		cout << value << "inserted successfully!" << endl;
	}

	void transfer()
	{
		while (!s1.isEmpty())
		{
			s2.push(s1.peek());
			s1.pop();
		}
	}

	int deQueue()
	{
		if (s1.isEmpty() && s2.isEmpty())
		{
			cout << "Queue is Empty! " << endl;
			return -1;
		}

		if (s2.isEmpty())
		{
			transfer();
		}
		int value = s2.peek();
		s2.pop();

		return value;
	}

	int front()
	{
		if (s1.isEmpty() && s2.isEmpty())
		{
			cout << "Queue is Empty! " << endl;
			return -1;
		}

		if (s2.isEmpty())
		{
			transfer();
		}

		return s2.peek();
	}

    void display() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        Stack temp1 = s2;
        Stack temp2;

        while (!temp1.isEmpty()) {
            cout << temp1.peek() << " ";
            temp2.push(temp1.peek());
            temp1.pop();
        }

        while (!temp2.isEmpty()) {
            temp1.push(temp2.peek());
            temp2.pop();
        }

        temp1 = s1;

        Stack temp3;

        while (!temp1.isEmpty()) {
            temp3.push(temp1.peek());
            temp1.pop();
        }

        while (!temp3.isEmpty()) {
            cout << temp3.peek() << " ";
            temp3.pop();
        }

        cout << endl;
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed Element: "
                << q.deQueue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: "
                << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Exited!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
