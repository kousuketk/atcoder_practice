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
  vector<int> nug(V);
  rep(i,E) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    nug[b]++;
  }
  queue<int> que;
  rep(i,V) if(nug[i] == 0) que.push(i);
  vector<int> ans;
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    ans.push_back(v);
    for(int nv : G[v]) {
      nug[nv]--;
      if(nug[nv] == 0) que.push(nv);
    }
  }
  rep(i,V) cout << ans[i] << endl;
  return 0;
}