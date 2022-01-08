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
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  double ans = 0;
  rep(i,N) {
    rep(j,N) {
      if(i == j) continue;
      // i, j番目の距離を求める
      int x1 = vec[i].first;
      int y1 = vec[i].second;
      int x2 = vec[j].first;
      int y2 = vec[j].second;
      double tmp = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
      ans = max(tmp, ans);
    }
  }
  cout << fixed << setprecision(8) << ans << endl;
}