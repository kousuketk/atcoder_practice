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

int N;
Graph G;
vector<int> dist;

P dfs(int v, int next_ptr, int max_val) {
  for(int nv : G[v]) {
    if(dist[nv] != -1) continue;
    dist[nv] = dist[v] + 1;
    if(dist[nv] > max_val) {
      next_ptr = nv;
      max_val = dist[nv];
    }
    P tmp = dfs(nv, next_ptr, max_val);
    next_ptr = tmp.first;
    max_val = tmp.second;
  }
  return P(next_ptr, max_val);
}

int main() {
  cin >> N;
  G.resize(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dist.resize(N);
  fill(ALL(dist), -1);
  dist[0] = 0;
  P res1 = dfs(0, 0, 0);
  int nv = res1.first;
  fill(ALL(dist), -1);
  dist[nv] = 0;
  P res2 = dfs(nv, 0, 0);
  int ans = res2.second + 1;
  cout << ans << endl;
}