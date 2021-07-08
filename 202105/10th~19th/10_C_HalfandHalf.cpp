#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int pay = 0;
  if( A+B >= 2*C ) {
    int min_amount = min(X, Y);
    pay = min_amount*2*C;
    if(X<Y){
      int surplus = Y - min_amount;
      if(B >= C*2) pay += surplus*C*2;
      else pay += surplus*B;
    } else if(X>Y) {
      int surplus = X - min_amount;
      if(A >= C*2) pay += surplus*C*2;
      else pay += surplus*A;
    }
  } else {
    pay = (A*X + B*Y);
  }
  cout << pay << endl;
}