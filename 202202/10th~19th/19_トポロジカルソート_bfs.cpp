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

int main() {
  int V, E; cin >> V >> E;
  Graph G(V);
  vector<int> deg(V);  // 出次数
  rep(i,E) {
    int a, b; cin >> a >> b;
    G[b].push_back(a);  // 逆に辺を張って、シンクから辿れるようにする
    deg[a]++;  // aからの出次数
  }
  vector<int> ans;
  queue<int> que;
  rep(i,V) {
    // シンクである頂点を入れていく
    if(deg[i] == 0) que.push(i);
  }
  while(!que.empty()) {
    int v = que.front();
    ans.push_back(v);
    que.pop();
    for(int next_v : G[v]) {
      deg[next_v]--;
      if(deg[next_v] == 0) que.push(next_v);
    }
  }
  reverse(ALL(ans));
  rep(i,V) cout << ans[i] << endl;
  return 0;
}

// bfsでトポロジカルソート