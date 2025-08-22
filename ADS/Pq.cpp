#include <iostream>
using namespace std;

struct Element {
    int data;
    int priority;
};

const int MAX = 100;
Element pq[MAX]; 
int Size = 0;    

void insert(int data, int priority) {
    if (Size >= MAX) {
        cout << "Priority Queue is full!\n";
        return;
    }
    pq[Size].data = data;
    pq[Size].priority = priority;
    Size++;
    cout << "Inserted (" << data << ", priority " << priority << ")\n";
}

void remove() {
    if (Size == 0) {
        cout << "Priority Queue is empty!\n";
        return;
    }

    int maxPriorityIndex = 0;
    for (int i = 1; i < Size; i++) {
        if (pq[i].priority > pq[maxPriorityIndex].priority) {
            maxPriorityIndex = i;
        }
    }

    cout << "Deleted (" << pq[maxPriorityIndex].data
         << ", priority " << pq[maxPriorityIndex].priority << ")\n";

    // Shift elements left
    for (int i = maxPriorityIndex; i < Size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    Size--;
}

// Display the priority queue
void display() {
    if (Size == 0) {
        cout << "Priority Queue is empty.\n";
        return;
    }
    cout << "Priority Queue (data, priority):\n";
    for (int i = 0; i < Size; i++) {
        cout << "(" << pq[i].data << ", " << pq[i].priority << ") ";
    }
    cout << "\n";
}
int main() {
    int choice, data, priority;
    do {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n2. Delete (highest priority)\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data and priority: ";
                cin >> data >> priority;
                insert(data, priority);
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
