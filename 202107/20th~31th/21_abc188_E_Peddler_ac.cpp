#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 2001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll dp[200100];

int main() {
  int N, M; cin >> N >> M;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  vector<P> side(M);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--; y--;
    side[i].first = x;
    side[i].second = y;
  }
  sort(side.begin(), side.end());
  rep(i,200100) dp[i] = INF;
  rep(i,M) dp[side[i].second] = min({dp[side[i].first], vec[side[i].first], dp[side[i].second]});
  ll ans = -INF;
  rep(i,N) ans = max(ans, vec[i]-dp[i]);
  cout << ans << endl;
}

// INFが足りなかった→