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

ll dp[20];
int main() {
  ll N; cin >> N;
  dp[1] = 45;
  for(int i = 2; i < 18; i++) {
    ll val = ((ll)pow(10, i) - (ll)pow(10, (i-1))) % MOD;
    dp[i] = val*(val+1)/2 % MOD;
  }
  int keta = 0;
  ll tmp = N;
  while (tmp > 0) {
    tmp = tmp/10;
    keta++;
  }
  ll ans = 0;
  rep(i,keta) ans = (ans + dp[i]) % MOD;
  ll a = (N - (ll)pow(10, (keta-1)) + 1) % MOD;
  ans = (ans + (a*(a+1)/2) % MOD) % MOD;
  cout << ans << endl;
}