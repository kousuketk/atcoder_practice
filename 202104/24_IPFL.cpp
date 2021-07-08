#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<vector<int>> vec(Q, vector<int>(3));
  for(int i = 0; i < Q; i++) {
    cin >> vec.at(i).at(0) >> vec.at(i).at(1) >> vec.at(i).at(2);
  }
  
  for(int i = 0; i < Q; i++) {
    if(vec.at(i).at(0) == 1) {
      int a = vec.at(i).at(1);
      int b = vec.at(i).at(2);
      string T;
      for(int s = 0; s < S.size(); s++) {
        if(s == a-1) {
          T.push_back(S.at(b-1)); 
        } else if(s == b-1) {
          T.push_back(S.at(a-1));
        } else {
          T.push_back(S.at(s));
        }
      }
      S = T;
    } else {
      string after_s, before_s;
      for(int j = 0; j < N; j++) {
        after_s.push_back(S.at(j));
      }
      for(int j = N; j < 2*N; j++) {
        before_s.push_back(S.at(j));
      }
      S = before_s + after_s;
    }
  }
  cout << S << endl;
}