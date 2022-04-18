#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;

bool used[310][310];
int main() {
  int N, K; cin >> N >> K;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  if(K == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  int ans = 0;
  // i,j番目を使った直線を考えて、k番目もそこを通るかを見ていく
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      if(used[i][j]) continue;
      int cnt = 2;
      for(int k = j+1; k < N; k++) {
        // if(used[i][k] || used[j][k]) continue;
        ll x1 = vec[i].first, y1 = vec[i].second;
        ll x2 = vec[j].first, y2 = vec[j].second;
        ll x = vec[k].first, y = vec[k].second;
        if((ll)(x2-x1)*(y-y1)==(ll)(y2-y1)*(x-x1)) {
          cnt++;
          used[i][k] = true;
          used[j][k] = true;
        }
      }
      if(cnt >= K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}