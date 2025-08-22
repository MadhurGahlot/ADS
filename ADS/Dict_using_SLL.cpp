#include <iostream>
using namespace std;
struct Node {
    int key;
    int value;
    Node* next;
};
Node* head = nullptr; 
void insert(int key, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            temp->value = value;
            cout << "Key already exists. Value updated.\n";
            return;
        }
        temp = temp->next;
    }
    Node* newNode = new Node{key, value, nullptr};

    if (head == nullptr || key < head->key) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted (" << key << ", " << value << ")\n";
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->key < key) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;

    cout << "Inserted (" << key << ", " << value << ")\n";
}

void removeKey(int key) {
    if (head == nullptr) {
        cout << "Dictionary is empty!\n";
        return;
    }

    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted key " << key << "\n";
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Key not found!\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Deleted key " << key << "\n";
}

void findKey(int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            cout << "Found: (" << temp->key << ", " << temp->value << ")\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Key not found!\n";
}

void display() {
    if (head == nullptr) {
        cout << "Dictionary is empty.\n";
        return;
    }

    cout << "Ordered Dictionary:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "(" << temp->key << ", " << temp->value << ") ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice, key, value;
    do {
        cout << "\n--- Ordered Dictionary (Linked List) Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Find\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key : ";
                cin >> key ;
                cout<<"Enter value: ";
                cin>> value;
                insert(key, value);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                removeKey(key);
                break;
            case 3:
                cout << "Enter key to find: ";
                cin >> key;
                findKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
