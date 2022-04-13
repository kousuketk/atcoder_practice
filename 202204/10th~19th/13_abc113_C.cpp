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

// 県ごとに座圧→計算量は(N+M)log(M)?
int main() {
  int N, M; cin >> N >> M;
  vector<P> vec(M);
  Graph G(N);
  rep(i,M) {
    int p, y; cin >> p >> y;
    p--;
    vec[i] = P(p, y);
    G[p].push_back(y);
  }
  rep(i,N) sort(ALL(G[i]));
  rep(i,M) {
    int p = vec[i].first;
    int y = vec[i].second;
    int idx = lower_bound(ALL(G[p]), y) - G[p].begin();
    // p+1, idx+1の値を出力
    cout << setfill('0') << right << setw(6) << p+1;
    cout << setfill('0') << right << setw(6) << idx+1;
    cout << endl;
  }
  return 0;
}