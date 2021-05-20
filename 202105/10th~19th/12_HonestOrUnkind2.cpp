#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<vector<int>>> vec(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    for(int j = 0; j < a; j++) {
      int x, y;
      cin >> x >> y;
      vec.at(i).push_back({x, y});
    }
  }
  int count = 0;
  bool flag;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<15> s(tmp);
    flag = true;
    for(int i = 0; i < N; i++) {
      if(s.test(i)) {
        for(long unsigned int j = 0; j < vec.at(i).size(); j++) {
          int x = vec.at(i).at(j).at(0);
          int y = vec.at(i).at(j).at(1);
          if( !((y==1 && s.test(x)) || (y==0 && !s.test(x))) ) flag = false;
        }
      }
    }
    if(flag) count = s.count();
  }
  cout << count << endl;
}