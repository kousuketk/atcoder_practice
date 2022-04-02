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
  ll K, X; cin >> K >> X;
  ll sum = 0;
  vector<ll> vec(N);
  vector<ll> vec_mod(N);
  rep(i,N) {
    ll a; cin >> a;
    vec[i] = a;
    sum += a;
    vec_mod[i] = a % X;
  }
  sort(ALL(vec_mod), greater());
  bool finished = false;
  // 過不足なく少なくできる時
  rep(i,N) {
    ll a = vec[i];
    ll can = a/X;  // 配れる枚数
    if(K-can > 0) {
      K -= can;
      sum -= X*can;
    } else {
      sum -= X*K;
      K = 0;
      finished = true;
      break;
    }
  }
  // それでも終わらなかったらmodを見ていく
  if(!finished) {
    rep(i,N) {
      if(K == 0 || sum <= 0) break;
      ll a = vec_mod[i];
      sum -= a;
      K--;
      if(K == 0 || sum <= 0) break;
    }
  }
  if(sum < 0) sum = 0;
  cout << sum << endl;
  return 0;
}