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
  int h, w, r, c; cin >> h >> w >> r >> c;
  int cnt = 4;
  if(h == 1 && w == 1) {
    cnt = 0;
  } else if(h == 1) {
    cnt -= 2;
    if(c == 1 || c == w) cnt--;
  } else if(w == 1) {
    cnt -= 2;
    if(r == 1 || r == h) cnt--;
  } else {
    if(r == 1 || r == h) cnt--;
    if(c == 1 || c == w) cnt--;
  }
  cout << cnt << endl;
  return 0;
}