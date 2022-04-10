#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;  // val, 個数
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
  int Q; cin >> Q;
  deque<P> deq;
  rep(i,Q) {
    int t; cin >> t;
    if(t == 1) {
      ll x, c; cin >> x >> c;
      deq.push_back(P(x, c));
    } else {
      ll c; cin >> c;
      ll ans = 0;
      P tmp = deq.front();
      deq.pop_front();
      ll popx = tmp.first;
      ll popc = tmp.second;
      while(c > popc) {
        c = c - popc;
        ans += popc*popx;
        tmp = deq.front();
        deq.pop_front();
        popx = tmp.first;
        popc = tmp.second;
      }
      // popc - c個はfrontに戻す
      ans += c*popx;
      ll rest = popc - c;
      deq.push_front(P(popx, rest));
      cout << ans << endl;
    }
  }
  return 0;
}