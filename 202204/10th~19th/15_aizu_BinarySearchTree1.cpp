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
  Node(int val) {
    key = val;
  }
};
Node *root, *NIL;

void print1(Node *x) {
  if(x == NIL) return;
  // 左の子へ
  print1(x->left);
  // 自身の出力
  cout << " " << x->key;
  // 右の子へ
  print1(x->right);
}

void print2(Node *x) {
  if(x == NIL) return;
  // 自身の出力
  cout << " " << x->key;
  // 左の子へ
  print2(x->left);
  // 右の子へ
  print2(x->right);
}

void insert(int val) {
  Node *x, *now, *before;
  now = root;
  before = NIL;
  x = new Node(val);
  x->left = NIL;
  x->right = NIL;
  while(now != NIL) {
    before = now;
    if(now->key >= x->key) now = now->left;
    else now = now->right;
  }
  x->par = before;
  if(now == root) root = x;
  else if(before->key >= x->key) before->left = x;
  else before->right = x;
}

int main() {
  int N; cin >> N;
  rep(i,N) {
    string s; cin >> s;
    if(s == "insert") {
      int val; cin >> val;
      insert(val);
    } else {
      print1(root);
      cout << endl;
      print2(root);
      cout << endl;
    }
  }
}