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
void printVec(vector<ll> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  // 累積和を取って前から見ていくO(NlogN)
  int N, M;
  ll K;
  cin >> N >> M >> K;
  vector<ll> vec_a(N);
  vector<ll> vec_b(M);
  rep(i,N) cin >> vec_a[i];
  rep(i,M) cin >> vec_b[i];
  vector<ll> sum_a(N+1);
  vector<ll> sum_b(M+1);
  rep(i,N) sum_a[i+1] = sum_a[i] + vec_a[i];
  rep(i,M) sum_b[i+1] = sum_b[i] + vec_b[i];
  int ans = 0;
  rep(i,N+1) {
    ll val = sum_a[i]; // i番目までの値(かかる時間)
    if(val > K) break;
    ll search = K - val;
    auto itr = upper_bound(ALL(sum_b), search);
    int count = i + (itr - sum_b.begin())-1;
    ans = max(ans, count);
  }
  cout << ans << endl;
}

// 最初、ないとは思いながらも貪欲法で解いていて案の定違った...→考え直してac