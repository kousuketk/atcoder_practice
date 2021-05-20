#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int t;
  ll N;
  cin >> t >> N;

  ll A = 2;
  ll before_price = ((100+t)/100);
  ll price = 0;
  ll count = 0;
  while(count <= N) {
    price = ((100+t)*A/100);
    if(price - before_price > 1) {
      A += before_price-2;
      count++;
      if(count == N) {
        cout << (before_price+1) << endl;
        return 0;
      }
    }
    before_price = price;
    A++;
  }
}

