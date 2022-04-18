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

bool calc(ll a, ll b, ll N) {
  return (a*a*a + a*a*b + a*b*b + b*b*b) >= N;
}

// a<=10^6, b<=10^6で、aを全探索, bを2分探索していく
int main() {
  ll N; cin >> N;
  ll ans = INF;
  for(ll a = 0; a <= 1000000; a++) {
    ll ng = -1;
    ll ok = 1000000;
    while(ng+1 < ok) {
      ll mid = (ng+ok)/2;
      if(calc(a, mid, N)) ok = mid;
      else ng = mid;
    }
    ans = min(ans, a*a*a + a*a*ok + a*ok*ok + ok*ok*ok);
  }
  cout << ans << endl;
  return 0;
}