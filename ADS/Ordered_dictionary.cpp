#include <iostream>
using namespace std;

struct Pair {
    int key;
    int value;
};
const int Max_size =100;
    Pair dictarr[Max_size];
    int Size=0;

    void insert(int key, int value) {
        if (Size >= Max_size) {
            cout << "Dictionary is full!\n";
            return;
        }
        for (int i = 0; i < Size; i++) {
            if (dictarr[i].key == key) {
                dictarr[i].value = value; 
                cout << "Key already exists. Value updated.\n";
                return;
            }
        }
        int pos = Size - 1;
        while (pos >= 0 && dictarr[pos].key > key) {
            dictarr[pos + 1] = dictarr[pos]; 
            pos--;
        }
        dictarr[pos + 1] = {key, value};
        Size++;
        cout << "Inserted (" << key << ", " << value << ")\n";
    }
    void remove(int key) {
        int i;
        for (i = 0; i < Size; i++) {
            if (dictarr[i].key == key) break;
        }
        if (i == Size) {
            cout << "Key not found!\n";
            return;
        }
        // shift left
        for (int j = i; j < Size - 1; j++) {
            dictarr[j] = dictarr[j + 1];
        }
        Size--;
        cout << "Deleted key " << key << "\n";
    }
    void find(int key) {
        for (int i = 0; i < Size; i++) {
            if (dictarr[i].key == key) {
                cout << "Found: (" << dictarr[i].key << ", " << dictarr[i].value << ")\n";
                return;
            }
        }
        cout << "Key not found!\n";
    }
    void display() {
        if (Size == 0) {
            cout << "Dictionary is empty.\n";
            return;
        }
        cout << "Ordered Dictionary:\n";
        for (int i = 0; i < Size; i++) {
            cout << "(" << dictarr[i].key << ", " << dictarr[i].value << ") ";
        }
        cout << "\n";
    }
int main() {
    int choice;
    int key, value;
    do {
        cout << "\n--- Ordered Dictionary Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Find\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key ;
                cout<<"Enter value: ";
                cin >> value;
                insert(key, value);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                remove(key);
                break;
            case 3:
                cout << "Enter key to find: ";
                cin >> key;
                find(key);
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
