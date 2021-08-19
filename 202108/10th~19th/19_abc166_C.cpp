#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<priority_queue<ll>>;
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
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  Graph G(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push(vec[b]);
    G[b].push(vec[a]);
  }
  int ans = 0;
  rep(i,N) {
    // vec[i], G[i].top()の比較
    if(G[i].empty()) {
      ans++;
      continue;
    }
    ll val = vec[i];
    ll que_val = G[i].top();
    if(val > que_val) ans++;
  }
  cout << ans << endl;
}