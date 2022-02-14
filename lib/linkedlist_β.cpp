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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
struct Node {
  Node *prev, *next;
  int key;
  Node(int key) : prev(NULL), next(NULL), key(key) {}
};

int main() {
  int N, Q; cin >> N >> Q;
  vector<Node*> vec(N);
  Node* nil;
  nil = new Node(-1);
  rep(i,N) {
    Node* node = new Node(i);
    node->prev = nil;
    node->next = nil;
    vec[i] = node;
  }
  rep(i,Q) {
    int a; cin >> a;
    if(a == 1) {
      int x, y; cin >> x >> y;
      x--, y--;
      vec[x]->next = vec[y];
      vec[y]->prev = vec[x];
    } else if(a == 2) {
      int x, y; cin >> x >> y;
      x--, y--;
      vec[x]->next = nil;
      vec[y]->prev = nil;
    } else {
      int x; cin >> x;
      x--;
      Node* cur = vec[x];
      while(cur->prev != nil) {
        cur = cur->prev;
      }
      vector<int> ans;
      while(cur != nil) {
        ans.push_back(cur->key + 1);
        cur = cur->next;
      }
      cout << ans.size() << " ";
      rep(i,(int)ans.size()) cout << ans[i] << " ";
      cout << endl;
    }
  }
  return 0;
}

// https://atcoder.jp/contests/abc225/tasks/abc225_d
// pre_vec, after_vecとかでvectorを使った解法もある