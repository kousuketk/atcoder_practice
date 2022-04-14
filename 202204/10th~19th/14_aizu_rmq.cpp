#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = pow(2,31)-1;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;

struct RMQ {
  int N;
  vector<int> dat;
  RMQ(int n) {
    int tmp = 1;
    while(n > tmp) tmp *= 2;
    N = tmp;
    dat.assign(2*N-1, INF);
  }
  void set(int i, int x) { dat[i+N-1] = x;}
  void build() {
    for(int k = N-2; k >= 0; k--) dat[k] = min(dat[2*k+1], dat[2*k+2]);
  }
  void update(int i, int x) {
    i += N-1;
    dat[i] = x;
    while(i > 0) {
      i = (i-1)/2;
      dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }
  }
  int query(int a, int b) { return query_sub(a, b, 0, 0, N); }  // updateはそのままi番目を更新するけど、クエリのときは区間[a, b)だから+1する必要がある.
  int query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return INF;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {  // 一部にマッチするときは、子に分割していく
      int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      int vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      return min(vl, vr);
    }
  }
};

int main() {
  int N; cin >> N;
  RMQ rmq(N);
  int Q; cin >> Q;
  vector<int> ans;
  rep(i,Q) {
    int c, x, y; cin >> c >> x >> y;
    if(c == 0) rmq.update(x, y);
    else ans.push_back(rmq.query(x, y+1));
  }
  for(int val : ans) cout << val << endl;
  return 0;
}