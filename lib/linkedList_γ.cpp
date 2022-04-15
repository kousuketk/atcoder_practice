#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int key) {
  Node *x, *y, *z;
  z = new Node;
  z->left = NIL;
  z->right = NIL;
  z->key = key;
  y = NIL;
  x = root;
  while(x != NIL) {
    y = x;
    if(z->key < x->key) x = x->left;
    else x = x->right;
  }
  z->parent = y;
  if(y == NIL) root = z;
  else if(z->key < y->key) y->left = z;
  else y->right = z;
}

Node* find(int key) {
  Node *x;
  x = root;
  while(x != NIL && x->key != key) {
    if(key < x->key) x = x->left;
    else x = x->right;
  }
  return x;
}

Node* next_node(Node *node) {
  Node *x;
  if(node->right != NIL) {
    x = node->right;
    while(x->left != NIL) {
      x = x->left;
    }
  } else {
    x = node;
    while(x->parent != NIL && x == x->parent->right) {
      x = x->parent;
    }
    x = x->parent;
  }
  return x;
}

void delete_node(int key) {
  Node *x, *y, *z;
  z = find(key);
  if(z->left == NIL || z->right == NIL) {
    y = z;
  } else {
    y = next_node(z);
  }
  if(y->left != NIL) x = y->left;
  else x = y->right;
  if(x != NIL) x->parent = y->parent;
  if(y->parent == NIL) root = x;
  else if(y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;
  if(z != y) z->key = y->key;
  delete y;
}

void preorder(Node* node) {
  if(node == NIL) return;
  cout << " " << node->key;
  if(node->left != NIL) preorder(node->left);
  if(node->right != NIL) preorder(node->right);
}

void inorder(Node* node) {
  if(node == NIL) return;
  if(node->left != NIL) inorder(node->left);
  cout << " " << node->key;
  if(node->right != NIL) inorder(node->right);
}

void print() {
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
}

int main() {
  int i, m, key;
  string command;
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> command;
    if(command[0] == 'i') {
      cin >> key;
      insert(key);
    } else if(command[0] == 'f') {
      cin >> key;
      if(find(key) != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if(command[0] == 'd') {
      cin >> key;
      delete_node(key);
    } else {
      print();
    }
  }
}

// https://programgenjin.hatenablog.com/entry/2019/03/01/083653