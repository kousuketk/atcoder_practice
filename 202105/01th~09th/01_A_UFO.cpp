#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  for(int i = 0; i < S.size() - 3; i++) {
    if(S.at(i) == 'Z' && S.at(i+1) == 'O' && S.at(i+2) == 'N' && S.at(i+3) == 'e') {
      count++;
    }
  }
  cout << count << endl;
}