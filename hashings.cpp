#include <iostream>
using namespace std;

// Node structure for the linked list in separate chaining
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class HashTable
{
private:
    int buckets;
    Node **table;

    int hashFunction(int key)
    {
        return key % buckets;
    }

public:
    HashTable(int b) : buckets(b)
    {
        table = new Node *[buckets];
        for (int i = 0; i < buckets; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < buckets; i++)
        {
            Node *current = table[i];
            while (current)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int key)
    {

        int index = hashFunction(key);
        Node *newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    
    }

    void remove(int key)
    {

        int index = hashFunction(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr && current->data != key)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Key " << key << " not found." << endl;
            return;
        }

        if (prev == nullptr)
        {

            table[index] = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        delete current;
        cout << "Key " << key << " removed." << endl;
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < buckets; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main()
{
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(3);
    ht.insert(22);

    cout << "Hash table after insertion:" << endl;
    ht.display();

    ht.remove(15);
    cout << "\nHash table after removing 15:" << endl;
    ht.display();

    cout << "\nSearching for 10: " << (ht.search(10) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
