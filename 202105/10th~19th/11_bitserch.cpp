#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);

  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<20> bit(tmp);

    int sum = 0;
    for(int i = 0; i < N; i++) {
      if(bit.test(i)) sum += A.at(i);
    }
    if(sum == K) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}