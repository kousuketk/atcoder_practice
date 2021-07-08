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
  
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  cout << A.size() << endl;
  return 0;
}