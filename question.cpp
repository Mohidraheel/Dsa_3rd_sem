#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;
struct record
{
  int id;
  string name;
  int age;
  record(int id = 0, string name = "", int age = 0) : id(id), name(name), age(age) {}
  bool operator<(const record &other) const
  {
    return id < other.id;
  }
  bool operator>(const record &other) const
  {
    return id > other.id;
  }
  bool operator==(const record &other) const
  {
    return id == other.id;
  }
};
//--------BST--------
struct bstNode
{
  record data;
  bstNode *left;
  bstNode *right;
  bstNode(record rec) : data(rec), left(nullptr), right(nullptr) {}
};
class bst
{
  bstNode *root;
  bstNode *insert(bstNode *r, record d)
  {
    if (r == NULL)
    {
      r = new bstNode(d);
      return r;
    }

    if (r->data.id < d.id)
    {
      r->right = insert(r->right, d);
    }
    else
    {
      if (r->data.id > d.id)
      {
        r->left = insert(r->left, d);
      }
      else
      {
        cout << "Record with ID " << d.id << " already exists." << endl;
      }
    }
    return r;
  }

  bool search(bstNode *r, int id)
  {
    if (r == nullptr)
    {
      return false;
    }
    if (r->data.id == id)
    {
      return true;
    }

    if (r->data.id > id)
    {
      return search(r->left, id);
    }
    else
    {
      return search(r->right, id);
    }
  }

  bstNode *update(bstNode *r, int id, string name, int age)
  {
    if (r == nullptr)
    {
      return nullptr;
    }

    if (r->data.id == id)
    {
      r->data.age = age;
      r->data.name = name;
      return r;
    }

    if (r->data.id < id)
    {
      return update(r->right, id, name, age);
    }
    else
    {
      return update(r->left, id, name, age);
    }
  }

  bstNode *findmin(bstNode *r)
  {
    if (r == NULL)
    {
      return nullptr;
    }
    if (r->left == NULL)
    {
      return r;
    }

    return findmin(r->left);
  }

  bstNode *findmax(bstNode *r)
  {
    if (r == NULL)
    {
      return nullptr;
    }
    if (r->right == NULL)
    {
      return r;
    }
    return findmax(r->right);
  }

  bstNode *deletion(bstNode *r, int id)
  {
    if (r == NULL)
    {
      return nullptr;
    }
    if (id < r->data.id)
    {
      r->left = deletion(r->left, id);
    }
    else if (id > r->data.id)
    {
      r->right = deletion(r->right, id);
    }
    else
    {

      if (r->left == NULL && r->right == NULL)
      {
        delete r;
        return NULL;
      }
      else
      {
        if (r->left == NULL && r->right != NULL)
        {
          bstNode *temp = r->right;
          delete r;
          return temp;
        }
        else
        {
          if (r->left != NULL && r->right == NULL)
          {
            bstNode *temp = r->left;
            delete r;
            return temp;
          }
          else
          {
            bstNode *temp = findmin(r->right);
            r->data.id = temp->data.id;
            r->right = deletion(r->right, temp->data.id);
          }
        }
      }
    }
    return r;
  }

public:
  bst()
  {
    root = NULL;
  }
  void insert(record d)
  {
    root = insert(root, d);
  }

  bool search(int id)
  {
    return search(root, id);
  }

  bool update(int id, string name, int age)
  {
    bstNode *updatedNode = update(root, id, name, age);
    return updatedNode != nullptr;
  }
  void deleteNode(int id)
  {
    root = deletion(root, id);
  }
};
//-----AVL-----
struct avlnode
{
  record data;
  avlnode *left;
  avlnode *right;
  int height;
  avlnode(record rec) : data(rec), left(nullptr), right(nullptr), height(0) {}
};
class avl
{

  avlnode *root;
  int getheight(avlnode *r)
  {
    if (r == NULL)
    {
      return -1;
    }
    return r->height;
  }
  avlnode *rightrotate(avlnode *y)
  {
    avlnode *x = y->left;
    avlnode *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
  }
  avlnode *leftrotate(avlnode *y)
  {
    avlnode *x = y->right;
    avlnode *temp = x->left;

    x->left = y;
    y->right = temp;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
  }

