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
  Node *left, *right;
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
    } else {
      print1();
      cout << endl;
      print2();
      cout << endl;
    }
  }
}