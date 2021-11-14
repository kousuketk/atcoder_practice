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
const ll MOD = 998244353;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
 
ll dp[3010][3010];
int main() {
  int N; cin >> N;
  vector<int> vec_a(N);
  vector<int> vec_b(N);
  rep(i,N) cin >> vec_a[i];
  rep(i,N) cin >> vec_b[i];
  rep(i,N) {
    int a = vec_a[i];
    int b = vec_b[i];
    if(i == 0) {
      while(a != b+1) {
        dp[i][a] = 1;
        a++;
      }
      continue;
    }
    int before_a = vec_a[i-1];
    int before_b = vec_b[i-1];
    ll sum = 0;
    for(int j = before_a; j <= before_b; j++) {
      sum = (sum + dp[i-1][j]) % MOD;
      if(j >= a) dp[i][j] = sum;
    }
    if(before_b < a) {
      for(int j = a; j <= b; j++) {
        sum = (sum + dp[i-1][j]) % MOD;
        dp[i][j] = sum; 
      }
    } else {
      for(int j = before_b+1; j <= b; j++) {
        sum = (sum + dp[i-1][j]) % MOD;
        dp[i][j] = sum; 
      }
    }
  }
  ll ans = 0;
  rep(j,3010) ans = (ans + dp[N-1][j]) % MOD;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}