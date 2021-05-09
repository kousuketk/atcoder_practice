#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

vector<long long> enum_divisors(long long N, long long M) {
  vector<long long> res;
  if(N < M) swap(N, M);
  for (long long i = 1; i <= M; ++i) {
    if (N % i == 0 && M % i == 0) {
      res.push_back(i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

void printVec(std::vector<long long> &vec) {
  std::cout << "";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  vector<long long> res1 = enum_divisors(A, B);
  printVec(res1);
  int r = res1.at(res1.size()-K);
  cout << r << endl;
}