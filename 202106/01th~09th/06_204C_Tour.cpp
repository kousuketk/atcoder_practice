#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, M; cin >> N >> M;

  Graph G(N);
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
  }

  ll ans = N;
  for(int i = 0; i < N; i++) {
    vector<int> dist(N, -1);
    queue<int> que;
    dist[i] = 0;
    que.push(i);

    while(!que.empty()) {
      int v = que.front();
      que.pop();
      for(int nv : G[v]) {
        if(dist[nv] != -1) continue;
        
        ans++;
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }
  cout << ans << endl;
  return 0;
}