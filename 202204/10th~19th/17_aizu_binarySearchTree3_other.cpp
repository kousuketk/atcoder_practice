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
  newNode->left = nil;
  newNode->right = nil;
  newNode->key = key;
  Node *now = root;
  Node *before = nil;
  while(now != nil) {
    before = now;
    if(now->key >= key) now = now->left;
    else now = now->right;
  }
  if(now == root) root = newNode;
  else if(before->key >= key) before->left = newNode;
  else before->right = newNode;
  newNode->par = before;
}

bool find(int key, Node *x = root) {
  if(x == nil) return false;
  if(x->key == key) return true;
  if(x->key >= key) return find(key, x->left);
  else return find(key, x->right);
}

void deleteNode(int key, Node *x = root) {
  if(x->key == key) {
    if(x->left == nil && x->right == nil) {
      // 1. xが子を持たない時
      Node *par = x->par;
      if(par->key >= key) par->left = nil;
      else par->right = nil;
      // delete x;
    } else if(x->left == nil || x->right == nil) {
      // 2. xが1つの子を持つ時(親の子, 子の親を設定)
      Node *par = x->par;
      Node *chil;
      if(x->left != nil) chil = x->left;
      else chil = x->right;
      if(par->key >= key) par->left = chil;
      else par->right = chil;
      chil->par = par;
      // delete x;
    } else {
      // 3. xが2つの子を持つ時(次節点とは、右の木の一番小さい要素)
      Node *nextNode = x->right;
      while(nextNode->left != nil) nextNode = nextNode->left;
      deleteNode(nextNode->key, nextNode);
      x->key = nextNode->key;
    }
  } else {
    if(x->key >= key) deleteNode(key, x->left);
    else deleteNode(key, x->right);
  }
}

void print1(Node *x = root) {
  if(x == nil) return;
  // 左
  print1(x->left);
  // 自分
  cout << " " << x->key;
  // 右
  print1(x->right);
}

void print2(Node *x = root) {
  if(x == nil) return;
  // 自分
  cout << " " << x->key;
  // 左
  print2(x->left);
  // 右
  print2(x->right);
}

int main() {
  int N; cin >> N;
  rep(_,N) {
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
  return 0;
}