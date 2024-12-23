#include<iostream>
using namespace std;
class node
{
    int data;
    node *next;
    public:
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    friend class linkedlist;

};

class linkedlist
{
    public:
    node *head;
    linkedlist()
    {
        head=NULL;
    }
    void insertatfront(int data)
    {
        node *n=new node(data);
        n->next=head;
        head=n;
    }
    void insertatend(int data)
    {
        if(head==NULL)
        {
            insertatfront(data);
            return;
        }
        node *n=new node(data);
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;

    }

   node* reversek(node*&temp,int k)
   {
        node *current=temp;
        node *previousptr=NULL;
        node *nextptr; 
        int count=0;

        while(current!=NULL && count<k)
        {
            nextptr=current->next;
            current->next=previousptr;

            previousptr=current;
            current=nextptr;
            count++;
        }

        // if(nextptr!=NULL)
        // {
        //     temp->next=reversek(nextptr,k);
        // }
        // k groups reverse
        if(temp!=NULL)
        {
            temp->next=current;
        }
        // only k elements reverse
        return previousptr;
   }
  
    void print()
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
  


};


int main()
{
    linkedlist ll;

    
    ll.insertatend(2);
    ll.insertatfront(4);
    ll.insertatend(5);
    ll.insertatend(10);
    ll.insertatfront(3);
    ll.insertatend(7);
    
    cout << "Original Linked List: ";
    ll.print();

  
    int k = 3;
    
    ll.head = ll.reversek(ll.head, k);
    cout << "Linked List after reversing in groups of " << k << ": ";
    ll.print();

    return 0;
}