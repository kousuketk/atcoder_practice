#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<P>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
vector<bool> seen;
vector<int> color;  // 偶数：0, 奇数：1
Graph G;
void rec(int i, int mod) {
  seen[i] = true;
  for(P tmp : G[i]) {
    int nv = tmp.first;
    int w = tmp.second;
    int mmod = (mod + w) % 2;
    color[nv] = mmod;
    if(seen[nv]) continue;
    rec(nv, mmod);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  seen.assign(N, false);
  color.assign(N, -1);
  rep(i,N-1) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    G[u].push_back(P(v, w));
    G[v].push_back(P(u, w));
  }
  color[0] = 0;
  rec(0, 0);
  rep(i,N) cout << color[i] << endl;
}