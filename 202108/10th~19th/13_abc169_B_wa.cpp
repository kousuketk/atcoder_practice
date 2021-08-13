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
    int tmp_digit = -1;
    while(tmp!=0) {
      tmp /= 10;
      tmp_digit++;
    }
    ll tmp_ans = ans;
    int tmp_ans_digit = -1;
    while(tmp_ans!=0) {
      tmp_ans /= 10;
      tmp_ans_digit++;
    }
    ans = ans*vec[i];
    if((ans > 1000000000000000000) || (ans < 0) || (tmp_digit+tmp_ans_digit > 18)) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

// オーバーフローのとり方が甘かった...ans > max && max/ans > vec[i]も取ればいける
// 他の対策としてint128, pythonなどがある