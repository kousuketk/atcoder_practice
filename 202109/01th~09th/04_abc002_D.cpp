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
  int N, M; cin >> N >> M;
  if(M == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<P> vec(M);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--, y--;
    vec[i] = P(x,y);
  }
  sort(ALL(vec));
  int ans = 0;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<12> bit(tmp);
    int cnt = __builtin_popcount(tmp);

    bool flag = true;
    for(int i = 0; i < N; i++) {
      if(!bit.test(i)) continue;
      for(int j = i+1; j < N; j++) {
        if(!bit.test(j)) continue;
        int idx = lower_bound(ALL(vec), P(i,j)) - vec.begin();
        P tmp = vec[idx];
        if(tmp != P(i,j)) flag = false;
      }
    }
    if(flag) ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}