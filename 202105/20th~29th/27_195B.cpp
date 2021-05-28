#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
  int a, b, w;
  cin >> a >> b >> w;
  w = w*1000;
  int i = 1;
  int ans_a = INF, ans_b = 0;
  while(i <= 1000000) {
    if(a*i <= w && b*i >= w) {
      ans_a = min(ans_a, i);
      ans_b = max(ans_b, i);
    }
    i++;
  }
  if(ans_a == INF) cout << "UNSATISFIABLE" << endl;
  else cout << ans_a << " " << ans_b << endl;
}