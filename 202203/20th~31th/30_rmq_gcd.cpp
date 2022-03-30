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
    dat.assign(4*N, INF);
  }

  void update(int i, int x) {
    i += N - 1;
    dat[i] = x;
    while(i > 0) {
      i = (i - 1) / 2;
      if(dat[2*i+1] == -1) dat[i] = dat[2*i+2];
      else if(dat[2*i+2] == -1) dat[i] = dat[2*i+1];
      else dat[i] = __gcd(dat[2*i+1], dat[2*i+2]);
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, N); }
  int query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return -1;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {
      int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
      int vr = query_sub(a, b, 2*k+2, (l+r)/2, r);
      if(vl == -1) return vr;
      else if(vr == -1) return vl;
      else return __gcd(vr, vl);
    }
  }
};

int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  RMQ rmq(N);
  rep(i,N) {
    int a = vec[i];
    rmq.update(i, a);
  }
  int ans = -1;
  rep(i,N) {  // i番目が無い時→(0, i], (i+1, N]
    int vl = rmq.query(0, i);
    int vr = rmq.query(i+1, N);
    if(vl == -1) ans = max(ans, vr);
    else if(vr == -1) ans = max(ans, vl);
    else ans = max(ans, __gcd(vl, vr));
  }
  cout << ans << endl;
  return 0;
}

// https://atcoder.jp/contests/abc125/tasks/abc125_c