#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (N/i != i) res.push_back(N/i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main() {
  int N;
  cin >> N;
  if(N % 2 == 0) N--;

  int count = 0;
  while(N > 104) {
    const auto &res = enum_divisors(N);
    if(res.size() == 8) count++;
    N -= 2;
  }
  cout << count << endl;
}