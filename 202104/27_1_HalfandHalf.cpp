#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y, same_count, money;
  cin >> A >> B >> C >> X >> Y;

  same_count = min(X, Y);
  if(A + B >= 2*C) {
    money += 2*C*same_count;
  } else {
    money += (A + B)*same_count;
  }

  // 残ったものに対しても、2Cで買うか、単品で買うか判断しなくてはいけない
  if(X >= Y) {
    if(A <= 2*C) {
      money += (X - Y)*A;
    } else {
      money += (X - Y)*2*C;
    }
  } else {
    if(B <= 2*C) {
      money += (Y - X)*B;
    } else {
      money += (Y - X)*2*C;
    }
  }
  cout << money << endl;
}