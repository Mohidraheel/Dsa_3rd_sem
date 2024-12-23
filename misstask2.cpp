#include<iostream>
using namespace std;
int factorial(int n)
{
  int f=1;
  for(int i=1;i<=n;i++)
  {
    f*=i;
  }
  return f;

  
}

bool isprime(int d)
{
  if(d<=1)
  {
    return false;
  }
  if(d<=3)
  {
    return true;
  }
  if(d%2==0 || d%3==0)
  {
    return false;
  }

  for(int i=5;i<d;i++)
  {
    if(d%i==0)
    {
      return false;
    }

  }
  return true;
}

class node
{
  int data;
  node *next;
  public:
  node(int data)
  {
    this->data=data;
    next=NULL;
  }
  friend class singlelist;
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
    node *nn=new node(data);
    node *temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=nn;
  }
  void deleteathead()
  {
    node *todelete=head;
    head=head->next;
    delete todelete;
  }

  void deleteatend()
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

  void insertcyle(int d)
  {
    node *temp=head;
    while(temp!=NULL)
    {
      if(temp->data==d)
      {
        break;
      }
      temp=temp->next;
    }

    node *temp1=head;
      while(temp1->next!=NULL)
    {
    
      temp1=temp1->next;
    }

    temp1->next=temp;

  }

  void print()
  {
    node *temp=head;
    while(temp!=NULL)
    {
  
          cout<<temp->data<<" "<<" -> ";
          temp=temp->next;
        
      
    }
    cout<<"NULL";
    cout<<endl;

  }
  bool detectcycle()
  {
    node *fast=head;
    node *slow=head;

    while(fast!=NULL || fast->next!=NULL)
    {
       fast=fast->next->next;
       slow=slow->next;
       
       if(fast==slow)
       {
        return true;
       }


    }
    return false;

  }
  
void removecycle()
{
  node *fast=head;
  node *slow=head;
  while(fast->next!=NULL || fast!=NULL )
  {
    fast=fast->next->next;
    slow=slow->next;
    if(slow==fast)
    {
      break;
    }
  }

  fast=head;
  while(fast!=slow)
  {
    fast=fast->next;
    slow=slow->next;
  }
  node *cycle=fast;
  node *temp=cycle;
  while(temp->next!=cycle)
  {
    temp=temp->next;
  }
  temp->next=NULL;
}

void newremovecycle()
{
  if(head==head->next)
  {
    head->next=NULL;
    return;
  }
  node *fast=head;
  node *slow=head;
  int found=0;
  while(fast!=NULL && fast->next!=NULL)
  {
    fast=fast->next->next;
    slow=slow->next;
    if(slow==fast)
    {
      found=1;
      slow=head;
      while(slow!=fast)
      {
        slow=slow->next;
        fast=fast->next;
      }
      node *toremove=fast;
      while(toremove->next!=slow)
      {
        toremove=toremove->next;
      }
      toremove->next=NULL;
      return;
    }

  }
  if(found==0)
  {
    cout<<"No Cycle in list"<<endl;
  }
}

void sum()
{
  int s=0;
  node *temp=head;
  while(temp!=NULL)
  {
    if(isprime(temp->data))
    {
      s+=factorial(temp->data);
    }
    temp=temp->next;
  }
  cout<<s;
}

};


int main()
{
  singlelist ll;
  ll.insertatend(5);
  ll.insertatend(6);
  ll.insertatend(7);
  ll.insertathead(2);
  ll.insertcyle(6);

  cout<<ll.detectcycle();
  ll.newremovecycle();
    ll.print();
    ll.sum();




  return 0;
}
