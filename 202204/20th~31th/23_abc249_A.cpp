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

int main() {
  int a, b, c, d, e, f, x; cin >> a >> b >> c >> d >> e >> f >> x;
  int tmp = x;
  int taka = 0;
  while(tmp > 0) {
    if(tmp >= a) {
      taka += b*a;
      tmp -= a;
    } else {
      taka += b*tmp;
      tmp = 0;
    }
    tmp -= c;
  }
  tmp = x;
  int aoki = 0;
  while(tmp > 0) {
    if(tmp >= d) {
      aoki += e*d;
      tmp -= d;
    } else {
      aoki += e*tmp;
      tmp = 0;
    }
    tmp -= f;
  }
  if(taka == aoki) cout << "Draw" << endl;
  else if(taka > aoki) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}