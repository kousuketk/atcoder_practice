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
  int Q; cin >> Q;
  multiset<ll> s;
  rep(i,Q) {
    int a; cin >> a;
    ll x; cin >> x;
    if(a == 1) {
      s.insert(x);
    } else {
      int K; cin >> K;
      if(s.empty()) {
        cout << -1 << endl;
        continue;
      }
      bool flag = false;
      if(a == 2) {
        auto itr = s.upper_bound(x);  // upper_boundは、xより大きいはじめてのitr→itr--すれば、x以下になる
        if(itr == s.begin()) {
          cout << -1 << endl;
          continue;
        }
        rep(k,K) {
          itr--;
          if(k != K-1 && itr == s.begin()) {
            flag = true;
            break;
          }
        }
        if(flag) {
          cout << -1 << endl;
          continue;
        }
        cout << *itr << endl;
      } else if(a == 3) {
        // x以上の要素のうち、小さい方からk番目の値
        auto itr = s.lower_bound(x);  // lower_boundは、x以上の最初のitr→K-1回だけitr++していけばよい
        if(itr == s.end()) {
          cout << -1 << endl;
          continue;
        }
        rep(k,K-1) {
          itr++;
          if(itr == s.end()) {
            flag = true;
            break;
          }
        }
        if(flag) {
          cout << -1 << endl;
          continue;
        }
        cout << *itr << endl;
      }
    }
  }
}