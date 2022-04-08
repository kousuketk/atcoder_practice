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

// 女子だけ全探索して、男子に上げる幸福度を最大にしていく
int main() {
  int N, M, P, Q, R; cin >> N >> M >> P >> Q >> R;
  vector<T> vec(R);
  Graph G(N);
  rep(i,R) {
    int x, y, z; cin >> x >> y >> z;
    x--, y--;
    vec[i] = T(x, y, z);
    G[x].emplace_back(y, z);
  }
  int ans = 0;
  for(int i = 0; i < (1<<N); i++) {
    bitset<18> bits(i);
    if(bits.count() != P) continue;
    vector<int> men(M);
    rep(j,N) {
      if(!bits.test(j)) continue;
      for(auto pa : G[j]) {
        int y = pa.first;
        int z = pa.second;
        men[y] += z;
      }
    }
    sort(ALL(men), greater());
    int val = 0;
    rep(j,Q) val += men[j];
    ans = max(ans, val);
  }
  cout << ans << endl;
  return 0;
}