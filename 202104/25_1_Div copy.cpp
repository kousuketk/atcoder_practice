#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, count;
  cin >> N;
  if(N == 1) {
    count = 0;
    cout << count << endl;
    return 0;
  }
  for(int a = 1; a < N; a++) {
    int b = N - a;
    count += 1;
  }
  cout << count << endl;
}