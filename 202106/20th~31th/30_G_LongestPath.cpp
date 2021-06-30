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

int memo[100100];
bool seen[100100];
Graph G;

int rec(int v) {
  if(seen[v]) return memo[v];
  seen[v] = true;
  int res = 0;
  for(int nv : G[v]) {
    res = max(res, rec(nv) + 1);
  }
  return memo[v] = res;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  rep(i,M) {
    int x, y; cin >> x >> y;
    G[x-1].push_back(y-1);
  }
  // 全ての頂点についてrec(i)して、最も大きかったresが答え
  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, rec(i));
  }
  cout << ans << endl;
}