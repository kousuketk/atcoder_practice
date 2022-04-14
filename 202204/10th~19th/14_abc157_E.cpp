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
struct RMQ {
  int N;
  vector<int> dat;
  RMQ(int n) {
    int tmp = 1;
    while(n > tmp) tmp *= 2;
    N = tmp;
    dat.assign(2*N-1, 0);
  }
  void set(int i, int x) { dat[i+N-1] = x; }
  void build() {
    for(int k = N-2; k >= 0; k--) dat[k] = dat[2*k+1] | dat[2*k+2];
  }
  void update(int i, int x) {
    i += N-1;
    dat[i] = x;
    while(i > 0) {
      i = (i-1)/2;
      dat[i] = dat[2*i+1] | dat[2*i+2];
    }
  }
  int query(int a, int b) { return query_sub(a, b, 0, 0, N); }
  int query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return 0;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {
      int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      int vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      return vl | vr;
    }
  }
};

// セグ木作ってorを取っていく
int main() {
  int N; cin >> N;
  RMQ seg(N);
  string s; cin >> s;
  rep(i,N) {
    int val = 1 << (s[i] - 'a');
    seg.set(i, val);
  }
  seg.build();
  vector<int> ans;
  int Q; cin >> Q;
  rep(i,Q) {
    int t, x; cin >> t >> x;
    if(t == 1) {
      char y; cin >> y;
      x--;
      s[x] = y;
      int val = 1 << (s[x] - 'a');
      seg.update(x, val);
    } else {
      int y; cin >> y;
      x--, y--;
      int val = seg.query(x, y+1);
      ans.push_back(__builtin_popcount(val));
    }
  }
  for(int a : ans) cout << a << endl;
  return 0;
}