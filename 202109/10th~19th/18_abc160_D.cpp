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
  int N, X, Y; cin >> N >> X >> Y;
  Graph G(N);
  rep(i,N-1) {
    G[i].push_back(i+1);
    G[i+1].push_back(i);
  }
  X--, Y--;
  G[X].push_back(Y);
  G[Y].push_back(X);
  vector<int> ans(N-1);
  rep(i,N-1) { // 頂点iからi+1以上の頂点に対しての最短距離を求めていく
    vector<int> dist(N, -1);
    queue<int> que;
    dist[i] = 0;
    que.push(i);
    while(!que.empty()) {
      int v = que.front();
      que.pop();

      for(int nv : G[v]) {
        if(dist[nv] != -1) continue;
        dist[nv] = dist[v]+1;
        que.push(nv);
      }
    }
    for(int j = i+1; j < N; j++) {
      int dis = dist[j];
      ans[dis-1]++;
    }
  }
  rep(i,N-1) cout << ans[i] << endl;
  return 0;
}