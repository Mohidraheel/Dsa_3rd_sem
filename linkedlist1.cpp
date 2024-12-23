#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node *next;
  node()
  {
    data=0;
    next=NULL;
  }
  node(int d)
  {
    data=d;
    next=NULL;
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
  void insert(int data)
  {
    if(head==NULL)
    {
      insertathead(data);
      return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=new node(data);

  }
  void insertathead(int data)
  {
    node *nn=new node(data);
    nn->next=head;
    head=nn;
  }
  void traverse()
  {
    node *temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" -> ";
      temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;

  }
  void insertsomewhere(int data,int value)
  {
    node *temp=head;
    node *nn=new node(data);int c=0;
    if(head==NULL)
    {
      insertathead(data);
      return;
    }
    while(temp!=NULL)
    {
       
        if(temp->data==value)
        {
          c=1;
          break;
        }
        else
        {
          temp=temp->next;
        }
        
    }
    if(c==1)
    {
       nn->next=temp->next;
       temp->next=nn;
    }
    else
    {
       cout<<"Value not found in the list."<<endl;
    }
   
  }

};
int main()
{

  linkedlist ll;
  // ll.insertathead(5);
  ll.insert(10);
  ll.insert(20);
  ll.insert(30);
  ll.insert(40);
  ll.insertsomewhere(15,30);
  
  ll.traverse();
  
return 0;
}
