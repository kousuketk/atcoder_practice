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
  int N, M; cin >> N >> M;
  Graph G(N);
  vector<int> used(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool ans = true;
  rep(i,N) {  // 連結グラフとは限らないときはすべての頂点を見る
    if(used[i] != 0) continue;
    queue<P> que;  // 別にpairでqueに入れなくても、used[v], used[next_v]の値で判定できる
    used[i] = 1;
    que.push({i, 1});
    while(!que.empty()) {
      P tmp = que.front();
      que.pop();
      int v = tmp.first;
      int cur = tmp.second;
      used[v] = cur;
      for(int next_v : G[v]) {
        if(used[next_v] != 0) {  // 既に探索済みのとき
          if(used[next_v] == cur) ans = false;
        } else {
          que.push({next_v, cur*(-1)});
        }
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}

// 幅優先探索で2部グラフ判定