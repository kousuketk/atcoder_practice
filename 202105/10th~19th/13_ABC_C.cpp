#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  int count = 0;
  cin >> N;
  int tmp = N;
  int digit = 0;
  while(tmp!=0){
    tmp /= 10;
    digit++;
    if(digit == 3) {
      count += 9;
    } else if(digit > 3 && digit % 2 == 1) {
      count += 9*pow(10, ((digit-3)/2));
    }
  }
  int tmp_i = pow(10, digit-1);
  if(digit % 2 == 0) {
    for(int i = tmp_i; i <= N; i++) {
      string str = to_string(i);
      string tmp1 = str.substr(digit/2);
      string tmp2 = str.substr(0, digit/2);
      if(tmp1 == tmp2) {
        count++;
      }
    }
  }
  cout << count << endl;
}
// TLEした(後半のfor文がよくなかった)、10^6の全探索で良い