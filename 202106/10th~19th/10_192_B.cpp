#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  string s;
  cin >> s;
  bool ans = true;
  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0 && isupper(s[i])) ans = false;
    else if(i % 2 == 1 && !isupper(s[i])) ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}