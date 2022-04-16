#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using P2 = pair<double,double>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;

int main() {
  int N, K; cin >> N >> K;
  if(N == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  map<P2, int>mp;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      int x1 = vec[i].first;
      int y1 = vec[i].second;
      int x2 = vec[j].first;
      int y2 = vec[j].second;
      if(x1 == x2) {
        double kata = 1000000000.0;
        double seten = x1;
        mp[P(kata, seten)]++;
        continue;
      }
      double kata = (y2-y1)/(x2-x1);
      double seten = -x1*(y2-y1)/(x2-x1) + y1;
      mp[P(kata, seten)]++;
    }
  }
  int ans = 0;
  auto itr = mp.begin();
  while(itr != mp.end()) {
    if((itr->second)+1 >= K) {
      // cout << "i:" << itr->first.first << endl;
      ans++;
    }
    itr++;
  }
  cout << ans << endl;
  return 0;
}