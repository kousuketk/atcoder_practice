#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<P>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

// bit全探索で、bitが立ってる人は正直な人で探索していく
int main() {
  int N; cin >> N;
  Graph G(N);
  rep(i,N) {
    int a; cin >> a;
    rep(j,a) {
      int x, y; cin >> x >> y;
      x--;
      G[i].push_back(P(x, y));
    }
  }
  int ans = 0;
  for(int i = 0; i < (1<<N); i++) {
    bitset<15> bits(i);
    bool flag = true;
    rep(i,N) {
      if(!bits.test(i)) continue;
      for(P pa : G[i]) {
        int x = pa.first;
        int y = pa.second;
        if(y == 1 && !bits.test(x)) flag = false;
        if(y == 0 && bits.test(x)) flag = false;
        if(!flag) break;
      }
      if(!flag) break;
    }
    if(flag) ans = max(ans, (int)bits.count());
  }
  cout << ans << endl;
  return 0;
}