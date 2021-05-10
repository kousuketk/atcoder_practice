#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int m = 5;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n)rep(j, m) cin >> a[i][j];
  int ac = 0, wa = 1001001001;
  while (ac+1 < wa)
  {
    int wj = (ac+wa)/2;
    vector<int> s;
    rep(i, n) {
      int x = 0;
      rep(j, m) {
        if(a[i][j] >= wj) x |= 1<<j;
      }
      s.push_back(x);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    bool ok = false;
    rep(i, s.size())rep(j,i+1)rep(k,j+1) {
      if((s[i]|s[j]|s[k]) == (1<<m)-1) ok = true;
    }
    if(ok) ac = wj; else wa = wj;
  }
  cout << ac << endl;
  return 0;
}
