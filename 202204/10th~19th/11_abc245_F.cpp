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

// 逆辺に張って、シンクを消していく→残った頂点が答え
int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  vector<int> deg(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[v].push_back(u);
    deg[u]++;
  }
  queue<int> que;
  rep(i,N) if(deg[i] == 0) que.push(i);
  while(!que.empty()) {
    int v = que.front(); que.pop();
    for(int nv : G[v]) {
      deg[nv]--;
      if(deg[nv] == 0) que.push(nv);
    }
  }
  int ans = 0;
  rep(i,N) if(deg[i] != 0) ans++;
  cout << ans << endl;
  return 0;
}