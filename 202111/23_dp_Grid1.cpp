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

int H, W;
vector<string> math;
ll dp[1010][1010];

ll rec(int h, int w) {
  if(dp[h][w] != -1) return dp[h][w];
  if(h == H-1 && w == W-2) return dp[h][w] = 1;
  if(w == W-1 && h == H-2) return dp[h][w] = 1;

  ll res = 0;
  if(math[h+1][w] == '.' && h < H-1) res = (res + rec(h+1, w)) % MOD;
  if(math[h][w+1] == '.' && w < W-1) res = (res + rec(h, w+1)) % MOD;
  
  return dp[h][w] = res;
}

int main() {
  cin >> H >> W;
  math.resize(H);
  rep(i,H) cin >> math[i];
  rep(i,1010) rep(j,1010) dp[i][j] = -1;
  ll ans = rec(0,0);
  cout << ans << endl;
}