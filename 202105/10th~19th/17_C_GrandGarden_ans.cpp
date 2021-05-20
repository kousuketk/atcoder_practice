#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

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
  vector<int> vec(N);
  rep(i,N) cin >> vec.at(i);
  int count = 0;
  for(int i = 1; i <= 100; i++) {
    int divide_counter = 0;
    int zero_counter = 0;
    for(int j = 0; j < N; j++) {
      if(vec.at(j) == 0) {
        zero_counter++;
        if(zero_counter == N) {
          cout << count << endl;
          return 0;
        }
        if((divide_counter > 0) && (j != (N-1))) {
          count++;
          divide_counter = 0;
        }
      } else {
        divide_counter++;
        vec.at(j)--;
      }
    }
    if(divide_counter > 0) count++;
  }
  cout << count << endl;
  return 0;
}