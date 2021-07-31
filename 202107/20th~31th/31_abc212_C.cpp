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
  int N, M; cin >> N >> M;
  vector<int> vec_a(N);
  vector<int> vec_b(M);
  rep(i,N) cin >> vec_a[i];
  rep(i,M) cin >> vec_b[i];
  sort(ALL(vec_a));
  sort(ALL(vec_b));
  int ans = INF;
  rep(i,N) {
    int tmp = vec_a[i];
    auto itr = lower_bound(ALL(vec_b), tmp);
    if(itr == vec_b.begin()) {
      ans = min(ans, abs(tmp - *itr));
    } else {
      int idx = itr - vec_b.begin();
      ans = min(ans, abs(tmp - vec_b[idx]));
      ans = min(ans, abs(tmp - vec_b[idx-1]));
    }
  }
  cout << ans << endl;
}