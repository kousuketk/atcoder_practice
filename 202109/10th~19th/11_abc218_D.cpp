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
  vector<P> vec_x(N);
  vector<P> vec_y(N);
  vector<P> vec(N);
  rep(i,N) {
    int x, y; cin >> x >> y;
    vec[i].first = x; vec[i].second = y;
    vec_x[i].first = x; vec_x[i].second = y;
    vec_y[i].first = y; vec_y[i].second = x;
  }
  sort(ALL(vec_x));
  sort(ALL(vec_y));
  ll ans = 0;
  rep(i,N) {
    int y = vec_y[i].first;
    int x = vec_y[i].second;
    // 同じyを見つける(xに並行)
    auto itl = lower_bound(vec_y.begin()+i, vec_y.end(), P(y, x+1));
    auto itr = lower_bound(vec_y.begin()+i, vec_y.end(), P(y+1, 0));
    while(itl != itr) {
      P tmp = *itl;
      int y2 = tmp.first;
      int x2 = tmp.second;
      // xかつx2に平行なものを見つける(その２つもyが同じじゃないといけない)
      auto itr3_l = lower_bound(ALL(vec_x), P(x, y+1));
      auto itr3_r = lower_bound(ALL(vec_x), P(x+1, 0));
      auto itr4_l = lower_bound(ALL(vec_x), P(x2, y2+1));
      auto itr4_r = lower_bound(ALL(vec_x), P(x2+1, 0));
      while(itr3_l != itr3_r && itr4_l != itr4_r) {
        P tmp3 = *itr3_l;
        P tmp4 = *itr4_l;
        int y3 = tmp3.second;
        int y4 = tmp4.second;
        if(y3 == y4) {
          ans++;
          itr3_l++;
          itr4_l++;
        } else if(y3 < y4) {
          itr3_l++;
        } else {
          itr4_l++;
        }
      }
      itl++;
    }
  }
  cout << ans << endl;
}