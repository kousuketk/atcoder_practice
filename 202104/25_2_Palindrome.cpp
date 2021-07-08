#include <bits/stdc++.h>
using namespace std;

int main() {
  string N, S;
  cin >> N;
  // とりま回分か判別する
  for(int i = 1; i <= N.size(); i++) {
    S.push_back(N.at(N.size() - i));
  }
  if(N == S) {
    cout << "Yes" << endl;
    return 0;
  }

  // Nを後ろから0であるか判定し、0であったら0を足して回分調査。(最大N回)
  int i = N.size()-1;
  while(N.at(i) == '0') {
    N = "0" + N;
    string S;
    for(int i = 1; i <= N.size(); i++) {
      S.push_back(N.at(N.size() - i));
    }
    if(N == S) {
      cout << "Yes" << endl;
      return 0;
    }
    i -= 1;
  }
  cout << "No" << endl;
}