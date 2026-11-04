#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int maxSize;
    int frontIndex;
    int rear;
    int count;

public:
    myQueue(int size) {
        maxSize = size;
        arr = new T[maxSize];

        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        rear = (rear + 1) % maxSize;
        arr[rear] = value;
        count++;

        cout << value << " inserted successfully!" << endl;
    }

    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = arr[frontIndex];

        frontIndex = (frontIndex + 1) % maxSize;
        count--;

        return value;
    }

    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return arr[frontIndex];
    }

    bool isEmpty() const override {
        return count == 0;
    }

    bool isFull() const override {
        return count == maxSize;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % maxSize;
            cout << arr[index] << " ";
        }

        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    int size;
    int choice;
    int value;

    cout << "Enter Queue Size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid Queue Size!" << endl;
        return 0;
    }

    myQueue<int> q(size);

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;

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
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 5:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is Not Full." << endl;
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Program Exited Successfully!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 7);

    return 0;
}
