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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
ll max_upper = 1000000000000000000;

int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  bool flag_zero = false;
  rep(i,N) {
    cin >> vec[i];
    if(vec[i] == 0) flag_zero = true;
  }
  if(flag_zero) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  rep(i,N) {
    ll tmp = vec[i];
    if((ans*vec[i] > max_upper) || max_upper/ans < vec[i]) {
      ans = -1;
      break;
    }
    ans = ans*vec[i];
  }
  cout << ans << endl;
  return 0;
}

// オーバーフローのとり方が甘かった...ans > max && max/ans < vec[i]も取ればいける
// 他の対策としてint128, pythonなどがある