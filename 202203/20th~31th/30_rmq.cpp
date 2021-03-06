#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = pow(2, 31)-1;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
struct RMQ {
  int N;  // 葉の数(2^xの形になるように表す)
  vector<int> dat;

  RMQ(int n) {
    int tmp = 1;
    while(n > tmp) tmp *= 2;
    N = tmp;
    dat.assign(4*N, INF);
  }

  void update(int i, int x) {
    i += N - 1;  // 葉iは、セグ木ではi += n-1番目になる
    dat[i] = x;
    while(i > 0) {
      i = (i - 1) / 2;
      dat[i] = min(dat[2*i+1], dat[2*i+2]);  // 親は子の最初値
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, N); }  // 区間[a, b)の最小値を取得
  int query_sub(int a, int b, int k, int l, int r) {  // 区間[a, b)の最小値を取得する際に、現在頂点kを見ている(区間は[l, r))
    if(r <= a || b <= l) {
      return INF;
    } else if(a <= l && r <= b) {  // 包括する形だったらそのまま返す
      return dat[k];
    } else {  // 一部マッチするときは、子に分割していく
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
    int c, x, y; cin >> c >> x >> y;
    if(c == 0) {
      rmq.update(x, y);
    } else {
      int val = rmq.query(x, y+1);
      cout << val << endl;
    }
  }
  return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp