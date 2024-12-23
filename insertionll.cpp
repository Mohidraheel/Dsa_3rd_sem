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

    // Function to sort the linked list using insertion sort
    void insertion_sort() {
        if (head == NULL || head->next == NULL)
            return;  // No need to sort if the list is empty or has only one element

        node *sorted = NULL;  // Temporary list to store sorted nodes
        node *current = head;

        while (current != NULL) {
            node *next = current->next;  // Store the next node to process
            sorted_insert(&sorted, current);  // Insert current node into the sorted list
            current = next;
        }

        head = sorted;  // Update the head to point to the sorted list
    }

    // Helper function to insert a node into the sorted part of the list
    void sorted_insert(node **sorted, node *new_node) {
        if (*sorted == NULL || (*sorted)->data >= new_node->data) {
            new_node->next = *sorted;
            *sorted = new_node;
        } else {
            node *temp = *sorted;
            while (temp->next != NULL && temp->next->data < new_node->data) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
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

    // Sorting the linked list
    ll.insertion_sort();

    cout << "Sorted Linked List: " << endl;
    ll.print();

    return 0;
}
