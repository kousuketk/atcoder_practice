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
      vector<int> tmp;
      tmp.push_back(i);
      tmp.push_back(j);
      used[i][j] = true;
      int cnt = 2;
      for(int k = j+1; k < N; k++) {
        ll x1 = vec[i].first;
        ll y1 = vec[i].second;
        ll x2 = vec[j].first;
        ll y2 = vec[j].second;
        ll x = vec[k].first;
        ll y = vec[k].second;
        if((x2-x1)*(y-y1)==(y2-y1)*(x-x1)) {
          cnt++;
          tmp.push_back(k);
        }
      }
      // 同じ線を引ける頂点に対してtrueにしていく
      for(int ii = 0; ii < (int)tmp.size(); ii++) {
        for(int jj = ii+1; jj < (int)tmp.size(); jj++) {
          used[tmp[ii]][tmp[jj]] = true;
        }
      }
      if(cnt >= K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}