#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include<atcoder/all>
using namespace atcoder;
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

// scc[i]:i番目のグループに属する頂点集合(グループは0からトポロジカルソート順)
int main() {
  int N, M; cin >> N >> M;
  scc_graph g(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    g.add_edge(u, v);
  }
  auto scc = g.scc();
  cout << (int)scc.size() << endl;
  for(auto v : scc) {
    cout << (int)v.size() << " ";
    for(int x : v) cout << x << " ";
    cout << endl;
  }
  return 0;
}

// https://atcoder.github.io/ac-library/production/document_ja/scc.html