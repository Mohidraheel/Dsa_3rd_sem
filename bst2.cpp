#include<iostream>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node *right;
    node *left;
    
    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }

};
node* constructbst(int preorder[],int* index,int key,int min,int max,int n)
{
    //base case
    if(*index>=n)
    {
        return NULL;
    }
    node *r=NULL;
    if(key>min && key<max)
    {
        r=new node(key);
        *index+=1;
        if(*index<n)
        {
            r->left=constructbst(preorder,index,preorder[*index],min,key,n);
        }

        if(*index<n)
        {
            r->right=constructbst(preorder,index,preorder[*index],key,max,n);
        }

    }
    return r;
}

void print(node* r)
{
    if(r!=NULL)
    {
        cout<<r->data<<" ";
        print(r->left);
        print(r->right);
    }

}
int main()
{
    int preorder[]={8,3,10,1,6,14,4,7,13};
    int n=sizeof(preorder)/sizeof(preorder[0]);
    int index=0;
    node* root=constructbst(preorder,&index,preorder[0],INT_MIN,INT_MAX,n);
    cout<<"Inorder traversal of constructed BST is: ";
    print(root);
    
return 0;
}
