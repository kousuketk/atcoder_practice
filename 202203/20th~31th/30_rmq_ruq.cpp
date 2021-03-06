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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

struct RMQ {
  int N;
  vector<int> dat, lazy;
  RMQ(int n) {
    int tmp = 1;
    while(n > tmp) tmp *= 2;
    N = tmp;
    dat.assign(2*N-1, INF);
    lazy.assign(2*N-1, INF);
  }
  
  void eval(int k) {
    if(lazy[k] == INF) return;
    if(k < N-1) {
      lazy[2*k+1] = lazy[k];
      lazy[2*k+2] = lazy[k];
    }
    dat[k] = lazy[k];
    lazy[k] = INF;
  }

  void update(int a, int b, int x) { update(a, b, x, 0, 0, N); }  // 区間[a, b)をxで更新する
  void update(int a, int b, int x, int k, int l, int r) {
    eval(k);
    if(a <= l && r <= b) {
      lazy[k] = x;
      eval(k);
    } else if(a < r && l < b) {
      update(a, b, x, 2*k+1, l, (l+r)/2);
      update(a, b, x, 2*k+2, (l+r)/2, r);
      dat[k] = min(dat[2*k+1], dat[2*k+2]);
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, N); }
  int query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if(r <= a || b <= l) {
      return INF;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {
      int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      int vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      return min(vl, vr);
    }
  }
};

int main() {
  int N, Q; cin >> N >> Q;
  RMQ rmq(N);
  rep(i,Q) {
    int q; cin >> q;
    if(q == 0) {
      int s, t, x; cin >> s >> t >> x;
      rmq.update(s, t+1, x);
    } else {
      int s, t; cin >> s >> t;
      int val = rmq.query(s, t+1);
      cout << val << endl;
    }
  }
  return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja