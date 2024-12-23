#include <iostream>
using namespace std;
class node
{
  int data;
  node *next;
  int exp;

public:
  node()
  {
    data = 0;
    next = NULL;
    exp = 0;
  }
  node(int data, int exp)
  {
    this->data = data;
    this->exp = exp;
    this->next = NULL;
  }
  friend class linkedlist;
};

class linkedlist
{
public:
  node *head;
  linkedlist()
  {
    head = NULL;
  }
  void insertatfront(int data, int exp)
  {
    node *n = new node(data, exp);
    n->next = head;
    head = n;
  }
  void insertatend(int data, int exp)
  {
    if (head == NULL)
    {
      insertatfront(data, exp);
      return;
    }
    node *n = new node(data, exp);
    node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = n;
  }

  void delete1(node *temp)
  {
    if (head == NULL || temp == NULL)
    {
      return; // List is empty or the given node is null
    }
    node *prev = NULL;
    node *temp1 = head;
    while (temp1 != NULL)
    {
      if (temp1 == temp)
      {
        break;
      }
      prev = temp1;
      temp1 = temp1->next;
    }
    if (temp1 == NULL)
    {
    
      return;
    }

    if (head == temp1)
    {

      head = head->next;
    }
    else
    {
        prev->next=temp1->next;
    }

    delete temp1;

   
  }
  void reverse()
  {
    node *currentptr = head;
    node *nextptr;
    node *previous = NULL;
    int c = 0;
    while (currentptr != NULL)
    {
      nextptr = currentptr->next;
      currentptr->next = previous;

      previous = currentptr;
      currentptr = nextptr;
    }
    head = previous;
  }

  void print()
  {
    node *temp = head;
    while (temp != NULL)
    {

      cout << temp->data << "x" << temp->exp;
      if (temp->next != NULL)
      {
        cout << " + ";
      }
      temp = temp->next;
    }
    cout << endl;
  }
void add(linkedlist &l1, linkedlist &l2) {
    node *temp1 = l1.head; // Use temp1 for l1
    node *temp2 = l2.head; // Use temp2 for l2

    linkedlist result;

    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 != NULL && temp2 != NULL) {
            if (temp1->exp == temp2->exp) {
                // If both exponents are the same, sum the coefficients
                result.insertatend(temp1->data + temp2->data, temp1->exp);
                temp1 = temp1->next; // Move to the next node in l1
                temp2 = temp2->next; // Move to the next node in l2
            } else if (temp1->exp > temp2->exp) {
                // If the exponent of temp1 is greater, add it to the result
                result.insertatend(temp1->data, temp1->exp);
                temp1 = temp1->next; // Move to the next node in l1
            } else {
                // If the exponent of temp2 is greater, add it to the result
                result.insertatend(temp2->data, temp2->exp);
                temp2 = temp2->next; // Move to the next node in l2
            }
        } else if (temp1 != NULL) {
            // If temp1 is not null, add the remaining nodes from l1
            result.insertatend(temp1->data, temp1->exp);
            temp1 = temp1->next; // Move to the next node in l1
        } else if (temp2 != NULL) {
            // If temp2 is not null, add the remaining nodes from l2
            result.insertatend(temp2->data, temp2->exp);
            temp2 = temp2->next; // Move to the next node in l2
        }
    }

    // Print the resulting polynomial
    result.print();
}
};
int main()
{
  linkedlist ll;

  ll.insertatend(5, 3);
  ll.insertatend(4, 1);
  ll.insertatend(3, 2);
  ll.insertatend(10, 4);
  ll.print();

  linkedlist l2;
  l2.insertatfront(2, 3);
  l2.insertatend(10, 1);
  l2.insertatend(3, 2);

  l2.print();

  cout << endl;
  ll.add(ll, l2);

}