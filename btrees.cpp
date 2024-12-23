#include <iostream>
#include <string>
using namespace std;

// Define the record structure
struct record
{
  int id;
  string name;
  int age;

  record(int id = 0, string name = "", int age = 0) : id(id), name(name), age(age) {}

  // Overload comparison operators for easy comparison
  bool operator<(const record &other) const { return id < other.id; }
  bool operator>(const record &other) const { return id > other.id; }
  bool operator==(const record &other) const { return id == other.id; }
};



class BTreeNode {
public:
  record *records;
  BTreeNode **children;
  int n;
  bool leaf;

  BTreeNode(int order, bool isLeaf) {
    leaf = isLeaf;
    n = 0;
    records = new record[order - 1];
    children = new BTreeNode *[order];
    for (int i = 0; i < order; i++) {
      children[i] = nullptr;
    }
  }

  ~BTreeNode() {
    delete[] records;
    delete[] children;
  }
};

class BTree {
private:
  BTreeNode *root;
  int order;

  void splitChild(BTreeNode *parent, int index) {
    BTreeNode *child = parent->children[index];
    BTreeNode *sibling = new BTreeNode(order, child->leaf);
    sibling->n = (order - 1) / 2;

    // Move second half of records to sibling
    for (int i = 0; i < sibling->n; i++) {
      sibling->records[i] = child->records[i + (order / 2)];
    }

    // Move child pointers if not a leaf
    if (!child->leaf) {
      for (int i = 0; i <= sibling->n; i++) {
        sibling->children[i] = child->children[i + (order / 2)];
      }
    }

    child->n = (order - 1) / 2;

    // Insert new child into parent
    for (int i = parent->n; i >= index + 1; i--) {
      parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = sibling;

    // Insert new record into parent
    for (int i = parent->n - 1; i >= index; i--) {
      parent->records[i + 1] = parent->records[i];
    }
    parent->records[index] = child->records[(order - 1) / 2];
    parent->n++;
  }

  void insertNonFull(BTreeNode *node, const record &rec) {
    int i = node->n - 1;

    // Check for duplicates
    for (int j = 0; j < node->n; j++) {
      if (node->records[j].id == rec.id) {
        cout << "Duplicate ID: " << rec.id << " already exists. Skipping insertion.\n";
        return;
      }
    }

    if (node->leaf) {
      while (i >= 0 && rec < node->records[i]) {
        node->records[i + 1] = node->records[i];
        i--;
      }
      node->records[i + 1] = rec;
      node->n++;
    } else {
      while (i >= 0 && rec < node->records[i]) {
        i--;
      }

      i++;
      if (node->children[i]->n == order - 1) {
        splitChild(node, i);

        if (rec > node->records[i]) {
          i++;
        }
      }
      insertNonFull(node->children[i], rec);
    }
  }

  void traverse(BTreeNode *node) {
    int i;
    for (i = 0; i < node->n; i++) {
      if (!node->leaf) {
        traverse(node->children[i]);
      }
      cout << "ID: " << node->records[i].id << ", Name: " << node->records[i].name
           << ", Age: " << node->records[i].age << endl;
    }

    if (!node->leaf) {
      traverse(node->children[i]);
    }
  }

  BTreeNode *search(BTreeNode *node, int id) {
    int i = 0;
    while (i < node->n && id > node->records[i].id) {
      i++;
    }

    if (i < node->n && id == node->records[i].id) {
      return node;
    }

    if (node->leaf) {
      return nullptr;
    }

    return search(node->children[i], id);
  }

  void *update(BTreeNode *root, int id, string name, int age) {
    int i = 0;
    // Function implementation placeholder
  }

public:
  BTree(int order) : root(nullptr), order(order) {}

  void insert(const record &rec) {
    if (!root) {
      root = new BTreeNode(order, true);
      root->records[0] = rec;
      root->n = 1;
    } else {
      if (root->n == order - 1) {
        BTreeNode *newRoot = new BTreeNode(order, false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);

        int i = (newRoot->records[0] < rec) ? 1 : 0;
        insertNonFull(newRoot->children[i], rec);
        root = newRoot;
      } else {
        insertNonFull(root, rec);
      }
    }
  }

  void traverse() {
    if (root) {
      traverse(root);
    }
    cout << endl;
  }

  bool search(int id) {
    return (search(root, id) != nullptr);
  }

  ~BTree() {
    delete root;
  }
};


int main()
{
  int order;
  cout << "Enter the order (minimum degree) of the B-Tree: ";
  cin >> order;

  if (order < 3)
  {
    cout << "Order must be at least 3.\n";
    return 0;
  }

  BTree t(order);

  t.insert(record(10, "Alice", 25));
  t.insert(record(20, "Bob", 30));
  t.insert(record(5, "Charlie", 22));
  t.insert(record(6, "David", 27));
  t.insert(record(12, "Eve", 35));
  t.insert(record(30, "Frank", 40));
  t.insert(record(7, "Grace", 29));
  t.insert(record(17, "Hannah", 33));

  cout << "Traversal of the constructed tree is:\n";
  t.traverse();
  cout<<endl;

  int searchId = 6;
  cout << "Searching for ID " << searchId << ": "
       << (t.search(searchId) ? "Found" : "Not Found") << endl;
       cout<<endl;

  searchId = 15;
  cout << "Searching for ID " << searchId << ": "
       << (t.search(searchId) ? "Found" : "Not Found") << endl;

  return 0;
}