  int getbalance(avlnode *r)
  {
    if (r == NULL)
    {
      return 0;
    }
    int left = getheight(r->left);
    int right = getheight(r->right);
    return (left - right);
  }
  avlnode *insert(avlnode *root, record d)
  {
    if (root == NULL)
    {
      root = new avlnode(d);
      return root;
    }
    if (d.id < root->data.id)
    {
      root->left = insert(root->left, d);
    }
    else
    {
      root->right = insert(root->right, d);
    }

    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    int balance = getbalance(root);

    if (balance > 1 && root->left->data.id > d.id)
    {
      return rightrotate(root);
    }
    if (balance < -1 && root->right->data.id < d.id)
    {
      return leftrotate(root);
    }

    if (balance > 1 && root->left->data.id < d.id)
    {
      root->right = leftrotate(root->right);
      return rightrotate(root);
    }

    if (balance < -1 && root->right->data.id > d.id)
    {
      root->left = rightrotate(root->left);
      return leftrotate(root);
    }
    return root;
  }
  avlnode *minvalue(avlnode *root)
  {
    avlnode *current = root;
    while (current->left != NULL)
    {
      current = current->left;
    }
    return current;
  }
  avlnode *deletion(avlnode *root, record key)
  {
    if (root == NULL)
    {
      return NULL;
    }

    if (root->data.id < key.id)
    {
      root->right = deletion(root->right, key);
    }
    else
    {
      if (root->data.id > key.id)
      {
        root->left = deletion(root->left, key);
      }
      else
      {
        if (root->left == NULL && root->right == NULL)
        {
          delete root;
          return NULL;
        }
        else
        {
          if (root->right == NULL && root->left != NULL)
          {
            avlnode *temp = root->left;
            delete root;
            return temp;
          }
          else
          {
            if (root->left == NULL && root->right != NULL)
            {
              avlnode *temp = root->right;
              delete root;
              return temp;
            }
            else
            {
              avlnode *temp = minvalue(root->right);
              root->data = temp->data;
              root->right = deletion(root->right, temp->data);
            }
          }
        }
      }
    }
    if (root == NULL)
    {
      return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int balance = getbalance(root);

    if (balance > 1 && getbalance(root->left) >= 0)
      return rightrotate(root);

    if (balance > 1 && getbalance(root->left) < 0)
    {
      root->left = leftrotate(root->left);
      return rightrotate(root);
    }

    if (balance < -1 && getbalance(root->right) <= 0)
      return leftrotate(root);

    if (balance < -1 && getbalance(root->right) > 0)
    {
      root->right = rightrotate(root->right);
      return leftrotate(root);
    }

    return root;
  }
  avlnode *update(avlnode *r, int id, string name, int age)
  {
    if (r == nullptr)
    {
      return nullptr;
    }

    if (r->data.id == id)
    {
      r->data.age = age;
      r->data.name = name;
      return r;
    }

    if (r->data.id < id)
    {
      return update(r->right, id, name, age);
    }
    else
    {
      return update(r->left, id, name, age);
    }
  }

  bool search(avlnode *r, int id)
  {
    if (r == nullptr)
    {
      return false;
    }
    if (r->data.id == id)
    {
      return true;
    }

    if (r->data.id > id)
    {
      return search(r->left, id);
    }
    else
    {
      return search(r->right, id);
    }
  }

public:
  avl() : root(nullptr) {}

  void insert(record d)
  {
    root = insert(root, d);
  }

  void remove(record d)
  {
    root = deletion(root, d);
  }

  bool search(int id)
  {
    return search(root, id);
  }

  void update(int id, string name, int age)
  {
    update(root, id, name, age);
  }
  void inorder(avlnode *r)
  {
    if (r == nullptr)
      return;

    inorder(r->left);
    cout << "(" << r->data.id << ", " << r->data.name << ", " << r->data.age << ") ";
    inorder(r->right);
  }
  void display()
  {
    cout << "Tree (Inorder): ";
    inorder(root);
    cout << endl;
  }
};

//--b tree
class BTreeNode
{
public:
  record *records;
  BTreeNode **children;
  int n;
  bool leaf;

  BTreeNode(int order, bool isLeaf)
  {
    leaf = isLeaf;
    n = 0;
    records = new record[order - 1];
    children = new BTreeNode *[order];
    for (int i = 0; i < order; i++)
    {
      children[i] = nullptr;
    }
  }

