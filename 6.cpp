#include <iostream>
#include <string>
using namespace std;

class Package
{
public:
    int packageID;
    string address;
    int startTime;
    int endTime;

    Package() 
    {
        packageID = 0;
        address = "";
        startTime = 0;
        endTime = 0;
    }
};

class Queue
{
private:
    Package* arr;
    int frontIndex;
    int rear;
    int count;
    int maxSize;

public:

    Queue(int size) 
    {
        maxSize = size;
        arr = new Package[maxSize];

        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() 
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == maxSize;
    }

    void enqueue(int id, string address,
        int start, int end) 
    {

        if (isFull()) 
        {
            cout << "Package Queue is Full!" << endl;
            return;
        }

        if (start < 0 || start > 2359 || end < 0 || end > 2359 || start % 100 >= 60 || end % 100 >= 60 || start > end)
        {
            cout << "Invalid Delivery Time Window!" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            int index = (frontIndex + i) % maxSize;

            if (arr[index].packageID == id) 
            {
                cout << "Package ID Already Exists!" << endl;
                return;
            }
        }

        rear = (rear + 1) % maxSize;

        arr[rear].packageID = id;
        arr[rear].address = address;
        arr[rear].startTime = start;
        arr[rear].endTime = end;

        count++;

        cout << "Package Added Successfully!" << endl;
    }

    void dequeue() 
    {

        if (isEmpty())
        {
            cout << "No Packages Available!" << endl;
            return;
        }

        cout << "Package " << arr[frontIndex].packageID  << " Delivered Successfully!" << endl;

        frontIndex = (frontIndex + 1) % maxSize;
        count--;
    }

    void front() 
    {

        if (isEmpty())
        {
            cout << "No Packages Available!" << endl;
            return;
        }

        cout << "\nNext Package Details:" << endl;

        cout << "Package ID: " << arr[frontIndex].packageID << endl;

        cout << "Address: " << arr[frontIndex].address << endl;

        cout << "Delivery Window: " << arr[frontIndex].startTime  << " - "  << arr[frontIndex].endTime << endl;
    }

    void display()
    {

        if (isEmpty())
        {
            cout << "No Pending Packages!" << endl;
            return;
        }

        cout << "\n===== PENDING PACKAGES =====" << endl;

        for (int i = 0; i < count; i++) 
        {

            int index = (frontIndex + i) % maxSize;

            cout << "\nPackage ID: " << arr[index].packageID << endl;

            cout << "Address: "  << arr[index].address << endl;

            cout << "Delivery Window: " << arr[index].startTime  << " - "  << arr[index].endTime << endl;
        }
    }

    void timeToDeliver(int currentTime) 
    {

        if (isEmpty()) 
        {
            cout << "No Packages Available!" << endl;
            return;
        }

        if (currentTime < 0 || currentTime > 2359 ||
            currentTime % 100 >= 60) {

            cout << "Invalid Current Time!" << endl;
            return;
        }

        while (!isEmpty())
        {

            if (currentTime > arr[frontIndex].endTime) 
            {

                cout << "\nPackage "
                    << arr[frontIndex].packageID
                    << " has Expired!" << endl;

                cout << "Package Skipped!" << endl;

                frontIndex = (frontIndex + 1) % maxSize;
                count--;
            }
            else
            {
                break;
            }
        }

        if (isEmpty())
        {
            cout << "No Packages Available for Delivery!" << endl;
            return;
        }

        if (currentTime < arr[frontIndex].startTime) 
        {

            cout << "\nPackage "
                << arr[frontIndex].packageID
                << " is Not Ready for Delivery Yet!" << endl;
        }
        else 
        {

            cout << "\nPackage "
                << arr[frontIndex].packageID
                << " Can Be Delivered Now!" << endl;

            cout << "Address: "
                << arr[frontIndex].address << endl;
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{

    int size, choice;
    int id, start, end, currentTime;
    string address;

    cout << "Enter Maximum Package Queue Size: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid Queue Size!" << endl;
        return 0;
    }

    Queue q(size);

    do
    {

        cout << "\n===== PACKAGE DELIVERY SYSTEM =====" << endl;

        cout << "1. Add New Package" << endl;
        cout << "2. Deliver Package" << endl;
        cout << "3. Check Next Package" << endl;
        cout << "4. Display All Packages" << endl;
        cout << "5. Check Delivery Time" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "Enter Package ID: ";
            cin >> id;

            cout << "Enter Recipient Address: ";
            cin >> ws;
            getline(cin, address);

            cout << "Enter Start Time (HHMM): ";
            cin >> start;

            cout << "Enter End Time (HHMM): ";
            cin >> end;

            q.enqueue(id, address, start, end);

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

            cout << "Enter Current Time (HHMM): ";
            cin >> currentTime;

            q.timeToDeliver(currentTime);

            break;

        case 6:

            cout << "Exiting Package Delivery System..."
                << endl;

            break;

        default:

            cout << "Invalid Choice! Try Again." << endl;
        }

    } 
    while (choice != 6);

    return 0;
}
