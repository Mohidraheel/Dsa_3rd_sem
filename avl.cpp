#include <iostream>
#include <vector>
using namespace std;

class node
{
  int data;
  node *right;
  node *left;
  int height;
  node()
  {
    data = 0;
    right = left = NULL;
    height = 0;
  }
  node(int data)
  {
    this->data = data;
    right = left = NULL;
    height = 0;
  }
  friend class avl;
};

class avl
{
  node *root;

public:
  avl()
  {
    root = NULL;
  }
  int getheight(node *r)
  {
    if (r == NULL)
    {
      return -1;
    }
    return r->height;
  }
  node *rightrotate(node *r)
  {
    node *x = r->left;
    node *t2 = x->right;

    x->right = r;
    r->left = t2;

    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    r->height = max(getheight(r->right), getheight(r->left)) + 1;

    return x;
  }

  node *leftrotate(node *r)
  {
    node *y = r->right;
    node *t2 = y->left;
    y->left = r;
    r->right = t2;
    r->height = max(getheight(r->right), getheight(r->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    return y;
  }
  int getbalace(node *r)
  {
    if (r == NULL)
    {
      return 0;
    }
    int left = getheight(r->left);
    int right = getheight(r->right);
    return left - right;
  }
  node *insert(node *r, int key)
  {
    if (r == NULL)
    {
      r = new node(key);
      return r;
    }
    else
    {
      if (r->data > key)
      {
        r->left = insert(r->left, key);
      }
      else
      {
        r->right = insert(r->right, key);
      }
    }
    r->height = max(getheight(r->left), getheight(r->right)) + 1;
    int balance = getbalace(r);

    if (balance > 1 && r->data > key)
    {
      return rightrotate(r);
    }
    if (balance < -1 && r->data < key)
    {
      return leftrotate(r);
    }
    if (balance > 1 && r->data < key)
    {
      r->left = leftrotate(r->left);
      return rightrotate(r);
    }
    if (balance < -1 && r->data > key)
    {
      r->right = rightrotate(r->right);
      return leftrotate(r);
    }
    return r;
  }
  node *findmin(node *r)
  {
    if(r==NULL)
    {
      return NULL;
    }
    node *current=r;
    while(current->left!=NULL)
    {
      current=current->left;
    }
    return current;

  }
  node* deletion(node *r, int key)
  {
    if (r == NULL)
    {
      return NULL;
    }
    if (r->data > key)
    {
      r->left = deletion(r->left, key);

    }
    else
    {
      if(r->data < key)
      {
        r->right = deletion(r->right, key);
      }
      else
      {
        if(r->left==NULL && r->right==NULL)
        {
          delete r;
          return NULL;
        }
        else
        {
          if(r->right ==NULL&&r->left!=NULL)
          {
            node *temp=r->left;
            delete r;
            return temp;
          }
          else
          {
            if(r->right!=NULL && r->left==NULL)
            {
              node *temp=r->right;
              delete r;
              return temp;
            }
            else
            {
              node *temp=findmin(r->right);
              r->data=temp->data;
              r->right=deletion(r->right,temp->data);
            }
          }
        }
      }

    }

    if(r==NULL)
    {
      return r;
    }
    r->height = max(getheight(r->left), getheight(r->right)) + 1;
    int balance = getbalace(r);
    if(balance > 1 && getbalace(r->left) >=0)
    {
      return rightrotate(r);
    }
    if(balance > 1 && getbalace(r->left) <0)
    {
      r->left = leftrotate(r->left);
      return rightrotate(r);
    }
    if(balance < -1 && getbalace(r->right) <=0)
    {
      return leftrotate(r);
    }
    if(balance < -1 && getbalace(r->right) >0)
    {
      r->right = rightrotate(r->right);
      return leftrotate(r);
    }
  }
  void insert(int key)
  {
    root = insert(root, key);
  }
  void inorder(node *r)
  {
    if (r == NULL)
    {
      return;
    }
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
  }
  void display()
  {
    inorder(root);
    cout << endl;
  }
  void preorder(node *r)
  {
    if (r == NULL)
    {
      return;
    }
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
  }

  void save(node *r, vector<int> &arr)
  {
    if (r == NULL)
    {
      return;
    }
    save(r->left, arr);
    arr.push_back(r->data);
    save(r->right, arr);
  }

  void price(int price)
  {
    vector<int> arr;
    save(root, arr);
    int min = 1000;
    int minvalue;
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {

      if (arr[i] < price)
      {
        minvalue = price - arr[i];
        if (minvalue < min)
        {
          min = minvalue;
          j = arr[i];
        }
      }
    }
    cout << "Minimum price difference is " << min << ", and the corresponding node is " << j << endl;
  }
};
int main()
{
  avl a;
  a.insert(100);
  a.insert(150);
  a.insert(200);
  a.insert(300);
  a.insert(350);
  a.insert(400);
  cout << "Inorder traversal of AVL tree is: ";
  a.display();
  a.price(250);

  return 0;
}
