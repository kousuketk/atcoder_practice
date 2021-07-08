#include <bits/stdc++.h>
using namespace std;

void printVec(std::vector<long long> &vec) {
  std::cout << "";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  for(long long i = 0; i < N; i++) {
    long long a;
    cin >> a;
    A.at(i) = a % 200;
  }

  vector<long long> B;
  vector<long long> C;
  for(long long i = 0; i < N; i++) {
    auto itr = find(B.begin(), B.end(), A.at(i));
    size_t index = distance( B.begin(), itr );
    if(index != B.size()) {
      C.at(index) += 1;
    } else {
      B.push_back(A.at(i));
      C.push_back(1);
    }
  }

  printVec(B);
  printVec(C);
  long long count = 0;
  for(long long i = 0; i < C.size(); i++) {
    long long a = C.at(i);
    count += (a*(a-1))/2;
  }
  cout << count << endl;
}