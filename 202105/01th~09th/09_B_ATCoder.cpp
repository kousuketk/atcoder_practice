#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int N;
  string S;
  cin >> S;

  int max = 0;
  int count = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
      count += 1;
      if(max < count) max = count;
    } else {
      count = 0;
    }
  }
  cout << max << endl;
}