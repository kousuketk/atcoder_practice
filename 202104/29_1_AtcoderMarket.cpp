#include <bits/stdc++.h>
#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long long sum = 0;
  for(int i = 0; i < N; i++) {
    sum += abs(A.at(i) - B.at(i));
    sum += abs(A.at(i) - A.at(N >> 1));
    sum += abs(B.at(i) - B.at(N >> 1));
  }
  cout << sum << endl;
}