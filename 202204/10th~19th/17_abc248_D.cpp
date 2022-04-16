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

// map<int, vector<int>> でxがあるidxを格納していく
int main() {
  int N; cin >> N;
  vector<vector<int>> vec(N);
  rep(i,N) {
    int a; cin >> a;
    a--;
    vec[a].push_back(i);
  }
  int Q; cin >> Q;
  rep(i,Q) {
    int l, r, x; cin >> l >> r >> x;
    l--, r--, x--;
    // vector<int> tmp = vec[x];
    auto itrl = lower_bound(ALL(vec[x]), l);
    auto itrr = upper_bound(ALL(vec[x]), r);
    int cnt = itrr - itrl;
    cout << cnt << endl;
  }
  return 0;
}