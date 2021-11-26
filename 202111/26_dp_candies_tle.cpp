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

ll dp[110][100100];
int main() {
  int N, K; cin >> N >> K;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  rep(i,N) {
    if(i == 0) {
      int cnt = min(vec[i], (ll)K);
      rep(k,cnt+1) {
        dp[i][k] = 1;
      }
      continue;
    }
    rep(j,K+1) {
      int cnt = min(vec[i], (ll)(K-j));  // すでにj個配っているので、今回のi番目で配れる数
      rep(k,cnt+1) {
        dp[i][j+k] = (dp[i][j+k] + dp[i-1][j]) % MOD;
      }
    }
  }
  ll ans = dp[N-1][K];
  cout << ans << endl;
}

// →TLEしたから、累積和を使おう