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
  // 木の直径を求めて、答えは直径+1
  int N; cin >> N;
  Graph G(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> dist(N, -1);
  queue<int> que;
  dist[0] = 0;  // とりあえず0から探索
  que.push(0);
  int next_point;  // 0から一番遠いい距離にあり、次の開始点になる
  int max_val = 0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();

    for(int nv : G[v]) {
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
      if(dist[nv] > max_val) {
        max_val = dist[nv];
        next_point = nv;
      }
    }
  }
  fill(ALL(dist), -1);
  dist[next_point] = 0;
  que.push(next_point);
  max_val = 0;  // 木の直径となる
  while(!que.empty()) {
    int v = que.front();
    que.pop();

    for(int nv : G[v]) {
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
      if(dist[nv] > max_val) max_val = dist[nv];
    }
  }
  int ans = max_val + 1;
  cout << ans << endl;
}