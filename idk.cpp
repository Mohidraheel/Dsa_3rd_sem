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
    node *n=new node(data);
    node*temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;

    }
    temp->next=n;
  }
  void insertatpoint(int data,int point)
  {
    int found=0;
    node *temp=head;
    node *prevous=NULL;
    while(temp->next!=NULL)
    {
      if(temp->data==point)
      {
        found=1;
        break;
      }
      
      prevous=temp;
      temp=temp->next;
   


    }
    if(found==1)
    {
      node *n=new node(data);
      // n->next=temp->next;
      // temp->next=n;
      if(prevous==NULL)
      {
           n->next = head;
            head = n;
      }
      else
      {
        prevous->next=n;
        n->next=temp;

      }
      

    }
    else
    {
      cout<<"No such value in this list";
    }

  }
  void deletehead()
  {
    if(head==NULL)
      {
        cout<<"Empty list";
      }
      else
      {
        node *todelete=head;
        head=head->next;
        delete todelete;
      }
  }
  void deletion()
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
void deleteatsome(int val)
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
  while(current!=NULL)
  {
    nextptr=current->next;
    current->next=previous;


     previous=current;
    current=nextptr;
   



  }
  head=previous;
}
  void print()
  {
    node *temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
  }
};
int main()
{
  linkedlist ll;
  ll.insert(3);
  ll.insertathead(2);
  ll.insert(5);
  ll.insertatpoint(4,3);
  ll.deletion();
  ll.reverse();
  ll.print();
return 0;
}
