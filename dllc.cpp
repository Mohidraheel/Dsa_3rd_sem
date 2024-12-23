#include<iostream>
using namespace std;

class node
{
  int data;
  node *next;
  node *prev;
  public:
  node()
  {
    data=0;
    next=NULL;
    prev=NULL;
  }
  node(int data)
  {
    this->data=data;
    next=NULL;
    prev=NULL;
  }

  friend class doublylinkedlist;
};


class doublylinkedlist
{
  node *head;
  public:
  doublylinkedlist()
  {
    head=NULL;
  }
  void insertathead(int data)
  {
    node *nn=new node(data);
    node *temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;
    }
    temp->next=nn;
    nn->next=head;
    nn->prev=temp;
    head->prev=nn;
    head=nn;
  }
  void insert(int data)
  {
    node *nn=new node(data);
    if(head==NULL)
    {
      head=nn;
      nn->next=head;
      nn->prev=head;
      return;
    }
    node *temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;
    }
    temp->next=nn;
    nn->next=head;
    nn->prev=temp;
    head->prev=nn;
  }

  void deleteathead()
  {
    if(head==NULL)
    {
      return;
    }
    node *todelete=head;
    if(head->next==head)
    {
      delete todelete;
      return;
    }

    node *temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;
    }
    temp->next=head->next;
    head->next->prev=temp;
    head=head->next;
    delete todelete;
  }

  void deleteatend()
  {
    node *temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;
    }

    node *todelete=temp;
    temp->prev->next=head;
    head->prev=temp->prev;
    delete todelete;
  }

  void print()
  {
    node *temp=head;
    do
    {
       cout<<temp->data<<" -> ";
       temp=temp->next;
    } while (temp!=head);
    
  
    cout<<endl;
  }

};
int main()
{
  doublylinkedlist d1;
  d1.insert(5);
  // d1.insertathead(2);
  d1.insert(7);
  d1.insert(8);
  d1.print();

  d1.deleteathead();
  d1.print();

  d1.deleteatend();
  d1.print();


}