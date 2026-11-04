//#include <iostream>
//using namespace std;
//
//class Queue 
//{
//private:
//    int tickets[100];
//    int frontIndex;
//    int rear;
//    int count;
//
//public:
//
//    Queue()
//    {
//        frontIndex = 0;
//        rear = -1;
//        count = 0;
//    }
//
//    void enqueue(int ticket_id)
//    {
//
//        if (count == 100) 
//        {
//            cout << "Ticket Queue is Full!" << endl;
//            return;
//        }
//
//        if (ticket_id < 1000 || ticket_id > 9999)
//        {
//            cout << "Invalid Ticket ID! Enter a 4-digit ID." << endl;
//            return;
//        }
//
//        rear = (rear + 1) % 100;
//        tickets[rear] = ticket_id;
//        count++;
//
//        cout << "Ticket " << ticket_id << " added successfully!" << endl;
//    }
//
//    void dequeue() 
//    {
//
//        if (isEmpty())
//        {
//            cout << "No Pending Tickets!" << endl;
//            return;
//        }
//
//        cout << "Ticket " << tickets[frontIndex] << " resolved successfully!" << endl;
//
//        frontIndex = (frontIndex + 1) % 100;
//        count--;
//    }
//
//    void front()
//    {
//
//        if (isEmpty()) 
//        {
//            cout << "No Pending Tickets!" << endl;
//            return;
//        }
//
//        cout << "Next Ticket to Resolve: " << tickets[frontIndex] << endl;
//    }
//
//    void display()
//    {
//
//        if (isEmpty()) 
//        {
//            cout << "No Pending Tickets!" << endl;
//            return;
//        }
//
//        cout << "\nPending Support Tickets:" << endl;
//
//        for (int i = 0; i < count; i++)
//        {
//            cout << tickets[(frontIndex + i) % 100]
//                << endl;
//        }
//    }
//
//    bool isEmpty() 
//    {
//        return count == 0;
//    }
//};
//
//int main() 
//{
//
//    Queue q;
//    int choice;
//    int ticket_id;
//
//    do 
//    {
//
//        cout << "\n===== CUSTOMER SUPPORT TICKET SYSTEM =====" << endl;
//        cout << "1. Add New Ticket" << endl;
//        cout << "2. Resolve Ticket" << endl;
//        cout << "3. Check Next Ticket" << endl;
//        cout << "4. Display Pending Tickets" << endl;
//        cout << "5. Exit" << endl;
//
//        cout << "\nEnter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//
//        case 1:
//            cout << "Enter 4-digit Ticket ID: ";
//            cin >> ticket_id;
//            q.enqueue(ticket_id);
//            break;
//
//        case 2:
//            q.dequeue();
//            break;
//
//        case 3:
//            q.front();
//            break;
//
//        case 4:
//            q.display();
//            break;
//
//        case 5:
//            cout << "Exiting Customer Support System..."
//                << endl;
//            break;
//
//        default:
//            cout << "Invalid Choice! Try Again." << endl;
//        }
//
//    } while (choice != 5);
//
//    return 0;
//}
