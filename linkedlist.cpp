#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }

};

void insertatend(node* &head,int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void insertathead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
void deleteathead(node* &head)
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    node* temp=head;
    head=head->next;
    delete temp;
}

void deletion(node* &head,int val)
{
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=del->next;
    delete del;
}


void printlist(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main()
{
    node* head=NULL;
    insertatend(head,1);
    insertatend(head,7);
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);
    insertathead(head,8);
    deletion(head,3);
    
    cout<<"Original List: ";
    printlist(head);

return 0;
}
