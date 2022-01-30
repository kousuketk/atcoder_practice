#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N, M;
vector<ll> vec;
vector<bool> seen;
vector<ll> memo;
Graph G;

ll dfs(int v, ll point) {
  if(memo[v] != -INF) return memo[v] + point;
  ll res = point;
  seen[v] = true;
  for(auto next_v : G[v]) {
    if(seen[next_v]) continue;
    // vとnext_vの計算をする
    if(vec[v] >= vec[next_v]) res = max(res, dfs(next_v, point + vec[v] - vec[next_v]));
    else res = max(res, dfs(next_v, point + 2*(vec[v] - vec[next_v])));
  }
  seen[v] = false;
  return memo[v] = res - point;
}

int main() {
  cin >> N >> M;
  vec.resize(N);
  seen.assign(N, false);
  memo.resize(N, -INF);
  rep(i,N) cin >> vec[i];
  G.resize(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll res = dfs(0, 0);
  ll ans = max(res, (ll)0);
  cout << ans << endl;
  return 0;
}

// ダイクストラを拡張したもので解けるらしい