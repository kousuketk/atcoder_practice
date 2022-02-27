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

Graph G;
int dp[100100];  // 頂点iからの最長パス数

int dfs(int v) {
  if(dp[v] != -1) return dp[v];
  int res = 0;
  for(int nv : G[v]) {
    res = max(res, dfs(nv)+1);
  }
  return dp[v] = res;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  rep(i,100100) dp[i] = -1;
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
  }
  int ans = 0;
  rep(i,N) {
    if(dp[i] != -1) continue;
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
}