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
  sort(vec.begin(), vec.end());
  int max = vec.at(N-1);
  int other_sum = 0;
  rep(i,N-1) other_sum += vec.at(i);
  if(max < other_sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}