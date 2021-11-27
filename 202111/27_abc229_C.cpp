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
  ll W; cin >> W;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  sort(ALL(vec), greater());
  ll ans = 0;
  ll now_w = 0;
  rep(i,N) {
    ll a = vec[i].first;
    ll b = vec[i].second;
    if((now_w + b) > W) {
      ans += a*(W - now_w);
      break;
    } else {
      now_w += b;
      ans += a*b;
    }
  }
  cout << ans << endl;
}