#include<iostream>
using namespace std;
class node
{
  int data;
  node *next;
  node *prev;
  public:
  node(int data)
  {
    this->data=data;
    next=NULL;
  }
  node(int data,int d)
  {
     this->data=data;
     next=NULL;
     this->prev=NULL;

  }
  friend class singlelist;
  friend class doublelist;

};

class singlelist
{
  node *head;
  public:
  singlelist()
  {
    head=NULL;
  }
  void insertathead(int data)
  {
    node *nn=new node(data);
    nn->next=head;
    head=nn;
    
  }
  void insertatend(int data)
  {
    if(head==NULL)
    {
      insertathead(data);
      return;

    }
    node *temp=head;
    node *nn=new node(data);
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=nn;
    nn->next=NULL;
  }
  void merge(singlelist l1)
  {
    node *temp=head;
        if (temp == NULL) {
           
            head = l1.head;
            return;
        }
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=l1.head;
  }
  void sort()
  {
   node *temp;
   node *temp1;
   for(temp=head;temp!=NULL;temp=temp->next)
   {
    for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
    {
      if(temp->data>temp1->data)
      {
        swap(temp->data,temp1->data);
      }
    }
   }
  }

  void removeduplicates()
  {
    sort();
    node *temp=head;
    while(temp->next!=NULL)
    {
      if(temp->data==temp->next->data)
      {
        node *todelete=temp->next;
        if(todelete->next==NULL)
        {
          temp->next=NULL;
        }
        else
        {
          temp->next=temp->next->next;
        }
      }
      else
      {
        temp=temp->next;
      }
    }
  }


  void print()
  {
    node *temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" -> ";
      cout<<" ";
      temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
  }
  friend class doublelist;

};
class doublelist
{
  node *head;
  public:
  doublelist()
  {
    head=NULL;
  }
  void insertathead(int data)
  {
    node *nn=new node(data,0);
    nn->next=head;
    if(head!=NULL)
    {

    
    head->prev=nn;
    }
    nn->prev=NULL;
    head=nn;

  }
  void singletodouble(singlelist &l1)
  {
    node *temp=l1.head;
    while(temp!=NULL)
    {
      insertatend(temp->data);
      temp=temp->next;
    }
  }
  void insertatend(int data)
  {
    if(head==NULL)
    {
      insertathead(data);
      return;
    }
    node *nn=new node(data,0);
    node *temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=nn;
    nn->prev=temp;
    nn->next=NULL;
  }
  void print()
  {
    node *ptr=head;
    cout<<"NULL";
    while(ptr!=NULL)
    {
      cout<< " "<<ptr->prev<<" <- "<<ptr->next<<" -> ";
      cout<<endl;
      ptr=ptr->next;
    }
    cout<<"NULL";
    cout<<endl;
  }
};
int main()
{
  singlelist ll,l2;
  ll.insertatend(4);
  ll.insertatend(6);
  ll.insertatend(1);
  ll.insertatend(7);

  cout<<"list 1"<<endl;
  ll.print();


  cout<<endl;
  l2.insertatend(1);
  l2.insertatend(5);
  l2.insertatend(3);
  l2.insertatend(4);
  cout<<"list 2"<<endl;
  l2.print();
  cout<<"after merge and sort"<<endl;
  ll.merge(l2);
  ll.sort();
  ll.removeduplicates();
  ll.print();




  doublelist db;
  db.singletodouble(ll);
  db.print();
return 0;
}
