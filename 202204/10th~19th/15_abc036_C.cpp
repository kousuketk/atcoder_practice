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

vector<int> compress(vector<int> &vec) {
  int siz = vec.size();
  vector<int> vals(siz);
  rep(i,siz) vals[i] = vec[i];
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  rep(i,siz) {
    int idx = lower_bound(ALL(vals), vec[i]) - vals.begin();
    vec[i] = idx;
  }
  return vals;
}

// 座圧(ソート, uniqueして、2分探索で見ていく)
int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<int> vals = compress(vec);
  rep(i,N) cout << vec[i] << endl;
  return 0;
}