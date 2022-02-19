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
vector<bool> seen, finished;

bool dfs(Graph &G, int v, int p) {
  seen[v] = true;
  for(int nv : G[v]) {
    if(nv == p) continue;
    if(finished[nv]) continue;
    if(seen[nv] && !finished[nv]) return false;
    if(!dfs(G, nv, v)) return false;
  }
  finished[v] = true;
  return true;
}
struct Node {
  Node *prev, *next;
  int key;
  Node(int key) : prev(NULL), next(NULL), key(key) {}
};

int main() {
  int N, M; cin >> N >> M;
  vector<int> vec_d(N);
  rep(i,N) cin >> vec_d[i];
  vector<P> vec(M);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    vec[i] = P(a, b);
  }
  // Diは必ず1が2つで、それ以外は2である
  if(N == 2) {
    if(vec_d[0] != 1 || vec_d[1] != 1) {
      cout << -1 << endl;
      return 0;
    }
  } else {
    int cnt = 0;
    bool flag = true;
    rep(i,N) {
      if(vec_d[i] == 1) cnt++;
      else if(vec_d[i] > 2) flag = false;
    }
    if(cnt != 2) flag = false;
    if(!flag) {
      cout << -1 << endl;
      return 0;
    }
  }
  // サイクルでない
  seen.assign(N, false), finished.assign(N, false);
  Graph G(N);
  rep(i,M) {
    int a = vec[i].first;
    int b = vec[i].second;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool flag_circle = true;
  rep(i,N) {
    if(seen[i]) continue;
    if(!dfs(G, i, -1)) flag_circle = false;
  }
  if(!flag_circle) {
    cout << -1 << endl;
    return 0;
  }
  // 建設可能
  // 連結リストでM個のリストを結んで、前からN頂点見ていって、
  // 前が空いてるnode, 後ろが空いてるnodeが2つ以上になったらそのnodeを連結させる
  Node* nil;
  nil = new Node(-1);
  vector<Node*> vec(N);
  rep(i,N) {
    Node* node = new Node(i);
    node->prev = nil;
    node->next = nil;
    vec[i] = node;
  }
  cout << 1 << endl;
  return 0;
}