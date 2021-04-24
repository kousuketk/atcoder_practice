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
  int N, Y;
  cin >> N >> Y;
  vector<int> A(N);
  int sum = 0;
  for(int i = 0; i <= N; i++) {
    for(int j = 0; i+j <= N; j++) {
      int k = N - (i+j);
      sum = 10000*i + 5000*j + 1000*k;
      if(sum == Y) {
        cout << i << ' ' << j << ' ' << k << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}