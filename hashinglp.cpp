#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;        // Array to store keys
    int capacity;      // Size of the hash table
    int size;          // Current number of elements in the table
    const int EMPTY;   // Placeholder for empty slots

    // Hash function to calculate index
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int cap) : capacity(cap), size(0), EMPTY(-1) {
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = EMPTY;  // Initialize all slots to EMPTY
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;  // Free allocated memory
    }

    // Insert a key into the hash table
    void insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full. Cannot insert key " << key << "." << endl;
            return;
        }

        int index = hashFunction(key);  // Calculate hash index
        while (table[index] != EMPTY && table[index] != key) {
            index = (index + 1) % capacity;  // Linear probing
        }

        if (table[index] == key) {
            cout << "Key " << key << " already exists in the hash table." << endl;
            return;
        }

        table[index] = key;  // Insert the key
        size++;
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);  // Calculate hash index
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = EMPTY;  // Mark slot as EMPTY
                size--;
                cout << "Key " << key << " removed." << endl;
                return;
            }

            index = (index + 1) % capacity;  // Continue probing
            if (index == startIndex) break;  // Stop if we've looped back to the start
        }

        cout << "Key " << key << " not found in the hash table." << endl;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);  // Calculate hash index
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;

            index = (index + 1) % capacity;  // Continue probing
            if (index == startIndex) break;  // Stop if we've looped back to the start
        }

        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] == EMPTY)
                cout << "Slot " << i << ": EMPTY" << endl;
            else
                cout << "Slot " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht(7);  // Create a hash table with 7 slots (array size is 7)

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(3);

    cout << "Hash table after insertion:" << endl;
    ht.display();

    ht.remove(15);
    cout << "\nHash table after removing 15:" << endl;
    ht.display();

    cout << "\nSearching for 10: " << (ht.search(10) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
