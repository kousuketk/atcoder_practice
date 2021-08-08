#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<priority_queue<int, vector<int>, greater<int>>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

Graph G;

void dfs(int v, int p) {
  cout << (v+1) << " ";
  bool flag = false;
  while(!G[v].empty()) {
    int nv = G[v].top(); G[v].pop();
    if(nv == p) continue;
    flag = true;
    dfs(nv, v);
    cout << (v+1) << " ";
  }
  // if(flag) cout << (v+1) << " ";
}

int main() {
  int N; cin >> N;
  G.resize(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push(b);
    G[b].push(a);
  }
  dfs(0, 0);
  return 0;
}