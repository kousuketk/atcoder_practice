#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int n, x;
  int last = 0, ans = 0;
  cin >> n;
  while (n--)
  {
    cin >> x;
    if (x > last)
      ans += (x-last);
    last = x;
	} 
  cout << ans << endl;
  return 0;
}