  ~BTreeNode()
  {
    delete[] records;
    delete[] children;
  }
};

class BTree
{
private:
  BTreeNode *root;
  int order;

  void sc(BTreeNode *parent, int index)
  {
    BTreeNode *child = parent->children[index];

    BTreeNode *sibling = new BTreeNode(order, child->leaf);

    sibling->n = (order - 1) / 2;

    for (int i = 0; i < sibling->n; i++)
    {

      sibling->records[i] = child->records[i + (order / 2)];
    }

    if (!child->leaf)
    {
      for (int i = 0; i <= sibling->n; i++)
      {
        sibling->children[i] = child->children[i + (order / 2)];
      }
    }

    child->n = (order - 1) / 2;

    for (int i = parent->n; i >= index + 1; i--)
    {
      parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = sibling;

    for (int i = parent->n - 1; i >= index; i--)
    {
      parent->records[i + 1] = parent->records[i];
    }
    parent->records[index] = child->records[(order - 1) / 2];
    parent->n++;
  }

  void insertbt(BTreeNode *node, const record &rec)
  {
    int i = node->n - 1;

    for (int j = 0; j < node->n; j++)
    {
      if (node->records[j].id == rec.id)
      {
        cout << "Already Exist: " << rec.id <<endl;
        return;
      }
    }

    if (node->leaf)
    {
      while (i >= 0 && rec < node->records[i])
      {
        node->records[i + 1] = node->records[i];
        i--;
      }
      node->records[i + 1] = rec;
      node->n++;
    }
    else
    {
      while (i >= 0 && rec < node->records[i])
      {
        i--;
      }

      i++;
      if (node->children[i]->n == order - 1)
      {
        sc(node, i);

        if (rec > node->records[i])
        {
          i++;
        }
      }
      insertbt(node->children[i], rec);
    }
  }
  void deleteFromNode(BTreeNode *node, int index)
  {
    if (node->leaf)
    {

      for (int i = index + 1; i < node->n; i++)
      {
        node->records[i - 1] = node->records[i];
      }
      node->n--;
    }
    else
    {
      BTreeNode *child = node->children[index];
      if (child->n > (order / 2))
      {
        BTreeNode *pred = child;
        while (!pred->leaf)
        {
          pred = pred->children[pred->n];
        }

        node->records[index] = pred->records[pred->n - 1];
        deleteFromNode(child, pred->n - 1);
      }
      else
      {
        BTreeNode *sibling = (index > 0) ? node->children[index - 1] : node->children[index + 1];
        if (index > 0)
        {
          sibling->records[sibling->n] = node->records[index - 1];
          node->records[index - 1] = sibling->records[sibling->n - 1];
          node->children[index - 1] = sibling->children[sibling->n - 1];
          node->n--;
        }
        else
        {
          sibling->records[sibling->n] = node->records[index];
          node->records[index] = sibling->records[0];
          node->children[index + 1] = sibling->children[0];
          node->n--;
        }
      }
    }
  }
  void removefromnode(BTreeNode *node, int id)
  {
    int index = 0;
    while (index < node->n && node->records[index].id < id)
    {
      index++;
    }

    if (index < node->n && node->records[index].id == id)
    {

      deleteFromNode(node, index);
    }
    else if (!node->leaf)
    {
      removefromnode(node->children[index], id);
    }
  }

  void traverse1(BTreeNode *node)
  {
    int i;
    for (i = 0; i < node->n; i++)
    {
      if (!node->leaf)
      {
        traverse1(node->children[i]);
      }
      cout << "id: " << node->records[i].id << ", name: " << node->records[i].name
           << ", age: " << node->records[i].age << endl;
    }

    if (!node->leaf)
    {
      traverse1(node->children[i]);
    }
  }

  BTreeNode *search(BTreeNode *node, int id)
  {
    int i = 0;
    while (i < node->n && id > node->records[i].id)
    {
      i++;
    }

    if (i < node->n && id == node->records[i].id)
    {
      return node;
    }

    if (node->leaf)
    {
      return nullptr;
    }

    return search(node->children[i], id);
  }

  BTreeNode *update(BTreeNode *root, int id, string n, int a)
  {
    int i = 0;
    while (i < root->n && id > root->records[i].id)
    {
      i++;
    }

    if (i < root->n && id == root->records[i].id)
    {
      root->records[i].age = a;
      root->records[i].name = n;
      return root;
    }

    if (root->leaf)
    {
      return nullptr;
    }

    return update(root->children[i], id, n, a);
  }

public:
  BTree(int order) : root(nullptr), order(order) {}

  void insert(const record &rec)
  {
    if (!root)
    {
      root = new BTreeNode(order, true);
      root->records[0] = rec;
      root->n = 1;
    }
    else
    {
      if (root->n == order - 1)
      {
        BTreeNode *newRoot = new BTreeNode(order, false);
        newRoot->children[0] = root;
        sc(newRoot, 0);

        int i = (newRoot->records[0] < rec) ? 1 : 0;
        insertbt(newRoot->children[i], rec);
        root = newRoot;
      }
      else
      {
        insertbt(root, rec);
      }
    }
  }
  void remove(int id)
  {
    if (root)
    {
      removefromnode(root, id);
    }
  }

  void traverse()
  {
    if (root)
    {
      traverse1(root);
    }
    cout << endl;
  }

  bool search(int id)
  {
    return (search(root, id) != nullptr);
  }

  void update(int id, string name, int age)
  {
    root = update(root, id, name, age);
  }

  ~BTree()
  {
    delete root;
  }
};
//-----------------Performance checking
class performanceanalysis
{

