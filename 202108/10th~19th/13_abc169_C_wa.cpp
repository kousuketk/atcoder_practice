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
  ll a; cin >> a;
  double inpnum; cin >> inpnum;
  ll b = inpnum*100;
  ll tmp = a*b;
  ll ans = tmp/100;
  cout << ans << endl;
  return 0;
}

// inpnum*100+0.1とかする必要がある。inpnum*100するときに誤差を生むことがあるらしい
// 他のやり方としては、文字列に直してから計算するとか