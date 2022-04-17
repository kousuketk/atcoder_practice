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
  Node *par, *left, *right;
};

Node *root, *nil;

void insert(int key) {
  Node *newNode = new Node();
  newNode->key = key;
  newNode->left = nil;
  newNode->right = nil;
  Node *now = root;
  Node *before = nil;
  while(now != nil) {
    before = now;
    if(now->key >= key) now = now->left;
    else now = now->right;
  }
  if(before == nil) {
    root = newNode;
  } else {
    if(before->key >= key) before->left = newNode;
    else before->right = newNode;
    newNode->par = before;
  }
}

bool find(int key, Node *x = root) {
  if(x == nil) return false;
  if(x->key == key) return true;
  if(x->key >= key) return find(key, x->left);
  else return find(key, x->right);
}

void deleteNode(int key, Node *x = root) {
  if(x->key == key) {  // 削除対象
    Node *par = x->par;
    if(x->left == nil && x->right == nil) {
      // 1. xが子を持たない時
      if(par->key >= key) par->left = nil;
      else par->right = nil;
    } else if(x->left == nil || x->right == nil) {
      // 2. xがちょうど1つの子を持つ時
      Node *y;
      if(x->left != nil) y = x->left;
      else y = x->right;
      if(par->key >= key) par->left = y;
      else par->right = y;
      y->par = par;
    } else {
      // 3. xが2つの子を持つ時(左をコピーして、左に行く)→右に行って.左にあれば左に行き続ける
      Node *nxt = x->right;
      while(nxt->left != nil) {
        nxt = nxt->left;
      }
      deleteNode(nxt->key, nxt);
      x->key = nxt->key;
      delete nxt;
    }
  } else {
    if(x->key >= key) deleteNode(key, x->left);
    else deleteNode(key, x->right);
  }
}

void print1(Node *x = root) {
  if(x == nil) return;
  print1(x->left);
  cout << " " << x->key;
  print1(x->right);
}

void print2(Node *x = root) {
  if(x == nil) return;
  cout << " " << x->key;
  print2(x->left);
  print2(x->right);
}

int main() {
  int N; cin >> N;
  rep(i,N) {
    string s; cin >> s;
    if(s == "insert") {
      int key; cin >> key;
      insert(key);
    } else if(s == "find") {
      int key; cin >> key;
      bool ans = find(key);
      if(ans) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if(s == "delete") {
      int key; cin >> key;
      deleteNode(key);
    } else {
      print1();
      cout << endl;
      print2();
      cout << endl;
    }
  }
}