  void avlPerformanceAnalysis()
  {
    cout<<"AVL-TREE"<<endl;
    avl tree;
    vector<record> records;
    for (int i = 0; i < 1000; i++)
    {
      records.push_back(record(i, "Mohid" + to_string(i), rand() % 100 + 1));
    }
    auto start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.insert(rec);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Insertion Time: " << duration.count() << " microseconds for 1000 records" << endl;
    
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.search(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Search Time: " << duration.count() << " microseconds for 1000 records" << endl;

    int i = 5;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.update(rec.id, "Mohid" + to_string(i), rand() % 100 + 1);
      i++;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Update Time: " << duration.count() << " microseconds for 1000 records" << endl;

    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.remove(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "AVL Deletion Time: " << duration.count() << " microseconds for 1000 records" << endl;
  }

  void btreePerformanceAnalysis()
  {
     cout<<"B-TREE"<<endl;
    BTree tree(3);
    vector<record> records;
    for (int i = 0; i < 1000; i++)
    {
      records.push_back(record(i, "Name" + to_string(i), rand() % 100 + 1));
    }
    auto start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.insert(rec);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "BTree Insertion Time: " << duration.count() << " microseconds for 1000 records" << endl;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.search(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BTree Search Time: " << duration.count() << " microseconds for 1000 records" << endl;

    int i = 2;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.update(rec.id, "Mohid" + to_string(i), rand() % 100 + 1);
      i++;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BTree Update Time: " << duration.count() << " microseconds for 1000 records" << endl;

    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.remove(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BTree Deletion Time: " << duration.count() << " microseconds for 1000 records" << endl;
  }

  void bstPerformanceAnalysis()
  {
     cout<<"BST-TREE"<<endl;
    bst tree;
    vector<record> records;

    for (int i = 0; i < 1000; i++)
    {
      records.push_back(record(i, "Mohid" + to_string(i), rand() % 100 + 1));
    }

    auto start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.insert(rec);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "BST Insertion Time: " << duration.count() << " microseconds for 1000 records" << endl;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.search(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BST Search Time: " << duration.count() << " microseconds for 1000 records" << endl;
    int i = 10;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.update(rec.id, "Mohid" + to_string(i), rand() % 100 + 1);
      i++;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BST Update Time: " << duration.count() << " microseconds for 1000 records" << endl;
    start = high_resolution_clock::now();
    for (auto &rec : records)
    {
      tree.deleteNode(rec.id);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BST Deletion Time: " << duration.count() << " microseconds for 1000 records" << endl;
  }
  public:
  void perform()
  {
    avlPerformanceAnalysis();
    cout << endl;
    bstPerformanceAnalysis();
    cout << endl;
    btreePerformanceAnalysis();
  }
};

int main()
{
  performanceanalysis pf;
  pf.perform();
  //23K-3000

  return 0;
}
