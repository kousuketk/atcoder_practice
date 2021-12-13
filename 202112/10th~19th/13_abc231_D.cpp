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

int N, M;
Graph G;
vector<bool> dist;

void dfs(int v, int par) {
  if(dist[v]) {
    cout << "No" << endl;
    exit(0);
  };
  dist[v] = true;
  for(int nv : G[v]) {
    if(nv != par) dfs(nv, v);
  }
}

int main() {
  // グラフを作って、根以外の節で1つしか子を持ってはいけない
  // サイクルになってはいけない
  cin >> N >> M;
  G.resize(N);
  map<int, int> mp;
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    mp[a]++, mp[b]++;
    if(mp[a] > 2 || mp[b] > 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  dist.resize(N);
  rep(i,N) dist[i] = false;
  rep(i,N) {
    if(!dist[i]) dfs(i, -1);
  }
  cout << "Yes" << endl;
  return 0;
}