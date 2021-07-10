#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

vector<int> depth;

void dfs(const Graph &G, int v, int p, int d) {
  depth[v] = d;
  for (auto nv : G[v]) {
    if (nv == p) continue; // nv が親 p だったらダメ
    dfs(G, nv, v, d+1);
  }
}


int main() {
  int N, Q; cin >> N >> Q;

  Graph G(N);
  for (int i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // 探索
  int root = 0; // 仮に頂点 0 を根とする
  depth.assign(N, 0);
  dfs(G, root, -1, 0);

  // for (int v = 0; v < N; ++v) {
  //   cout << v << ": depth = " << depth[v] << endl;
  // }
  for(int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    if(abs(depth[a]-depth[b]) % 2 == 0) cout << "Town" << endl;
    else cout << "Road" << endl;
  }
}