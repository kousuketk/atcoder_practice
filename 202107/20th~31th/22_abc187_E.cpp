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

vector<int> depth;
Graph G;
vector<ll> S;

void dfs(int v, int par, int d) {
  depth[v] = d;
  for(int next_v : G[v]) {
    if(next_v == par) continue;
    dfs(next_v, v, d+1);
  }
}

void dfs_imos(int v, int par) {
  if(v != par) S[v] += S[par];
  for(int next_v : G[v]) {
    if(next_v == par) continue;
    dfs_imos(next_v, v);
  }
}

int main() {
  int N; cin >> N;
  vector<P> vec(N);
  G.resize(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b); G[b].push_back(a);
    vec[i].first = a; vec[i].second = b;
  }
  // 頂点0を根とした根付き木を考える
  depth.resize(N);
  int root = 0;
  dfs(root, root, 0);
  // クエリ処理→O(Q)
  S.assign(N, 0);
  int Q; cin >> Q;
  rep(i,Q) {
    int t, e, x; cin >> t >> e >> x;
    e--;
    if(t == 1) {
      // vec[e].first→vec[e].second
      if(depth[vec[e].first] > depth[vec[e].second]) {
        S[vec[e].first] += x;
      } else {
        S[root] += x;
        S[vec[e].second] -= x;
      }
    } else {
      // vec[e].second→vec[e].first
      if(depth[vec[e].second] > depth[vec[e].first]) {
        S[vec[e].second] += x;
      } else {
        S[root] += x;
        S[vec[e].first] -= x;
      }
    }
  }
  // // 累積和の処理→O(N)
  // 根付き木でrootから見ていく
  // rep(i,N) cout << S[i] << endl;
  dfs_imos(root, root);
  rep(i,N) cout << S[i] << endl;
}