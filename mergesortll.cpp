#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node() {
        data = 0;
        next = NULL;
    }

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    friend class linkedlist;
};

class linkedlist {
public:
    node *head;

    linkedlist() {
        head = NULL;
    }

    void insertatfront(int data) {
        node *n = new node(data);
        n->next = head;
        head = n;
    }

    void insertatend(int data) {
        if (head == NULL) {
            insertatfront(data);
            return;
        }
        node *n = new node(data);
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void print() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to split the linked list into two halves
    void split(node *source, node **front, node **back) {
        node *fast;
        node *slow;
        slow = source;
        fast = source->next;

        // Move fast two nodes and slow one node
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // Slow is before the midpoint
        *front = source;
        *back = slow->next;
        slow->next = NULL; // Split the list into two halves
    }

    // Function to merge two sorted linked lists
    node* merge(node *a, node *b) {
        node *result = NULL;

        // Base cases
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // Recursive case
        if (a->data <= b->data) {
            result = a;
            result->next = merge(a->next, b);
        } else {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }

    // Function to perform merge sort on the linked list
    void mergesort(node **headRef) {
        node *head = *headRef;
        node *a;
        node *b;

        // Base case: if the list is empty or has one node
        if (head == NULL || head->next == NULL)
            return;

        // Split the list into two halves
        split(head, &a, &b);

        // Recursively sort the sublists
        mergesort(&a);
        mergesort(&b);

        // Merge the sorted sublists
        *headRef = merge(a, b);
    }

    void sort() {
        mergesort(&head);
    }
};

int main() {
    linkedlist ll;

    // Inserting some values into the list
    ll.insertatend(1);
    ll.insertatend(2);
    ll.insertatend(3);
    ll.insertatend(9);
    ll.insertatend(2);
    ll.insertatend(10);
    ll.insertatend(7);

    cout << "Original Linked List: " << endl;
    ll.print();

    // Sorting the linked list using merge sort
    ll.sort();

    cout << "Sorted Linked List: " << endl;
    ll.print();

    return 0;
}
