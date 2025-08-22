#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10; 
struct Node {
    string firstName;
    string lastName;
    string contact;
    Node* next;
    Node(string f, string l, string c) {
        firstName = f;
        lastName = l;
        contact = c;
        next = nullptr;
    }
};
class HashTable {
    Node* table[TABLE_SIZE]; 

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
    }
    int hashFunc(string f, string l) {
        int sum = 0;
        string key = f + l;
        for (char ch : key) sum += ch;
        return sum % TABLE_SIZE;
    }

    void insert(string f, string l, string c) {
        int index = hashFunc(f, l);
        Node* newNode = new Node(f, l, c);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted: " << f << " " << l << " (" << c << ")\n";
    }
    void search(string f, string l) {
        int index = hashFunc(f, l);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->firstName == f && temp->lastName == l) {
                cout << "Found: " << temp->firstName << " " 
                     << temp->lastName << " -> " << temp->contact << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found!\n";
    }

    void remove(string f, string l) {
        int index = hashFunc(f, l);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->firstName == f && temp->lastName == l) {
                if (prev == nullptr)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                cout << "Deleted: " << f << " " << l << "\n";
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Contact not found!\n";
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket[" << i << "]: ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "[" << temp->firstName << " " << temp->lastName
                     << " : " << temp->contact << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};
int main() {
    HashTable ht;
    int choice;
    string f, l, c;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert Contact\n2. Search Contact\n3. Delete Contact\n4. Display All\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter First Name, Last Name, Contact: ";
                cin >> f >> l >> c;
                ht.insert(f, l, c);
                break;
            case 2:
                cout << "Enter First Name and Last Name to search: ";
                cin >> f >> l;
                ht.search(f, l);
                break;
            case 3:
                cout << "Enter First Name and Last Name to delete: ";
                cin >> f >> l;
                ht.remove(f, l);
                break;
            case 4:
                ht.display();
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
