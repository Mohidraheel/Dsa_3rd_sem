#include <iostream>
#include <math.h>
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
    if (head == NULL)
    {
      return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
  }
  void deleteatend()
  {
    if (head == NULL)
    {
      return;
    }
    else
    {
      if (head->next == NULL)
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
  void print()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " -> ";
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
  void sum(linkedlist ll,linkedlist l2,linkedlist &l3)
  {
    int c = 0;
    node *temp = ll.head;
    while (temp != NULL)
    {

      c++;
      temp = temp->next;
    }
    temp =ll. head;
    int num = 0;
    int temp1 = 0;
    while (temp != NULL)
    {
      temp1 = temp->data;
      c--;
       int temp2=1; 
        for(int i=0;i<c;i++)
        {
          temp2*=10;

        } 
      num += temp1*temp2;
      temp = temp->next;
    }
    cout << num;

    int num2=0;
    node *second=l2.head;
     
    int count=0;
    while(second!=NULL)
    {
      count++;
      second=second->next;
    }
    second=l2.head;
    int temp4=0;
    while(second!=NULL)
    {
      int temp3=second->data;
      count--;
       int temp4=1; 
        for(int i=0;i<count;i++)
        {
          temp4*=10;

        } 
        num2+=temp3*temp4;
        second=second->next;

    }
    cout<<endl;
    cout<<num2;
    
    count=0;
    int result=num+num2;
    while(result>0)
    {
      int digit=result%10;
      l3.insertatfront(digit);
      result=result/10;
    }
  }

  
};

int main()
{
  linkedlist ll;
  ll.insertatfront(3);
  ll.insertatend(4);
  ll.insertatend(5);


  linkedlist l2;
  l2.insertatfront(4);
  l2.insertatend(5);
    linkedlist l3;

    ll.sum(ll,l2,l3);
    cout<<endl;
    l3.print();

}