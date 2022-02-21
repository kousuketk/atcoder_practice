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
vector<P> ans;  // left, right
void dfs(int v, int& val, int par) {
  bool reef = true;
  for(int nv : G[v]) {
    if(nv == par) continue;
    reef = false;
    dfs(nv, val, v);
  }
  // 葉のとき
  if(reef) {
    ans[v] = P(val, val);
    val++;
    return;
  }
  // 葉じゃないときは、子要素を見てmin, maxを取る
  ans[v].first = INF, ans[v].second = -1;
  for(int nv : G[v]) {
    if(nv == par) continue;
    ans[v].first = min(ans[v].first, ans[nv].first);
    ans[v].second = max(ans[v].second, ans[nv].second);
  }
  return;
}

int main() {
  int N; cin >> N;
  G.resize(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ans.resize(N);
  int val = 1;
  dfs(0, val, -1);
  rep(i,N) cout << ans[i].first << " " << ans[i].second << endl;
}