#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < K; i++) {
    if(N%200 == 0) {
      N = N / 200;
    } else {
      string tmp = to_string(N);
      tmp.append("200");
      N = stoi(tmp);
    }
  }
  cout << N << endl;
}