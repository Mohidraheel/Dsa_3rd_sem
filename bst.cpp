#include <iostream>
using namespace std;

class root
{
public:
    int data;
    root *left, *right;

    root(int item)
    {
        data = item;
        left = right = NULL;
    }
};

root* insertbst(root* &r, int data)
{
    if (r == NULL)
    {
        root *r = new root(data);
        return r;
    }
    if (data < r->data)
    {
        r->left = insertbst(r->left, data);
    }
    else
    {
        r->right = insertbst(r->right, data);
    }

    return r;
}

void input(root* &r)
{
    int data;
    cout << "Enter the data (-1 to stop): ";
    cin >> data;
    while (data!= -1)
    {
        r = insertbst(r, data);
        cout << "Enter the data (-1 to stop): ";
        cin >> data;
    }

}
void search(root* &r,int s)
{
    if(r==NULL)
    {
        cout << "Element not found" << endl;
        return;
    }
    if(s==r->data)
    {
        cout << "Element found" << endl;
        return;
    }
    if(s>r->data)
    {
        search(r->right,s);
    }
    if(s<r->data)
    {
        search(r->left,s);
    }
}

void print(root* &r)
{
    if (r!= NULL)
    {
        print(r->left);
        cout << r->data << " ";
        print(r->right);
    }
 

}
int main()
{
    root *root = NULL;
    input(root);
    cout << "Binary Search Tree: ";
    print(root);
    cout<<endl;
    search(root,5);

    return 0;
}
