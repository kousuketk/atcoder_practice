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

// 0-idxから始まる座圧を求めるO(NlogN)
int main() {
  int N; cin >> N;
  vector<int> vec(N);
  vector<int> vals(N);
  vector<int> ans(N);
  rep(i,N) {
    int a; cin >> a;
    vec[i] = a;
    vals[i] = a;
  }
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  rep(i,N) {
    int a = vec[i];
    int idx = lower_bound(ALL(vals), a) - vals.begin();
    ans[i] = idx;
  }
  rep(i,N) cout << ans[i] << endl;
  return 0;
}