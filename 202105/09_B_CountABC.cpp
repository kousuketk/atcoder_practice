#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int count = 0;
  for(int i = 0; i < N-2; i++) {
    if(S.at(i) == 'A' && S.at(i+1) == 'B' && S.at(i+2) == 'C') {
      count += 1;
    }
  }
  cout << count << endl;
}