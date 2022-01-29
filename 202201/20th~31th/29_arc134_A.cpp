#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
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
  ll L, W; cin >> L >> W;
  vector<P> vec(N);
  rep(i,N) {
    ll a; cin >> a;
    vec[i] = P(a, a+W);
  }
  ll ans = 0;
  ll before_end = 0;
  rep(i,N) {
    ll start = vec[i].first;
    ll diff = start - before_end;
    ll tmp = diff/W;
    if(diff > tmp*W) tmp++;
    ans += tmp;
    before_end = vec[i].second;
  }
  ll diff = L-before_end;
  ll tmp = diff/W;
  if(diff > tmp*W) tmp++;
  ans += tmp;
  cout << ans << endl;
}