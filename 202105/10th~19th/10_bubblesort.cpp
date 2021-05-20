#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> &vec) {
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for(int i = 0; i < A.size(); i++) {
    for(int j = A.size()-2; j >= i; j--) {
      if (A.at(j) > A.at(j + 1)) swap(A.at(j), A.at(j + 1));
    }
  }
  printVec(A);
}