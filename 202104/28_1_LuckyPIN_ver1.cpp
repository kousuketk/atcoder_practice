#include <bits/stdc++.h>
#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
using namespace std;

int main() {
  int N;
  string S, tmp_S;
  cin >> N >> S;
  vector<string> vec;

  for(int i = 0; i < S.size()-2; i++) {
    for(int j = i+1; j < S.size()-1; j++) {
      for(int k = j+1; k < S.size(); k++) {
        ostringstream oss;
        oss << S.at(i) << S.at(j) << S.at(k);
        string tmp_S = oss.str();
        vec.push_back(tmp_S);
      }
    }
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  cout << vec.size() << endl;
}