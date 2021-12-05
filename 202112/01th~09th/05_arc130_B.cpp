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
  int H, W, C, Q; cin >> H >> W >> C >> Q;
  vector<T> vec(Q);
  vector<ll> ans(C);
  int cnt_h = 0;  // 今の操作後では、何行塗られるか
  int cnt_w = 0;  // 今の操作後では、何列塗られるか
  map<int, int> mp_h;
  map<int, int> mp_w;
  rep(i,Q) {
    int t, n, c; cin >> t >> n >> c;
    vec[i] = T(t, n, c);
    if(t == 1) {
      if(!mp_h.count(n)) cnt_h++;
      mp_h[n] = i+1;
    } else {
      if(!mp_w.count(n)) cnt_w++;
      mp_w[n] = i+1;
    }
  }
  rep(i,Q) {
    int t = get<0>(vec[i]);
    int n = get<1>(vec[i]);
    int c = get<2>(vec[i]);
    if(t == 1) {
      if(mp_h[n] == i+1) { // 今の色が塗られている
        ans[c-1] += (ll)(W - cnt_w);
        cnt_h--;
      }
    } else {
      if(mp_w[n] == i+1) {
        ans[c-1] += (ll)(H - cnt_h);
        cnt_w--;
      }
    }
  }
  rep(i,C) cout << ans[i] << " ";
  cout << endl;
}