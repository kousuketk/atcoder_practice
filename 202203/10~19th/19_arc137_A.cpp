#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll min_rec(ll L , ll R) {
  ll res = -1;
  if(__gcd(L, R) == 1) return res = max(res, R-L);
  res = max(res, min_rec(L+1, R));
  res = max(res, min_rec(L, R-1));
  return res;
}


int main() {
  ll L, R; cin >> L >> R;
  ll ans = min_rec(L, R);
  cout << ans << endl;
  return 0;
}