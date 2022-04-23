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

vector<int> enum_divisors(int N) {
  vector<int> res;
  for (int i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      // if (N/i != i) res.push_back(N/i);
    }
  }
  // 小さい順に並び替える
  // sort(res.begin(), res.end());
  return res;
}

int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(ALL(vec));
  ll ans = 0;
  // 大きいものから見ていって、約数を全列挙して、その２つを2分探索で見つける
  for(int i = N-1; i >= 0; i--) {
    vector<int> tmp = enum_divisors(vec[i]);  // vec[i]の約数を全部出す
    int siz = tmp.size();
    for(int j = 0; j < siz; j++) {
      int a = tmp[j];
      int b = vec[i] / tmp[j];
      // a, bの個数をそれぞれ出す
      ll cnt_a = upper_bound(ALL(vec), a) - lower_bound(ALL(vec), a);
      ll cnt_b = upper_bound(ALL(vec), b) - lower_bound(ALL(vec), b);
      if(a == b) ans += cnt_a*cnt_a;
      else ans += cnt_a*cnt_b*2;
    }
  }
  cout << ans << endl;
}