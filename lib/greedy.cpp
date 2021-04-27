#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> pays;
  while (1) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) {
      break;
    } else {
      pays.push_back(tmp);
    }
  }
  vector<int> coins = {500, 100, 50, 10, 5, 1};
  for (auto pay : pays) {
    int back = 1000 - pay; // お釣り
    int ans = 0;
    for (auto coin : coins) {
      int use = back / coin; // coin円 を使用する枚数
      back -= coin * use;
      ans += use;
    }
    cout << ans << endl;
  }
  return 0;
}