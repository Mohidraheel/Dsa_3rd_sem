#include <iostream>
#include <stack>
using namespace std;

class node
{
    int data;
    node *next;

public:
    node(int data)
    {
        next = NULL;
        this->data = data;
    }
    friend class MyStack; // Renamed to MyStack
};

class MyStack
{
    node *top;

public:
    MyStack()
    {
        top = NULL;
    }

    void push(int data)
    {
        node *nn = new node(data);
        nn->next = top;
        top = nn;
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            node *todelete = top;
            top = top->next;
            delete todelete;
        }
    }

    bool isempty()
    {
        return top == NULL;
    }

    void peek()
    {
        if (!isempty())
        {
            cout << top->data;
        }
        else
        {
            cout << "Stack is empty";
        }
    }

    void print()
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    MyStack s;
    s.push(2);
    s.push(3);

    s.peek();
    cout << endl;
    cout << "_____________________________________" << endl;
    s.print();
    cout << endl;
    cout << "calling pop function" << endl;
    s.pop();
    s.peek();
    cout << endl;
    if (s.isempty())
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    cout << "calling pop function" << endl;
    s.pop();
    if (s.isempty())
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
  
    return 0;
}
