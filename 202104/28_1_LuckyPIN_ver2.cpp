#include <bits/stdc++.h>
#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<string> vec;
  int count = 0;
  for(int i = 0; i < 10; i++) {
    string tmp_S1 = S;
    if(tmp_S1.find(to_string(i)) == string::npos) {
      continue;
    }
    int pos1 = tmp_S1.find(to_string(i));
    tmp_S1 = tmp_S1.substr(pos1+1);
    for(int j = 0; j < 10; j++) {
      string tmp_S2 = tmp_S1;
      if(tmp_S2.find(to_string(j)) == string::npos) {
        continue;
      }
      int pos2 = tmp_S2.find(to_string(j));
      tmp_S2 = tmp_S2.substr(pos2+1);
      for(int k = 0; k < 10; k++) {
        if(tmp_S2.find(to_string(k)) == string::npos) {
          continue;
        }
        count += 1;
      }
    }
  }
  cout << count << endl;
}