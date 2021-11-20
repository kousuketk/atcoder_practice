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
  vector<vector<ll>> G(N, vector<ll>(M));
  rep(i,N) {
    rep(j,M) {
      ll b; cin >> b;
      b--;
      G[i][j] = b;
    }
  }
  ll start = G[0][0];
  int h = start/7;
  // int w = start - (h*7);
  bool flag = true;
  rep(i,N) {
    rep(j,M) {
      if(!(G[i][j] == (start + i*7 + j))) flag = false;
      if(G[i][j] >= (h+i+1)*7) flag = false;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}