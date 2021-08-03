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
  ll N; cin >> N;
  if(N == 1) {
    cout << 0 << endl;
    return 0;
  }
  // 10^N - (9^N + 9^N - 8^N) = 10^N + 8^N - 9^N - 9^N
  ll before_ten = 1;
  ll before_nine = 1;
  ll before_eight = 1;
  rep(i,N) {
    before_ten = before_ten*10;
    before_nine = before_nine*9;
    before_eight = before_eight*8;
    if(before_ten >= MOD && before_nine >= MOD && before_eight >= MOD) {
      before_ten = before_ten % MOD;
      before_nine = before_nine % MOD;
      before_eight = before_eight % MOD;
    }
  }
  ll ans = (before_ten - before_nine + before_eight - before_nine) % MOD;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}

// それぞれのMODをとっても問題ない