#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(2));
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i).at(0) >> vec.at(i).at(1);
  }
}