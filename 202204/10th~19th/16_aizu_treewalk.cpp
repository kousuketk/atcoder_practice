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
  int par, left, right;
};

vector<Node> vec(30);

int find_root() {
  rep(i,30) if(vec[i].par == -1) return i;
  return INF;
}

void preorder(int id) {
  if(id == -1) return;
  cout << " " << id;
  preorder(vec[id].left);
  preorder(vec[id].right);
}

void inorder(int id) {
  if(id == -1) return;
  inorder(vec[id].left);
  cout << " " << id;
  inorder(vec[id].right);
}

void postorder(int id) {
  if(id == -1) return;
  postorder(vec[id].left);
  postorder(vec[id].right);
  cout << " " << id;
}

int main() {
  int N; cin >> N;
  rep(i,30) vec[i].par = -1;  // 最初から見ていって親が-1だったらroot
  rep(i,N) {
    int id, l, r; cin >> id >> l >> r;
    vec[id].left = l;
    vec[id].right = r;
    vec[l].par = id;
    vec[r].par = id;
  }
  int root = find_root();
  cout << "Preorder" << endl;
  preorder(root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(root);
  cout << endl;
}