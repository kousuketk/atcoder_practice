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

int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  vector<ll> S(N);
  vector<ll> S_max(N);
  rep(i,N) cin >> vec[i];
  rep(i,N) {
    if(i == 0) {
      S[i] = vec[i];
      S_max[i] = max((ll)0, vec[i]);
    } else {
      S[i] = S[i-1] + vec[i];
      ll tmp = S[i-1] + vec[i];
      S_max[i] = max(S_max[i-1], tmp);
    }
  }
  ll ans = -INF;
  ll now = 0;
  rep(i,N) {
    ll x = now + S_max[i];
    now += S[i];
    ans = max(ans, x);
  }
  cout << ans << endl;
}