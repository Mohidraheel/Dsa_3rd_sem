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

    void swapu(node *current, node *previous) {
        node *nextptr = current->next;
        current->next = nextptr->next;
        nextptr->next = current;
        if (previous != NULL) {
            previous->next = nextptr;
        } else {
            head = nextptr;
        }
    }

    void bubblesort() {
        if (head == NULL || head->next == NULL) {
            return;  // No need to sort if the list is empty or has only one node
        }

        bool swapped;
        do {
            swapped = false;
            node *current = head;
            node *previous = NULL;

            while (current->next != NULL) {
                if (current->data > current->next->data) {
                    // Swap adjacent nodes
                    swapu(current, previous);
                    swapped = true;

                    // After swapping, the current node stays the same, so we don't move `previous`
                    previous = current->next;  // `current` now is the next node after swap
                } else {
                    // Move both `previous` and `current` forward if no swap
                    previous = current;
                    current = current->next;
                }
            }
        } while (swapped);  // Repeat until no swaps are made
    }


   int search(node * temp,int key)
   {
     if(temp ==NULL)
     {
      return -1;
     }

     if(temp->data == key )
     {
      return 1;
     }

     int result=search(temp->next,key);
     return result;
   }

   int slength(node * temp,int length)
   {
    if(temp==NULL)
    {
      return length;
    }

    slength(temp->next,length +1);
  
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
    cout<<endl;
    cout<<ll.search(ll.head,17);
    cout<<endl;
    int length=0;
    int x=ll.slength(ll.head,length);
    cout<<x<<endl;

    // Sorting the linked list using bubble sort
    ll.bubblesort();

    cout << "Sorted Linked List: " << endl;
    ll.print();


    return 0;
}
