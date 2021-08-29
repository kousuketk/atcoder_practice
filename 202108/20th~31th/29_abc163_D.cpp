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
  int N, K; cin >> N >> K;
  vector<ll> S(N+1);
  rep(i,N) S[i+1] = S[i] + i+1;
  ll ans = 0;
  for(int i = K; i <= N+1; i++) {
    ll min_val = S[i-1];
    ll max_val;
    if(N-i >= 0) max_val = S[N] - S[N-i];
    else max_val = S[N];
    ans = (ans + (max_val - min_val) + 1) % MOD;
  }
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}