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
  int L, Q; cin >> L >> Q;
  vector<int> vec(2);
  vec[0] = 0;
  vec[1] = L;
  rep(i,Q) {
    int c, x; cin >> c >> x;
    auto itr = lower_bound(ALL(vec), x);
    if(c == 1) {
      vec.insert(itr, x);
    } else {
      int idx = itr - vec.begin();
      int ans = vec[idx] - vec[idx-1];
      cout << ans << endl;
    }
  }
  return 0;
}