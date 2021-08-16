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
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> look(N, -1);
  look[0] = 0;
  que.push({0,0});
  while(!que.empty()) {
    P tmp = que.top(); que.pop();
    int cost = tmp.first;
    int v = tmp.second;
    for(int nv : G[v]) {
      if(look[nv] != -1) continue;
      look[nv] = v;
      que.emplace(cost+1, nv);
    }
  }
  cout << "Yes" << endl;
  rep(i,N-1) cout << look[i+1]+1 << endl;
  return 0;
}
// →普通にbfsでいい