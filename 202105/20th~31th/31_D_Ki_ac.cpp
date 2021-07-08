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

Graph G;
vector<int> ans;
vector<bool> seen;

void dfs(int v) {
  seen[v] = true;
  for(int next_v : G[v]) {
    if (seen[next_v]) continue;
    ans[next_v] += ans[v];
    dfs(next_v);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  G.resize(N);
  ans.resize(N);
  seen.assign(N, false);
  for(int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0);
  printVec(ans);
  return 0;
}