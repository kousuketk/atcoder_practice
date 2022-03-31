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
    for(int k = N-2; k >= 0; k--) dat[k] = max(dat[2*k+1], dat[2*k+2]);
  }

  void update(int i, int x) {
    i += N-1;
    dat[i] = x;
    while(i > 0) {
      i = (i - 1) / 2;
      dat[i] = max(dat[2*i+1], dat[2*i+2]);
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, N); } // 区間[a, b)の最大値を取得
  int query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return -1;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else { // 一部マッチするときは、子に分割していく
      int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      int vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      return max(vl, vr);
    }
  }

  int find_rightest(int a, int b, int x) { return find_rightest_sub(a, b, x, 0, 0, N); }  // 区間[a, b)でx以下の要素を持つ最右位置
  int find_leftest(int a, int b, int x) { return find_leftest_sub(a, b, x, 0, 0, N); }
  int find_rightest_sub(int a, int b, int x, int k, int l, int r) {
    if(dat[k] < x || r <= a || b <= l) {
      return -1;
    } else if(k >= N-1) {
      return (k - (N-1));
    } else {
      int vr = find_rightest_sub(a, b, x, 2*k+2, (l+r)/2, r);
      if(vr != -1) return vr;
      else return find_rightest_sub(a, b, x, 2*k+1, l, (l+r)/2);  // 右になかったら左を見ていく
    }
  }
  int find_leftest_sub(int a, int b, int x, int k, int l, int r) {
    if(dat[k] < x || r <= a || b <= l) {
      return -1;
    } else if(k >= N-1) {
      return (k - (N-1));
    } else {
      int vl = find_leftest_sub(a, b, x, 2*k+1, l, (l+r)/2);
      if(vl != -1) return vl;
      else return find_leftest_sub(a, b, x, 2*k+2, (l+r)/2, r);
    }
  }
};

int main() {
  int N, Q; cin >> N >> Q;
  RMQ rmq(N);
  rep(i,N) {
    int a; cin >> a;
    rmq.set(i, a);
  }
  rmq.build();
  rep(i,Q) {
    int t; cin >> t;
    if(t == 1) {
      int x, v; cin >> x >> v;
      x--;
      rmq.update(x, v);
    } else if(t == 2) {
      int l, r; cin >> l >> r;
      l--, r--;
      int val = rmq.query(l, r+1);
      cout << val << endl;
    } else {
      int x, v; cin >> x >> v;
      x--;
      int idx = rmq.find_leftest(x, N, v);
      if(idx == -1) cout << N+1 << endl;
      else cout << idx+1 << endl;
    }
  }
  return 0;
}

// https://atcoder.jp/contests/practice2/tasks/practice2_j