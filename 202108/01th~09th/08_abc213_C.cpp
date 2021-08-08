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

int main() {
  int H, W, N; cin >> H >> W >> N;
  vector<P> vec(N);
  vector<int> vec_h(N);
  vector<int> vec_w(N);
  rep(i,N) {
    int a, b; cin >> a >> b;
    vec[i].first = a;
    vec[i].second = b;
    vec_h[i] = a;
    vec_w[i] = b;
  }
  sort(ALL(vec_h));
  sort(ALL(vec_w));
  vec_h.erase(unique(ALL(vec_h)), vec_h.end());
  vec_w.erase(unique(ALL(vec_w)), vec_w.end());
  rep(i,N) {
    int a = vec[i].first;
    int b = vec[i].second;
    auto itr_a = lower_bound(ALL(vec_h), a);
    auto itr_b = lower_bound(ALL(vec_w), b);
    int idx_a = itr_a - vec_h.begin();
    int idx_b = itr_b - vec_w.begin();
    cout << (idx_a+1) << " " << (idx_b+1) << endl;
  }
  return 0;
}