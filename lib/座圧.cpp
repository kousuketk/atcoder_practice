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

vector<ll> compress(vector<int> &V1, vector<int> &V2) {
  vector<ll> vals;
  int N = (int)V1.size();
  for(int i = 0; i < N; i++) {
    for(int d = 0; d <= 1; d++) {
      int val1 = V1[i] + d;
      int val2 = V2[i] + d;
      vals.push_back(val1);
      vals.push_back(val2);
    }
  }
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  for(int i = 0; i < N; i++) {
    V1[i] = lower_bound(ALL(vals), V1[i]) - vals.begin();
    V2[i] = lower_bound(ALL(vals), V2[i]) - vals.begin();
  }
  return vals;
}

// 座圧したあとに、imosで塗りつぶして面積を求める
int main() {
  int N; cin >> N;
  vector<int> X1(N), X2(N), Y1(N), Y2(N);
  rep(i,N) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  // 座圧
  vector<ll> X = compress(X1, X2);
  vector<ll> Y = compress(Y1, Y2);
  // imos法で塗りつぶし
  int w = (int)X.size();
  int h = (int)Y.size();
  vector<vector<int>> G(w, vector<int>(h));
  for(int i = 0; i < N; i++) {
    G[X1[i]][Y1[i]]++;
    G[X2[i]][Y2[i]]++;
    G[X1[i]][Y2[i]]--;
    G[X2[i]][Y1[i]]--;
  }
  for(int x = 1; x < w; x++) {  // x軸方向に更新していく
    for(int y = 0; y < h; y++) {
      G[x][y] += G[x-1][y];
    }
  }
  for(int x = 0; x < w; x++) {
    for(int y = 1; y < h; y++) {
      G[x][y] += G[x][y-1];
    }
  }
  ll ans = 0;  // 塗りつぶした面積を求めるために、復元しながら求めて行く
  for(int x = 0; x < w-1; x++) {
    for(int y = 0; y < h-1; y++) {
      if(G[x][y]) ans += (X[x+1] - X[x]) * (Y[y+1] - Y[y]);
    }
  }
  cout << ans << endl;
  return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A&lang=ja