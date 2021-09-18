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
  int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
  vector<ll> p(a);
  vector<ll> q(b);
  vector<ll> r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(ALL(p), greater());
  sort(ALL(q), greater());
  sort(ALL(r), greater());
  vector<ll> vec(x+y);
  rep(i,x) vec.push_back(p[i]);
  rep(i,y) vec.push_back(q[i]);
  sort(ALL(vec), greater());
  // sum_r, sum_vec:i番目までの総和
  vector<ll> sum_r(c+1);
  rep(i,c) sum_r[i+1] = sum_r[i] + r[i];
  vector<ll> sum_vec(x+y+1);
  rep(i,x+y) sum_vec[i+1] = sum_vec[i] + vec[i];
  ll ans = 0;
  rep(i,c+1) { // rがi個選ばれる時
    if(x+y-i < 0) break;
    ll tmp = sum_r[i] + sum_vec[x+y-i];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}