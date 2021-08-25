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
const int MOD = 998244353;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int dp[1010][(1<<10)][10];

int main() {
  int N; cin >> N;
  string s; cin >> s;
  rep(i,N) {
    int now = s[i] - 'A';
    rep(bit,1<<N) {
      rep(j,10) {
        if(now == j) {
          dp[i+1][bit][j] = (dp[i+1][bit][j]+dp[i][bit][j]) % MOD;
        } else {
          // 最後と違うが、今までやってなかった時(bit集合にない時)
          if(!(bit & (1<<now))) { // bit集合になかったら選べる
            int nb = bit & (1<<j);
            dp[i+1][nb][now] = (dp[i+1][nb][j]+dp[i][bit][j]) % MOD;
          }
        }
      }
    }
    dp[i][(1<<now)][now] = (dp[i][(1<<now)][now]+1) % MOD;
  }
  int ans = 0;
  rep(bit,1<<N) {
    rep(j,10) {
      ans = (ans+dp[N][bit][j])%MOD;
    }
  }
  cout << ans-1 << endl;
}