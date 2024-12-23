#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node
{
  node *right;
  node *left;

public:
  int data;
  node()
  {
    data = 0;
    right = left = NULL;
  }
  node(int data)
  {
    this->data = data;
    right = left = NULL;
  }

  node *insert(node *&r, int data)
  {
    if (r == NULL)
    {
      r = new node(data);
      return r;
    }
    if (data > r->data)
    {
      r->right = insert(r->right, data);
    }
    else
    {
      r->left = insert(r->left, data);
    }
    return r;
  }

  node *search(node *r, int data)
  {
    if (r == NULL)
    {
      return NULL;
    }

    if (r->data == data)
    {
      return r;
    }

    if (r->data > data)
    {
      return search(r->left, data);
    }
    else
    {
      return search(r->right, data);
    }
  }

  node *findmin(node *r)
  {
    if (r == NULL)
    {
      return NULL;
    }
    if (r->left == NULL)
    {
      return r;
    }
    return findmin(r->left);
  }

  node *findmax(node *r)
  {
    if (r == NULL)
    {
      return NULL;
    }

    if (r->right == NULL)
    {
      return r;
    }

    return findmax(r->right);
  }

 node *predecessor1(node *r, node *target)
{
    if (target == NULL)
    {
        return NULL;
    }

    
    if (target->left != NULL)
    {
        return findmax(target->left);
    }

   
    node *pred = NULL;
    while (r != NULL)
    {
        if (target->data > r->data)
        {
            pred = r; // Update predecessor
            r = r->right;
        }
        else if (target->data < r->data)
        {
            r = r->left;
        }
        else
        {
            break; // Target found, stop loop
        }
    }
    return pred;
}

node *sucessor(node *r, node *target)
{
    if (target == NULL)
    {
        return NULL;
    }

    // Case 1: If right subtree exists, successor is the minimum of the right subtree
    if (target->right != NULL)
    {
        return findmin(target->right);
    }

    // Case 2: No right subtree, traverse from root to find successor
    node *succ = NULL;
    while (r != NULL)
    {
        if (target->data < r->data)
        {
            succ = r; // Update successor
            r = r->left;
        }
        else if (target->data > r->data)
        {
            r = r->right;
        }
        else
        {
            break; // Target found, stop loop
        }
    }
    return succ;
}


  node *deletion(int data, node *r)
  {
    if (r == NULL)
    {
      return NULL;
    }

    if (data < r->data)
    {
      r->left = deletion(data, r->left);
    }
    else if (data > r->data)
    {
      r->right = deletion(data, r->right);
    }
    else
    {

      if (r->left == NULL && r->right == NULL)
      {
        // Case 1: No children (leaf node)
        delete r;
        return NULL;
      }
      else if (r->left == NULL && r->right != NULL)
      {
        // Case 2: Only right child
        node *temp = r->right;
        delete r;
        return temp;
      }
      else if (r->right == NULL && r->left != NULL)
      {
        // Case 2: Only left child
        node *temp = r->left;
        delete r;
        return temp;
      }
      else
      {
        // Case 3: Two children
        node *temp = findmin(r->right);
        r->data = temp->data;
        r->right = deletion(temp->data, r->right);
      }
    }
    return r;
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

  void postorder(node *r)
  {
    if (r == NULL)
    {
      return;
    }
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
  }

  void bfs(node *r)
  {
    if (r == NULL)
    {
      return;
    }

    queue<node *> q1;
    q1.push(r);
    while (!q1.empty())
    {
      int n = q1.size();
      for (int i = 0; i < n; i++)
      {
        node *temp = q1.front();
        q1.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
          q1.push(temp->left);
        }
        if (temp->right)
        {
          q1.push(temp->right);
        }
      }
      cout << endl;
    }
  }

  int findheight(node *r)
  {
    if (r == NULL)
    {
      return -1;
    }

    int lefth = findheight(r->left);
    int righth = findheight(r->right);
    return max(lefth, righth) + 1;
  }

  bool isbst(node *r, int min, int max)
  {
    if (r == NULL)
    {
      return true;
    }
    if (r->data >= min && r->data <= max)
    {
      bool left = isbst(r->left, min, r->data);
      bool right = isbst(r->right, r->data, max);
      return left && right;
    }
    else
    {
      return false;
    }
  }

  int ksmallest(node *r, int &i, int k)
  {
    if (r == NULL)
    {
      return -1;
    }

    int left = ksmallest(r->left, i, k);
    if (left != -1)
    {
      return left;
    }

    i++;
    if (i == k)
    {
      return r->data;
    }

    return ksmallest(r->right, i, k);
  }

  int klargest(node *r, int &i, int k)
  {
    if (r == NULL)
    {
      return -1;
    }

    int right = klargest(r->right, i, k);
    if (right != -1)
    {
      return right;
    }
    i++;
    if (i == k)
    {
      return r->data;
    }
    return klargest(r->left, i, k);
  }

  int countleaf(node *r)
  {
    if(r==NULL)
    {
      return 0;
    }

    if(r->right == NULL && r->left ==NULL)
    {
      return 1;
    }

    return countleaf(r->right )+ countleaf( r->left);
  }
};

int main()
{
    node *root = NULL;
    root = root->insert(root, 7);
    root = root->insert(root, 9);
    root = root->insert(root, 8);
    root = root->insert(root, 3);
    root = root->insert(root, 1);

    cout << "Inorder traversal: ";
    root->inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    root->preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    root->postorder(root);
    cout << endl;

    // Find and display the height of the BST
    int ans3 = root->findheight(root);
    cout << "Height of BST: " << ans3 << endl;  // Ensure this is printed

    cout << "Deletion: ";
    root = root->deletion(7, root);
    cout << endl;

    cout << "BFS traversal: ";
    root->bfs(root);
    cout << endl;

    // Continue with other operations as before...
    node *s = root->search(root, 7);
    if (s)
    {
        cout << "Search for 7 found " << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    node *t = root->findmin(root);
    cout << "Minimum value: " << t->data << endl;

    node *temp = root->findmax(root);
    cout << "Maximum value: " << temp->data << endl;

    if (root->isbst(root, INT_MIN, INT_MAX))
    {
        cout << "Tree is a bst" << endl;
    }
    else
    {
        cout << "Not a BST" << endl;
    }

    int i = 0;
    int ans = root->ksmallest(root, i, 2);
    cout << "2nd smallest element: " << ans << endl;

    int j = 0;
    int ans2 = root->klargest(root, j, 2);
    cout << "2nd largest element: " << ans2 << endl;

    node *target = root->search(root, 9);
    if (target)
    {
        node *pred = root->predecessor1(root, target);
        if (pred != NULL)
        {
            cout << "Predecessor of " << target->data << ": " << pred->data << endl;
        }
        else
        {
            cout << "Predecessor of " << target->data << ": None" << endl;
        }

        node *succ = root->sucessor(root, target);
        if (succ != NULL)
        {
            cout << "Successor of " << target->data << ": " << succ->data << endl;
        }
        else
        {
            cout << "Successor of " << target->data << ": None" << endl;
        }
    }


    cout<<"Total Leaf Nodes:"<<root->countleaf(root);
    return 0;
}
