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
vector<int> used;
bool dfs(int v, int cur = 1) {
  used[v] = cur;
  for(int next_v : G[v]) {
    if(used[next_v] != -1) {  // 既に探索済みの頂点の場合は異なる色であるか判定する
      if(used[next_v] == cur) return false;
    } else {  // はじめて探索するとき
      bool flag = dfs(next_v, cur*(-1));
      if(!flag) return false;
    }
  }
  return true;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  used.assign(N, 0);
  rep(i,M) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool ans = true;
  rep(i,N) {  // 連結グラフかわからないときは、全ての頂点から始める
    if(used[i] != 0) continue;
    if(!dfs(i)) ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}