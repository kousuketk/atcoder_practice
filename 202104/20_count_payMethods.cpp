#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> coins;
  coins = {500, 100, 50};
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int count = 0;
  for(int i = 0; i <= a; i++) {
    for(int j = 0; j <= b; j++) {
      for(int k = 0; k <= c; k++) {
        if((coins.at(0)*i + coins.at(1)*j + coins.at(2)*k) == x) {
          count += 1;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}