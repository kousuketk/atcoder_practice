#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
ll dist[13][13];
ll dp[(1<<14)][13];
ll rec(int bit, int i) {
  if(dp[bit][i] != -1) return dp[bit][i];
  if(bit == (1<<i)) return dist[0][i];  // その頂点しか立ってなかったら、0からのスタート
  int prev_bit = bit & ~(1<<i);
  ll res = INF;
  for(int j = 0; j < N; j++) {
    if(!(prev_bit & (1<<j))) continue;  // prev_bitになかったら次
    res = min(res, rec(prev_bit, j) + dist[j][i]);
  }
  return dp[bit][i] = res;
} 

int main() {
  cin >> N;
  rep(i,N) rep(j,N) cin >> dist[i][j];
  rep(i,(1<<14)) rep(j,13) dp[i][j] = -1;
  ll ans = rec((1<<N)-1, 0);
  cout << ans << endl;
  return 0;
}