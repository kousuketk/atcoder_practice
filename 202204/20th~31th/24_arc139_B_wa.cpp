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

// コスパが良いものを基本選び、端数は相談
int main() {
  int T; cin >> T;
  vector<int> vec_ans;
  rep(_,T) {
    ll n, a, b, x, y, z; cin >> n >> a >> b >> x >> y >> z;
    ll plus = 0, cost = 0;
    double one = x;
    double two = (double)y/(double)a;
    double three = (double)z/(double)b;
    if(one <= two && one <= three) plus = 1, cost = x;  // 小さいほうがコスパがいい
    else if(two <= three) plus = a, cost = y;
    else plus = b, cost = z;
    // cout << "plus:" << plus << " cost:" << cost << endl;
    // plusで増やせるだけ増やして、costをかける. 残ったものは3つの内最も良いもの
    ll cnt = n / plus;
    ll ans = cnt * cost;
    n = n % plus;
    // 残りのnについて最も良いもの(切り上げで計算), ぴったりにするから最適なものを選んでいく
    while(n != 0) {
      plus = 1;
      cost = x;
      int flag = 1;
      if(n - a >= 0 && two <= one) plus = a, cost = y, flag = 2;
      if(n - b >= 0) {
        if(flag == 1 && three <= one) plus = b, cost = z;
        if(flag == 2 && three <= two) plus = b, cost = z;
      }
      cnt = n / plus;
      n = n % plus;
      ans += cnt*cost;
    }
    vec_ans.push_back(ans);
  }
  for(ll a : vec_ans) cout << a << endl;
  return 0;
}