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
  int N; cin >> N;
  vector<int> vec_a(N);
  rep(i,N) cin >> vec_a[i];
  sort(ALL(vec_a));
  int Q; cin >> Q;
  rep(i,Q) {
    int b; cin >> b;
    auto itr = lower_bound(ALL(vec_a), b);
    int ans;
    if(itr == vec_a.begin()) {
      ans = abs(b - *itr);
    } else {
      ans = min(abs(b-*itr), abs(b-*(itr-1)));
    }
    cout << ans << endl;
  }
  return 0;
}