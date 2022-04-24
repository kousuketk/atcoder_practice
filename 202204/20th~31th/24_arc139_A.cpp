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

int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  ll val = pow((ll)2, (ll)vec[0]);
  // cout << val << endl;
  for(int i = 1; i < N; i++) {
    ll now = pow((ll)2, vec[i]);
    if(vec[i] > vec[i-1]) {
      if(now > val) {
        val = now;
      } else {
        // 最上位桁のみ残して、vec[i]だけ1にする. 最上位桁とvec[i]が同じ時は処理追加
        bitset<60> bs(val);
        for(int k = 0; k < vec[i]; k++) bs.reset(k);
        val = bs.to_ullong();
        // cout << val << endl;
        if(bs.test(vec[i])) val += pow((ll)2, (vec[i]+1));
        else val += pow((ll)2, vec[i]);
      }
    } else if(vec[i] == vec[i-1]) {
      val += pow((ll)2, (vec[i]+1));
    } else {
      val = val + pow((ll)2, vec[i]);
    }
    // cout << val << endl;
  }
  cout << val << endl;
  return 0;
}