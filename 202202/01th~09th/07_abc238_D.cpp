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
  int T; cin >> T;
  rep(i,T) {
    ll a, s; cin >> a >> s;
    ll tmp = s - 2*a;
    // and(a), xor(tmp)がわかったので、各桁見ていって、(1,1)ならアウト
    bool flag = true;
    bitset<60> bit_a(a);
    bitset<60> bit_tmp(tmp);
    if(tmp < 0 || tmp > s) flag = false;
    rep(j,60) {
      if(bit_a.test(j) && bit_tmp.test(j)) flag = false;
      if(!flag) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}