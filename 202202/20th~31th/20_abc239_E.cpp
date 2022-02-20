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

int maxK = 20;
vector<vector<int>> vec_val; // 頂点i番目において、大きい値から並べる(maxK個まで)
vector<int> vec_x;

void dfs(Graph &G, int v = 0, int p = -1) {
  vec_val[v].push_back(vec_x[v]);  // 頂点自身の値を入れる
  for(int nv : G[v]) {
    if(nv == p) continue;
    dfs(G, nv, v);
  }
  // 子要素を入れる
  for(int nv : G[v]) {
    if(nv == p) continue;
    for(int val : vec_val[nv]) vec_val[v].push_back(val);
  }
  sort(ALL(vec_val[v]), greater());
  // もしvec_valの大きさがmaxKより大きかったら減らす
  if((int)vec_val[v].size() > maxK) vec_val[v].erase(vec_val[v].begin()+maxK, vec_val[v].end());
  return;
}

int main() {
  int N, Q; cin >> N >> Q;
  vec_val.resize(N);
  vec_x.resize(N);
  rep(i,N) cin >> vec_x[i];
  Graph G(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(G);
  rep(i,Q) {
    int v, k; cin >> v >> k;
    v--, k--;
    cout << vec_val[v][k] << endl;
  }
  return 0;
}

// 計算量O(NKlongK)