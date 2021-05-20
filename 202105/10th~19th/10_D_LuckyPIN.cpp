#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i=0; i<1000; i++) {
    string t = "";
    int x = i;
    rep(j, 3) {
      t = char(x%10 + '0') + t;
      x /= 10;
    }
    int index = 0;
    for(int j=0; j<n; j++) {
      if(s[j] == t[index]) index++;
      if(index == 3) break;
    }
    if(index == 3) ans++;
  }
  cout << ans << endl;
}