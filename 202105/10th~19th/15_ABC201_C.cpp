#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  string S;
  cin >> S;
  int count = 0;
  string tmp_s;
  for(int i = 0; i < 10000; i++) {
    string cp_s = S;
    tmp_s = to_string(i);
    while(tmp_s.size() < 4) {
      tmp_s = '0' + tmp_s;
    }
    bool flag = true;
    for(int j = 0; j < 4; j++) {
      int index = tmp_s.at(j) - '0';
      if((S.at(index) == 'o' || S.at(index) == '?')) cp_s.at(index) = '?';
      else flag = false;
    }
    if(flag) {
      for(int index_s = 0; index_s < cp_s.size(); index_s++) {
        if(cp_s.at(index_s) == 'o') break;
        if(index_s == cp_s.size() -1) count++;
      }
    }
  }
  cout << count << endl;
}