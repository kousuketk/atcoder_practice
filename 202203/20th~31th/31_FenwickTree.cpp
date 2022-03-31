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
  vector<ll> dat;

  RMQ(int n) {
    int tmp = 1;
    while(n > tmp) tmp *= 2;
    N = tmp;
    dat.assign(2*N-1, 0);
  }

  void set(int i, ll x) { dat[i+N-1] = x; }
  void build() {
    for(int k = N-2; k >= 0; k--) dat[k] = dat[2*k+1]+dat[2*k+2];
  }

  void update(int i, ll x) {
    i += N - 1;
    dat[i] += x;
    while(i > 0) {
      i = (i - 1) / 2;
      dat[i] = dat[2*i+1] + dat[2*i+2];  // 親は子の和
    }
  }

  ll query(int a, int b) { return query_sub(a, b, 0, 0, N); }
  ll query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return 0;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {
      ll vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      ll vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      return (vl + vr);
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
    if(t == 0) {
      int p, x; cin >> p >> x;
      rmq.update(p, x);
    } else {
      int l, r; cin >> l >> r;
      ll val = rmq.query(l, r);
      cout << val << endl;
    }
  }
  return 0;
}

// https://atcoder.jp/contests/practice2/tasks/practice2_b