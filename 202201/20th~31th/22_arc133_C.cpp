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
  ll H, W, K; cin >> H >> W >> K;
  vector<ll> A(H);
  vector<ll> B(W);
  rep(i,H) cin >> A[i];
  rep(i,W) cin >> B[i];
  ll mod_a = 0;
  ll mod_b = 0;
  rep(i,H) mod_a = (mod_a + A[i]) % K;
  rep(i,W) mod_b = (mod_b + B[i]) % K;
  if(mod_a != mod_b) {
    cout << -1 << endl;
    return 0;
  }
  // 行について(W回値を取れる)
  ll max_a = (K-1)*W;
  ll max_a_mod = max_a % K;
  ll ans_a = 0;
  rep(i,H) {
    ll a = A[i];
    ll tmp;
    if(a == max_a_mod) tmp = 0;
    else if(a < max_a_mod) tmp = max_a_mod - a;
    else tmp = max_a_mod + K-a;
    ans_a += (max_a-tmp);
  }
  // 列について(H回値を取れる)
  ll max_b = (K-1)*H;
  ll max_b_mod = max_b % K;
  ll ans_b = 0;
  rep(i,W) {
    ll b = B[i];
    ll tmp;
    if(b == max_b_mod) tmp = 0;
    else if(b < max_b_mod) tmp = max_b_mod - b;
    else tmp = max_b_mod + K-b;
    ans_b += (max_b-tmp);
  }
  ll ans = min(ans_a, ans_b);
  cout << ans << endl;
}