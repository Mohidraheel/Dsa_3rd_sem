#include <iostream>
using namespace std;
class node
{
  int data;
  node *next;

public:
  node()
  {
    data = 0;
    next = NULL;
  }
  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  friend class linkedlist;
};

class linkedlist
{
  node *head;

public:
  linkedlist()
  {
    head = NULL;
  }
  void insertatfront(int data)
  {
    node *n = new node(data);
    n->next = head;
    head = n;
  }
  void insertatend(int data)
  {
    if (head == NULL)
    {
      insertatfront(data);
      return;
    }
    node *n = new node(data);
    node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = n;
  }
  void insertbeforekey(int data, int key)
  {
    node *temp = head;
    int found = 0;
    node *previous = NULL;
    while (temp != NULL)
    {
      if (temp->data == key)
      {
        found = 1;
        break;
      }
      previous = temp;
      temp = temp->next;
    }
    if (found == 1)
    {
      node *n = new node(data);
      if (previous == NULL)
      {
        insertatfront(data);
      }
      else
      {
        previous->next = n;
        n->next = temp;
      }
    }
    else
    {
      cout << "Value not found" << endl;
    }
  }
  void insertafterkey(int data, int key)
  {
    node *temp = head;
    int found = 0;
    while (temp != NULL)
    {
      if (temp->data == key)
      {
        found = 1;
        break;
      }

      temp = temp->next;
    }
    if (found == 1)
    {
      node *n = new node(data);
      n->next = temp->next;
      temp->next = n;
    }
    else
    {
      cout << "Value not found" << endl;
    }
  }
  void deletehead()
  {
    if(head==NULL)
    {
      return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
  }
  void deleteatend()
  {
    if(head==NULL)
    {
      return;
    }
    else
    {
      if(head->next==NULL)
      {
        deletehead();
        return;
      }
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
  }
  void deleteatsome(int key)
  {
    node *temp = head;
    node *previous = NULL;
    int found = 0;
    while (temp != NULL)
    {
      if (temp->data == key)
      {
        found = 1;
        break;
      }
      previous = temp;
      temp = temp->next;
    }
    // cout<<temp->data;
    // cout<<previous->data;
    if (found == 1)
    {
      node *todelete = temp;
      if (previous == NULL)
      {
        deletehead();
        return;
      }
      else
      {
        previous->next = temp->next;
        temp->next = NULL;
        delete todelete;
      }
    }
    else
    {
      cout << "No such Value" << endl;
    }
  }
  void sort()
  {
    node *temp;
       node *temp1;
       int temporary;
       for(temp=head;temp!=NULL;temp=temp->next)
       {
        for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
          if(temp->data>temp1->data)
          {
            // swap(temp->data,temp1->data);
            temporary=temp->data;
            temp->data=temp1->data;
            temp1->data=temporary;
          }
        }

       }
  }
  void print()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " -> ";
      cout<<temp<<" ";
      cout<<temp->next;
      cout<<endl;
      temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
  }
  void countcheck()
  {
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {

      count++;
      temp = temp->next;
    }

    cout << "total Nodes:" << count << endl;
    cout << endl;
  }
};

int main()
{
  linkedlist ll;
  ll.insertatfront(6);
  ll.insertatend(1);
  ll.insertatend(8);
  ll.insertatend(3);
  ll.insertatend(4);
  ll.print();

  cout<<"_________________________"<<endl;
  ll.sort();
  ll.print();

}