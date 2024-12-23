#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node *next;
  node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};
class linkedlist
{
  node *head;
  public:
  linkedlist()
  {
    head=NULL;
  }
  void insertathead(int data)
  {
    node *n=new node(data);
    n->next=head;
    head=n;
  }
  void insert(int data)
  {
   
    if(head==NULL)
    {
      insertathead(data);
      return;
    }
    node * n=new node(data);
    node *temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=n;

  }

  void insertatsomepoint(int data,int key)
  {
     node *temp=head;
     int found=0;
     while(temp->next!=NULL)
     {
      if(temp->data==key)
      {
        found=1;
        break;
      }
      temp=temp->next;


     }

     if(found==1)
     {
      node *n=new node(data);
      n->next=temp->next;
      temp->next=n;
     }
  }

  void print()
  {
    node *temp=head;
    if(temp==NULL)
    {
      cout<<"No list"<<endl;
    }
    else
    {
      while(temp!=NULL)
      {
        cout<<temp->data<<" -> ";
        temp=temp->next;
      }
      cout<<"NULL";
      cout<<endl;

    }
  }

  void deleteathead()
  {
    node *temp=head;
    head=head->next;
    delete temp;
  }
  void deleteattail()
  {
    node *temp=head;
    while(temp->next->next!=NULL)
    {
       temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=NULL;
    delete todelete;
  }
  void deletion(int val)
  {
    node *temp=head;
    while(temp->next->data!=val)
    {
      temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
  }

  void reverse()
  {
    node *current=head;
    node *nextptr;
    node *previous=NULL;

   // previous -> current->next
    while(current!=NULL)
    {
       nextptr=current->next;  // head ->next if i=0 then now i=1 iterations
      current->next=previous;  
 
     
      previous=current;
      current=nextptr;
      
    }
    head=previous;
  }
};
int main()
{
  linkedlist ll;
  ll.insert(1);
  ll.insert(3);
  ll.insertathead(2);
  ll.insert(4);
  ll.insertatsomepoint(5,3);
//  ll.deleteathead(); 
  // ll.deleteattail();
  // ll.deletion(3);
  ll.reverse();
  ll.print();
return 0;
}

