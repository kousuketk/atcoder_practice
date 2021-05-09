#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int N;
  cin >> N;

  int count = 0;
  while(N) {
    string s = to_string(N);
    if(s.size()%2 == 1) count++;
    N--;
  }
  cout << count << endl;
}