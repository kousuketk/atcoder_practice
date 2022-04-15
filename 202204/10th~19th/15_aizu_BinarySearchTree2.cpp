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

void insert(int val) {
  Node *x = new Node();
  x->key = val;
  x->left = nil;
  x->right = nil;
  Node *now = root;
  Node *before = nil;
  while(now != nil) {
    before = now;
    if(now->key >= x->key) now = now->left;
    else now = now->right;
  }
  x->par = before;
  if(now == root) root = x;
  else if(before->key >= x->key) before->left = x;
  else before->right = x;
}

bool find(int key, Node *x = root) {
  if(x == nil) return false;
  if(x->key == key) return true;
  if(x->key > key) return find(key, x->left);
  else return find(key, x->right);
}

void print1(Node *x = root) {
  if(x == nil) return;
  // 左の子
  print1(x->left);
  // 出力
  cout << " " << x->key;
  // 右の子
  print1(x->right);
}

void print2(Node *x = root) {
  if(x == nil) return;
  // 出力
  cout << " " << x->key;
  // 左の子
  print2(x->left);
  // 右の子
  print2(x->right);
}

int main() {
  int N; cin >> N;
  rep(i,N) {
    string s; cin >> s;
    if(s == "insert") {
      int val; cin >> val;
      insert(val);
    } else if(s == "find") {
      int val; cin >> val;
      bool ans = find(val);
      if(ans) cout << "yes" << endl;
      else cout << "no" << endl;
    } else {
      print1();
      cout << endl;
      print2();
      cout << endl;
    }
  }
  return 0;
}