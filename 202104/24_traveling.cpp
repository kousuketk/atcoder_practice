#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(3));
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i).at(0) >> vec.at(i).at(1) >> vec.at(i).at(2);
  }
  
  int t, x, y;
  for(int i = 0; i < N; i++) {
    t = vec.at(i).at(0);
    x = vec.at(i).at(1);
    y = vec.at(i).at(2);
    if(x > t || y > t) {
      cout << "NO" << endl;
      return 0;
    }
    if(((t%2 == 0) && ((x+y)%2 != 0)) || ((t%2 == 1) && ((x+y)%2 != 1))) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}