#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  vector<int> height(N);
  vector<string> name(N);
  rep(i,N) {
    cin >> name.at(i) >> height.at(i);
  }
  int max_index = 0;
  rep(i,N) {
    if(height.at(max_index) < height.at(i)) max_index = i;
  }
  int second_index;
  if(max_index != 0) second_index = 0;
  else second_index = 1;
  for(int i = 0; i < N; i++) {
    if(i == max_index) {
      continue;
    } else if(height.at(second_index) < height.at(i)) second_index = i;
  }
  cout << name.at(second_index) << endl;
}